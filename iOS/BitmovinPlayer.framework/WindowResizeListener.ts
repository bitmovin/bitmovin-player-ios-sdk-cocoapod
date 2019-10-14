import PlayerEventCallback = bitmovin.PlayerAPI.PlayerEventCallback;
import PlayerResizeEvent = bitmovin.PlayerAPI.PlayerResizeEvent;
import { PlayerEventV7 } from './v7/PlayerEnums';

export class WindowResizeListener {
  private eventHandler: PlayerEventCallback[] = [];
  private resizeTimer: any;

  constructor() {
    this.setupEventListener();
  }

  onResize(callback: PlayerEventCallback) {
    this.eventHandler.push(callback);
  }

  private setupEventListener() {
    window.addEventListener('resize', () => {
      clearTimeout(this.resizeTimer);
      this.resizeTimer = setTimeout(() => {
        const onPlayerResizeEvent: PlayerResizeEvent = {
          width: window.innerWidth + 'px',
          height: window.innerHeight + 'px',
          type: PlayerEventV7.ON_PLAYER_RESIZE,
        };

        this.eventHandler.forEach((callback) => {
          callback(onPlayerResizeEvent);
        });
      }, 100);
    });
  }
}
