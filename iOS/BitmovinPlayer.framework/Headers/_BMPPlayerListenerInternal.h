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
@class _BMPInternalTimeShiftEvent;
@class _BMPInternalTimeShiftedEvent;
@class _BMPInternalPlayEvent;
@class _BMPInternalCastReadyEvent;
@class _BMPInternalMediaBufferChangedEvent;

NS_ASSUME_NONNULL_BEGIN

/**
 Private protocol for internal events
 */
NS_SWIFT_NAME(_PlayerListenerInternal)
@protocol _BMPPlayerListenerInternal <BMPPlayerListener>
@optional
/**
 Can be used to update the state of the player UI running in WebView, when updating through the official events
 documented in BMPPlayerListener is not working.
 */
- (void)onUpdatePlayerState:(_BMPUpdatePlayerStateEvent *)event;

/**
 Is called once after a new BMPPlayerListener was added to the event system.

 @param unseenEvents Contains all events which were already fired prior to adding the listener.
 */
- (void)onUnseen:(NSArray<BMPPlayerEvent *> *)unseenEvents;

/**
 Is called when master playlist data has been loaded.
 */
- (void)onMasterPlaylistLoaded:(_BMPMasterPlaylistLoadedEvent *)event;

/**
 Is called when variant playlist data has been loaded.
 */
- (void)onVariantPlaylistLoaded:(_BMPVariantPlaylistLoadedEvent *)event;

/**
 Is called when variant playlist SCTE-35 tags have been parsed.
 */
- (void)onScteTagsParsed:(_BMPScteTagsParsedEvent *)event;
/**
 Is called when the current playback time has changed. Will be fired every 0.2 seconds.
 Public configuration of the firing interval for time changed events is not affecting this event.
 */
- (void)onInternalTimeChanged:(_BMPInternalTimeChangedEvent *)event;
/**
 Is fired as soon as the AVPlayerItem enters the AVPlayerItemStatusReadyToPlay state for the first time after the source
 was loaded. This event is always fired before onReady.
 */
- (void)onInternalReady:(_BMPInternalReadyEvent *)event;
/**
 Is fired on intention to start/resume playback for main content (non-ad)
 */
- (void)onInternalPlay:(_BMPInternalPlayEvent *)event;
/**
 * Is called periodically during time shifting. Only applies to live streams, please refer to onSeek for VoD streams.
 *
 * @note This event is always triggered even for internal TimeShifts e.g. when applying a startOffset
 * @param event An object holding specific event data.
 */
- (void)onInternalTimeShift:(_BMPInternalTimeShiftEvent *)event;

/**
 * Is called when time shifting has been finished and data is available to continue playback. Only applies to live streams, please refer to onSeeked for VoD streams.
 *
 * @note This event is always triggered even for internal TimeShifts e.g. when applying a startOffset
 * @param event An object holding specific event data.
 */
- (void)onInternalTimeShifted:(_BMPInternalTimeShiftedEvent *)event;

/**
 * Is called when the cast receiver is ready for immediate playback.
 *
 * @param event An object holding specific event data.
 */
- (void)onInternalCastReady:(_BMPInternalCastReadyEvent *)event;
// TODO
- (void)onInternalMediaBufferChanged:(_BMPInternalMediaBufferChangedEvent *)event;
@end

NS_ASSUME_NONNULL_END
