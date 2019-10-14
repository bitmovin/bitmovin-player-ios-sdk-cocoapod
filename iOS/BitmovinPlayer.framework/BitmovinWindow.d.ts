import { CustomMessageHandler } from './CustomMessageHandler';
import { NativePlayerState } from './NativePlayerStateHandler';

export interface BitmovinWindow extends Window {
  webkit: Webkit;
  bitmovin: BitmovinNamespace;
  /**
   * Updated by the native code to keep the player state in sync
   */
  app: NativePlayerState;
  /**
   * Called by the native code to fire an event
   * @param eventType
   * @param dataAsString
   */
  fireEvent: (eventType: string, dataAsString: string) => void;
  /**
   * Called by the native code to reset the app state
   */
  resetStateWhenSourceUnloaded: () => void;
}

interface BitmovinNamespace {
  customMessageHandler?: CustomMessageHandler;
  playerui?: any;
}

interface MessageHandlersIos {
  postMessage: (message: { event: string }) => void;
}

interface MessageHandlers {
  ios: MessageHandlersIos;
}

interface Webkit {
  messageHandlers: MessageHandlers;
}
