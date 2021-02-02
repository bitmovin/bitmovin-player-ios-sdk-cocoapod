//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerListener.h>
@class _BMPUpdatePlayerStateEvent;
@class _BMPMasterPlaylistLoadedEvent;
@class _BMPVariantPlaylistLoadedEvent;
@class _BMPScteTagsParsedEvent;
@class _BMPInternalTimeChangedEvent;
@class _BMPInternalReadyEvent;
@protocol BMPEvent;
@class _BMPInternalTimeShiftEvent;
@class _BMPInternalTimeShiftedEvent;
@class _BMPInternalPlayEvent;
@class _BMPInternalActiveSourceChangedEvent;

NS_ASSUME_NONNULL_BEGIN

/**
 Private protocol for internal events
 */
NS_SWIFT_NAME(_PlayerListenerInternal)
@protocol _BMPPlayerListenerInternal <BMPPlayerListener>
@optional
/**
 * Can be used to update the state of the player UI running in WebView, when updating through the official events
 * documented in BMPPlayerListener is not working.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onUpdatePlayerState:(_BMPUpdatePlayerStateEvent *)event player:(BMPPlayer *)player;

/**
 * Is called once after a new BMPPlayerListener was added to the event system.
 *
 * @param unseenEvents Contains all events which were already fired prior to adding the listener.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onUnseen:(NSArray<id <BMPEvent>> *)unseenEvents player:(BMPPlayer *)player;

/**
 * Is called when master playlist data has been loaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onMasterPlaylistLoaded:(_BMPMasterPlaylistLoadedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when variant playlist data has been loaded.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onVariantPlaylistLoaded:(_BMPVariantPlaylistLoadedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when variant playlist SCTE-35 tags have been parsed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onScteTagsParsed:(_BMPScteTagsParsedEvent *)event player:(BMPPlayer *)player;
/**
 * Is called when the current playback time has changed. Will be fired every 0.2 seconds.
 * Public configuration of the firing interval for time changed events is not affecting this event.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onInternalTimeChanged:(_BMPInternalTimeChangedEvent *)event player:(BMPPlayer *)player;
/**
 * Is fired as soon as the AVPlayerItem enters the AVPlayerItemStatusReadyToPlay state for the first time after the source
 * was loaded. This event is always fired before onReady.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onInternalReady:(_BMPInternalReadyEvent *)event player:(BMPPlayer *)player;
/**
 * Is fired on intention to start/resume playback for main content (non-ad)
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onInternalPlay:(_BMPInternalPlayEvent *)event player:(BMPPlayer *)player;
/**
 * Is called periodically during time shifting. Only applies to live streams, please refer to onSeek for VoD streams.
 *
 * @note This event is always triggered even for internal TimeShifts e.g. when applying a startOffset
 * @param event An object holding specific event data.
 */
- (void)onInternalTimeShift:(_BMPInternalTimeShiftEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when time shifting has been finished and data is available to continue playback. Only applies to live streams, please refer to onSeeked for VoD streams.
 *
 * @note This event is always triggered even for internal TimeShifts e.g. when applying a startOffset
 * @param event An object holding specific event data.
 */
- (void)onInternalTimeShifted:(_BMPInternalTimeShiftedEvent *)event player:(BMPPlayer *)player;

/**
 * Is called when the active source of the player changed.
 *
 * @param event An object holding specific event data.
 * @param player The player instance which is associated with the emitted event
 */
- (void)onInternalActiveSourceChanged:(_BMPInternalActiveSourceChangedEvent *)event player:(BMPPlayer *)player;
@end

NS_ASSUME_NONNULL_END
