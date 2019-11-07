import PlayerEventCallback = bitmovin.PlayerAPI.PlayerEventCallback;
import { EventMapper } from './v8/EventMapper';
import PlayerEvent = bitmovin.PlayerAPI.PlayerEvent;
import EVENT = bitmovin.PlayerAPI.EVENT;
import { uiBridge } from './UIBridge';
import { PlayerEventV7 } from './v7/PlayerEnums';
import { EventEnumMapper } from './v8/EventEnumMapper';

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
    // As with UI v3 a few events were dropped we have to map it accordingly.
    // I.e. all event callbacks are stored by their v7 event type string. For events not longer available in v8
    // these events have to be mapped to their possible v7 equivalent. Example: 'onCastPlaying' does no longer exist.
    // Its corresponding v8 event is 'playing'. So onCastPlaying <=> playing <=> onPlaying
    const originalType = eventType;
    eventType = EventEnumMapper.mapEventTypeIfNeeded(eventType);

    if (eventType !== originalType) {
      eventType = EventEnumMapper.mapToV7(eventType);
    }

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
