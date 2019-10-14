import { CustomMessageHandler } from './CustomMessageHandler';
import { NativePlayerStateHandler } from './NativePlayerStateHandler';
import { UrlHelper } from './helper/UrlHelper';
import { CssLoader } from './helper/CssLoader';
import { JsLoader } from './helper/JsLoader';
import { NativeCommunicator } from './helper/NativeCommunicator';
import { NativePlayerAdapter } from './NativePlayerAdapter';
import { PlayerV8Adapter } from './v8/PlayerV8Adapter';
import { Logger } from './helper/Logger';
import { EventEmitter } from './EventEmitter';
import { WindowResizeListener } from './WindowResizeListener';
import { FullscreenSupportHandler } from './FullscreenSupportHandler';
import { BitmovinWindow } from './BitmovinWindow';

declare const window: BitmovinWindow;

class UIBridge {
  private readonly player: NativePlayerAdapter;
  private stateHandler: NativePlayerStateHandler;
  private uiManager: any;
  private eventEmiter: EventEmitter;

  constructor() {
    this.setupErrorHandler();
    this.setupAppState();
    this.setupEventEmitter();
    this.setupWindowResizeListener();
    this.player = new NativePlayerAdapter(this.stateHandler, this.eventEmiter);

    this.setupCustomMessageHandler();

    this.loadResources().then(() => {
      this.setupUiManager();
      NativeCommunicator.postEvent('uiReady');
    });

    this.setupFullScreenHandling();
  }

  private setupFullScreenHandling() {
    this.player.on('onFullscreenEnabled', () => {
      FullscreenSupportHandler.changeButtonVisibility(true);
    });

    this.player.on('onFullscreenDisabled', () => {
      FullscreenSupportHandler.changeButtonVisibility(false);
    });
  }

  private setupWindowResizeListener() {
    const windowResizeListener = new WindowResizeListener();
    windowResizeListener.onResize((event) => {
      this.eventEmiter.firePlayerEvent(event.type, event);
    });
  }

  private setupEventEmitter() {
    this.eventEmiter = new EventEmitter();

    window.fireEvent = (eventType: string, dataAsString: string) => {
      this.eventEmiter.fireNativeEvent(eventType, dataAsString);
    };
  }

  private setupErrorHandler() {
    window.addEventListener('error', (e) => {
      Logger.error(e.error ? e.error.message : e.message); // A JS error coming form the UI results in script-error.
      return false;
    });
  }

  private loadResources(): Promise<void[]> {
    const uiCss = UrlHelper.getUrlParameterByName('uicss');
    const supplementalUiCss = UrlHelper.getUrlParameterByName('supplementaluicss');
    const uiJS = UrlHelper.getUrlParameterByName('uijs');

    const promises = [];

    if (uiCss) {
      promises.push(CssLoader.load(uiCss, 'uicss'));
    }

    if (supplementalUiCss) {
      promises.push(CssLoader.load(supplementalUiCss, 'supplementaluicss'));
    }

    if (uiJS) {
      promises.push(JsLoader.load(uiJS));
    }

    return Promise.all(promises);
  }

  private setupUiManager(uiConfig: {} = {}) {
    if (this.isV3Ui()) {
      const v8Adapter = new PlayerV8Adapter(this.player, this.stateHandler);
      this.uiManager = window.bitmovin.playerui.UIFactory.buildDefaultSmallScreenUI(v8Adapter, uiConfig);
    } else {
      this.uiManager = window.bitmovin.playerui.UIManager.Factory.buildDefaultSmallScreenUI(this.player, uiConfig);
    }

    this.registerUiManagerEvents();
  }

  private registerUiManagerEvents() {
    // FIXME: This only subscribes to the events of the current UI. If the UI variant changes at runtime those events
    //        will not be captured. E.g. Ads UI
    this.uiManager.currentUi.events.onControlsShow.subscribe(() => {
      NativeCommunicator.postEvent('controlsShow');
    });

    this.uiManager.currentUi.events.onControlsShow.subscribe(() => {
      NativeCommunicator.postEvent('controlsHide');
    });
  }

  // Setup customMessageHandler for communication between JS and native code
  private setupCustomMessageHandler() {
    window.bitmovin = window.bitmovin || {};
    window.bitmovin.customMessageHandler = new CustomMessageHandler();
  }

  private setupAppState() {
    this.stateHandler = new NativePlayerStateHandler();

    window.app = this.stateHandler.state;
    window.resetStateWhenSourceUnloaded = () => {
      this.stateHandler.reset();
    };
  }

  public isV3Ui(): boolean {
    // FIXME: This could lead to wrong assumption e.g. if someone removes the UIFactory from a forked UI
    //        We should think about checking more than this (maybe if a special component exists)
    return window.bitmovin.playerui.UIFactory !== undefined;
  }
}

export const uiBridge = new UIBridge();
