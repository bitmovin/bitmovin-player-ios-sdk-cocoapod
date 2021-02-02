//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvents.h>

@class BMPPlayer;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines listener methods for all events available for the BitmovinPlayer. See the documentation of the single listener
 * methods for further information.
 */
NS_SWIFT_NAME(PlayerListener)
@protocol BMPPlayerListener <NSObject>
@optional
/**
 * Is called when the player is ready for immediate playback, because initial audio/video has been downloaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onReady:(BMPReadyEvent *)event player:(BMPPlayer *)player;

/**
 * Notifies about the intention to start/resume playback.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlay:(BMPPlayEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when playback has been started.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlaying:(BMPPlayingEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player enters the pause state.
 * 
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPaused:(BMPPausedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the current playback time has changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onTimeChanged:(BMPTimeChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the duration of the current played media has changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onDurationChanged:(BMPDurationChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called periodically during seeking.
 *
 * Only applies to VoD streams.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSeek:(BMPSeekEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when seeking has been finished and data is available to continue playback.
 *
 * Only applies to VoD streams.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSeeked:(BMPSeekedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called periodically during time shifting. Only applies to live streams, please refer to onSeek for VoD streams.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onTimeShift:(BMPTimeShiftEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when time shifting has been finished and data is available to continue playback. Only applies to live streams, please refer to onSeeked for VoD streams.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onTimeShifted:(BMPTimeShiftedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player is paused or in buffering state and the timeShift offset has exceeded the available timeShift window.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onDvrWindowExceeded:(BMPDvrWindowExceededEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player begins to stall and to buffer due to an empty buffer.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onStallStarted:(BMPStallStartedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player ends stalling, due to enough data in the buffer.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onStallEnded:(BMPStallEndedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the current size of the video content has been changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onVideoSizeChanged:(BMPVideoSizeChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback of the current media has finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlaybackFinished:(BMPPlaybackFinishedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the first frame of the current video is rendered onto the video surface.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onRenderFirstFrame:(BMPRenderFirstFrameEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an error is encountered.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onError:(BMPErrorEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a warning occurs.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onWarning:(BMPWarningEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when loading of a new source started. This does not mean that loading of the new manifest has been finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSourceLoad:(BMPSourceLoadEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a new source is loaded. This does not mean that loading of the new manifest has been finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSourceLoaded:(BMPSourceLoadedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the current source will be unloaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSourceUnload:(BMPSourceUnloadEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the current source has been unloaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSourceUnloaded:(BMPSourceUnloadedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player was destroyed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onDestroy:(BMPDestroyEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when metadata (i.e. ID3 tags in HLS and EMSG in DASH) are encountered.
 * 
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onMetadata:(BMPMetadataEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when metadata is parsed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onMetadataParsed:(BMPMetadataParsedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when casting to another device, such as a ChromeCast, is available.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastAvailable:(BMPCastAvailableEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback on an cast device has been paused.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastPaused:(BMPCastPausedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback on an cast device has been finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastPlaybackFinished:(BMPCastPlaybackFinishedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when playback on an cast device has been started.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastPlaying:(BMPCastPlayingEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the cast app is launched successfully.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastStarted:(BMPCastStartedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when casting is initiated, but the user still needs to choose which device should be used.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastStart:(BMPCastStartEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when casting to a device is stopped.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastStopped:(BMPCastStoppedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the time update from the currently used cast device is received.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastTimeUpdated:(BMPCastTimeUpdatedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a cast device has been chosen and player is waiting for the device to get ready for playback.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCastWaitingForDevice:(BMPCastWaitingForDeviceEvent *)event player:(BMPPlayer *)player __TVOS_PROHIBITED;

/**
 * Is called when the player configuration has been updated by either calling load or setup on the player.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onConfigurationUpdated:(BMPConfigurationUpdatedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a sideloaded subtitle cue has been parsed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCueParsed:(BMPCueParsedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a subtitle entry transitions into the active status.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCueEnter:(BMPCueEnterEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an active subtitle entry transitions into the inactive status.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onCueExit:(BMPCueExitEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a new BMPSubtitleTrack is added, for example using the BMPPlayerAPI#addSubtitle: call.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSubtitleAdded:(BMPSubtitleAddedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an external BMPSubtitleTrack has been removed so it is possible to update the controls accordingly.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSubtitleRemoved:(BMPSubtitleRemovedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the active BMPSubtitleTrack is changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSubtitleChanged:(BMPSubtitleChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player is muted.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onMuted:(BMPMutedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player is unmuted.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onUnmuted:(BMPUnmutedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an audio track is added.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAudioAdded:(BMPAudioAddedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an audio track is removed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAudioRemoved:(BMPAudioRemovedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the audio track is changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAudioChanged:(BMPAudioChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback of an ad has been started.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdStarted:(BMPAdStartedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback of an ad has been finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdFinished:(BMPAdFinishedEvent *)event player:(BMPPlayer *)player;

/**
 * Is fired when the playback of an ad has progressed over a quartile boundary.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdQuartile:(BMPAdQuartileEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback of an ad break has been started.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdBreakStarted:(BMPAdBreakStartedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the playback of an ad break has been finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdBreakFinished:(BMPAdBreakFinishedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an ad manifest was successfully downloaded and parsed and the ad has been added onto the queue.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdScheduled:(BMPAdScheduledEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when an ad has been skipped.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdSkipped:(BMPAdSkippedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the user clicks on the ad.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdClicked:(BMPAdClickedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when ad playback fails.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdError:(BMPAdErrorEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the download of an ad manifest is starting.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdManifestLoad:(BMPAdManifestLoadEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the ad manifest has been successfully loaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAdManifestLoaded:(BMPAdManifestLoadedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the current video download quality has changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onVideoDownloadQualityChanged:(BMPVideoDownloadQualityChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a web download request has finished.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onDownloadFinished:(BMPDownloadFinishedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when AirPlay playback starts or stops.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAirPlayChanged:(BMPAirPlayChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when AirPlay is available.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onAirPlayAvailable:(BMPAirPlayAvailableEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when a source item is loaded which has metadata attached or when setSourceMetadata: is called on the player.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onSourceMetadataChanged:(BMPSourceMetadataChangedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when DRM data is found in a downloaded manifest file.
 * TweaksConfiguration.nativeHlsParsingEnabled needs to be set to true to receive those events.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onDrmDataParsed:(BMPDrmDataParsedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called for each occurring player event.
 *
 * @param event The player event. Use event.name or [event isKindOfClass:] to check the specific event type.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onEvent:(id <BMPEvent>)event player:(BMPPlayer *)player NS_SWIFT_NAME(onEvent(_:player:));

/**
 * Is called when a source was loaded into the Player.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlayerActive:(BMPPlayerActiveEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the Player was unloaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlayerInactive:(BMPPlayerInactiveEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the player transitions between two sources in a playlist.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onPlaylistTransition:(BMPPlaylistTransitionEvent *)event player:(BMPPlayer *)player;
@end

NS_ASSUME_NONNULL_END
