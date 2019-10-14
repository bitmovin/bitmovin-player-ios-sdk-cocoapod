import { EventEnumMapper } from './EventEnumMapper';
import { PlayerEventBase, ViewModeChangedEvent } from 'bitmovin-player-v8';
import PlayerEvent = bitmovin.PlayerAPI.PlayerEvent;
import { ViewMode } from './PlayerV8Enums';
import { PlayerEventV7 } from '../v7/PlayerEnums';

export class EventMapper {

  static mapEventToV8(event: PlayerEvent): PlayerEventBase {
    let mappedEvent = event;

    switch (event.type) {
      case PlayerEventV7.ON_FULLSCREEN_ENTER:
      case PlayerEventV7.ON_FULLSCREEN_EXIT:
        mappedEvent = this.mapFullscreenEvent(event);
    }

    mappedEvent.type = EventEnumMapper.mapToV8(event.type);
    return mappedEvent as PlayerEventBase;
  }

  private static mapFullscreenEvent(event: PlayerEvent): ViewModeChangedEvent {
    return {
      ...event,
      from: event.type === PlayerEventV7.ON_FULLSCREEN_ENTER ? ViewMode.Inline : ViewMode.Fullscreen,
      to: event.type === PlayerEventV7.ON_FULLSCREEN_ENTER ? ViewMode.Fullscreen : ViewMode.Inline,
      legacy: false,
    } as ViewModeChangedEvent;
  }
}
