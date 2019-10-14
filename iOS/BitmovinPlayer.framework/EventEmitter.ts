import PlayerEventCallback = bitmovin.PlayerAPI.PlayerEventCallback;
import { EventMapper } from './v8/EventMapper';
import PlayerEvent = bitmovin.PlayerAPI.PlayerEvent;
import EVENT = bitmovin.PlayerAPI.EVENT;
import { uiBridge } from './UIBridge';
import { PlayerEventV7 } from './v7/PlayerEnums';

export class EventEmitter {
  private eventHandlers: { [eventType: string]: PlayerEventCallback[]; } = {};

  on(eventType: string, callback: PlayerEventCallback): void {
    if (!this.eventHandlers.hasOwnProperty(eventType)) {
      this.eventHandlers[eventType] = [];
    }

    this.eventHandlers[eventType].push(callback);
  }

  off(eventType: string, callback: PlayerEventCallback): void {
    if (this.eventHandlers.hasOwnProperty(eventType)) {
      this.eventHandlers[eventType] = this.eventHandlers[eventType].filter((element) => {
        return element !== callback;
      });
    }
  }

  fireNativeEvent(eventType: EVENT, dataAsStringOrObject: string | PlayerEvent): void {
    if (this.eventHandlers.hasOwnProperty(eventType) && !this.shouldSuppressEvent(eventType)) {
      const toDataObj = (dataAsStringOrObject: string | PlayerEvent): PlayerEvent => {
        if (typeof dataAsStringOrObject === 'string') {
          return JSON.parse(decodeURIComponent(dataAsStringOrObject));
        }

        return dataAsStringOrObject;
      };

      const event = this.processEvent(eventType, toDataObj(dataAsStringOrObject));

      this.firePlayerEvent(eventType, event);
    }
  }

  firePlayerEvent(eventType: string, event: PlayerEvent) {
    if (this.eventHandlers.hasOwnProperty(eventType)) {
      this.eventHandlers[eventType].forEach((callback) => {
        callback(event);
      });
    }
  }

  private shouldSuppressEvent(eventType: EVENT): boolean {
    const eventsToSkipInV3: string[] = [
      PlayerEventV7.ON_SOURCE_LOADED,
    ];

    if (uiBridge.isV3Ui()) {
      return eventsToSkipInV3.includes(eventType);
    }

    return false;
  }

  private processEvent(eventType: EVENT, eventData: PlayerEvent): PlayerEvent {
    if (uiBridge.isV3Ui()) {
      // In v8 (v3 UI) the onSourceLoaded event is basically the onReady event -> Playback can be started.
      // To not send the onSourceLoaded too early for v8 we need to suppress the actual event.
      if (eventType === PlayerEventV7.ON_READY) {
        const onSourceLoadedEvent = this.prepareEventData({
          ...eventData,
          type: PlayerEventV7.ON_SOURCE_LOADED,
        });

        this.firePlayerEvent(PlayerEventV7.ON_SOURCE_LOADED, onSourceLoadedEvent);
      }
    }

    return this.prepareEventData(eventData);
  }

  private prepareEventData(data: PlayerEvent): {} {
    if (uiBridge.isV3Ui()) {
      data = EventMapper.mapEventToV8(data);
    }

    return data;
  }
}
