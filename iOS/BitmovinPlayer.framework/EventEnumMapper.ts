import { PlayerEvent } from 'bitmovin-player-v8';

export class EventEnumMapper {
  private static mapping: { [key: string]: string } = {
    onReady: 'ready',
    onPlay: 'play',
    onPlaying: 'playing',
    onPaused: 'paused',
    onSeek: 'seek',
    onSeeked: 'seeked',
    onTimeShift: 'timeshift',
    onTimeShifted: 'timeshifted',
    onVolumeChanged: 'volumechanged',
    onMuted: 'muted',
    onUnmuted: 'unmuted',
    onPlayerResized: 'playerresized',
    onPlaybackFinished: 'playbackfinished',
    onError: 'error',
    onWarning: 'warning',
    onStallStarted: 'stallstarted',
    onStallEnded: 'stallended',
    onAudioChanged: 'audiochanged',
    onAudioAdded: 'audioadded',
    onAudioRemoved: 'audioremoved',
    onVideoQualityChanged: 'videoqualitychanged',
    onAudioQualityChanged: 'audioqualitychanged',
    onVideoDownloadQualityChange: 'videodownloadqualitychange',
    onAudioDownloadQualityChange: 'audiodownloadqualitychange',
    onVideoDownloadQualityChanged: 'videodownloadqualitychanged',
    onAudioDownloadQualityChanged: 'audiodownloadqualitychanged',
    onVideoPlaybackQualityChanged: 'videoplaybackqualitychanged',
    onAudioPlaybackQualityChanged: 'audioplaybackqualitychanged',
    onTimeChanged: 'timechanged',
    onCueParsed: 'cueparsed',
    onCueEnter: 'cueenter',
    onCueUpdate: 'cueupdate',
    onCueExit: 'cueexit',
    onSegmentPlayback: 'segmentplayback',
    onMetadata: 'metadata',
    onMetadataParsed: 'metadataparsed',
    onVideoAdaptation: 'videoadaptation',
    onAudioAdaptation: 'audioadaptation',
    onDownloadFinished: 'downloadfinished',
    onSegmentRequestFinished: 'segmentrequestfinished',
    onAdManifestLoaded: 'admanifestloaded',
    onAdStarted: 'adstarted',
    onOverlayAdStarted: 'overlayadstarted',
    onAdQuartile: 'adquartile',
    onAdSkipped: 'adskipped',
    onAdClicked: 'adclicked',
    onAdLinearityChanged: 'adlinearitychanged',
    onAdBreakStarted: 'adbreakstarted',
    onAdBreakFinished: 'adbreakfinished',
    onAdFinished: 'adfinished',
    onAdError: 'aderror',
    onVRViewingDirectionChange: 'vrviewingdirectionchange',
    onVRViewingDirectionChanged: 'vrviewingdirectionchanged',
    onVRStereoChanged: 'vrstereochanged',
    onCastAvailable: 'castavailable',
    onCastStopped: 'caststopped',
    onCastStart: 'caststart',
    onCastStarted: 'caststarted',
    onCastWaitingForDevice: 'castwaitingfordevice',
    onSourceLoaded: 'sourceloaded',
    onSourceUnloaded: 'sourceunloaded',
    onPeriodSwitch: 'periodswitch',
    onPeriodSwitched: 'periodswitched',
    onDVRWindowExceeded: 'dvrwindowexceeded',
    onSubtitleAdded: 'subtitleadded',
    onSubtitleRemoved: 'subtitleremoved',
    onShowAirplayTargetPicker: 'showairplaytargetpicker',
    onAirplayAvailable: 'airplayavailable',
    onAirplayChanged: 'airplaychanged',
    onDestroy: 'destroy',
    onPlaybackSpeedChanged: 'playbackspeedchanged',
    onViewModeChanged: 'viewmodechanged',
    onModuleReady: 'moduleready',
  };

  // This mapping is needed to map any event that got removed with UI v3 (Player API v8)
  private static legacyEventMapping: { [key: string]: string } = {
    onCastPlaying: 'playing',
    onCastPaused: 'paused',
    onCastTimeUpdated: 'timechanged',
    onFullscreenEnter: 'viewmodechanged',
    onFullscreenExit: 'viewmodechanged',
    onSubtitleChanged: 'subtitleenabled',
  };

  static mapToV7(event: PlayerEvent): string {
    return Object.keys(this.mapping).filter((key) => this.mapping[key] === event)[0];
  }

  static mapToV8(eventName: string): string {
    let eventMapping = this.mapping[eventName];
    return eventMapping ? eventMapping : this.mapEventTypeIfNeeded(eventName);
  }

  static mapEventTypeIfNeeded(eventType: string): string {
    return this.legacyEventMapping[eventType] || eventType;
  }
}
