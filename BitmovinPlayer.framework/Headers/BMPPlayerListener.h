//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvents.h>

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
 */
- (void)onReady:(BMPReadyEvent *)event;

/**
 * Is called when the player enters the play state.
 *
 * @param event An object holding specific event data.
 */
- (void)onPlay:(BMPPlayEvent *)event;

/**
 * Is called when the player enters the pause state.
 * 
 * @param event An object holding specific event data.
 */
- (void)onPaused:(BMPPausedEvent *)event;

/**
 * Is called when the current playback time has changed.
 *
 * @param event An object holding specific event data.
 */
- (void)onTimeChanged:(BMPTimeChangedEvent *)event;

/**
 * Is called when the duration of the current played media has changed.
 *
 * @param event An object holding specific event data.
 */
- (void)onDurationChanged:(BMPDurationChangedEvent *)event;

/**
 * Is called periodically during seeking.
 *
 * Only applies to VoD streams.
 *
 * @param event An object holding specific event data.
 */
- (void)onSeek:(BMPSeekEvent *)event;

/**
 * Is called when seeking has been finished and data is available to continue playback.
 *
 * Only applies to VoD streams.
 *
 * @param event An object holding specific event data.
 */
- (void)onSeeked:(BMPSeekedEvent *)event;

/**
 * Is called when the current size of the video content has been changed.
 *
 * @param event An object holding specific event data.
 */
- (void)onVideoSizeChanged:(BMPVideoSizeChangedEvent *)event;

/**
 * Is called when the playback of the current media has finished.
 *
 * @param event An object holding specific event data.
 */
- (void)onPlaybackFinished:(BMPPlaybackFinishedEvent *)event;

/**
 * Is called when the first frame of the current video is rendered onto the video surface.
 *
 * @param event An object holding specific event data.
 */
- (void)onRenderFirstFrame:(BMPRenderFirstFrameEvent *)event;

/**
 * Is called when an error is encountered.
 *
 * @param event An object holding specific event data.
 */
- (void)onError:(BMPErrorEvent *)event;

/**
 * Is called when a new source is loaded. This does not mean that loading of the new manifest has been finished.
 *
 * @param event An object holding specific event data.
 */
- (void)onSourceLoaded:(BMPSourceLoadedEvent *)event;

/**
 * Is called when the current source has been unloaded.
 *
 * @param event An object holding specific event data.
 */
- (void)onSourceUnloaded:(BMPSourceUnloadedEvent *)event;

/**
 * Is called when the player was destroyed.
 *
 * @param event An object holding specific event data.
 */
- (void)onDestroy:(BMPDestroyEvent *)event;

/**
 * Is called when metadata (i.e. ID3 tags in HLS and EMSG in DASH) are encountered.
 * 
 * @param event An object holding specific event data.
 */
- (void)onMetadata:(BMPMetadataEvent *)event;

/**
 * Is called when casting to another device, such as a ChromeCast, is available.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastAvailable:(BMPCastAvailableEvent *)event;

/**
 * Is called when the playback on an cast device has been paused.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastPaused:(BMPCastPausedEvent *)event;

/**
 * Is called when the playback on an cast device has been finished.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastPlaybackFinished:(BMPCastPlaybackFinishedEvent *)event;

/**
 * Is called when playback on an cast device has been started.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastPlaying:(BMPCastPlayingEvent *)event;

/**
 * Is called when the cast app is launched successfully.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastStarted:(BMPCastStartedEvent *)event;

/**
 * Is called when casting is initiated, but the user still needs to choose which device should be used.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastStart:(BMPCastStartEvent *)event;

/**
 * Is called when casting to a device is stopped.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastStopped:(BMPCastStoppedEvent *)event;

/**
 * Is called when the time update from the currently used cast device is received.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastTimeUpdated:(BMPCastTimeUpdatedEvent *)event;

/**
 * Is called when a cast device has been chosen and player is waiting for the device to get ready for playback.
 *
 * @param event An object holding specific event data.
 */
- (void)onCastWaitingForDevice:(BMPCastWaitingForDeviceEvent *)event;

/**
 * Is called when the player configuration has been updated by either calling load or setup on the player.
 *
 * @param event An object holding specific event data.
 */
- (void)onConfigurationUpdated:(BMPConfigurationUpdatedEvent *)event;

/**
 * Is called once after a new BMPPlayerListener was added to the event system.
 *
 * @param unseenEvents Contains all events which were already fired prior to adding the listener.
 */
- (void)onUnseen:(NSArray<BMPPlayerEvent *> *)unseenEvents;
@end

NS_ASSUME_NONNULL_END