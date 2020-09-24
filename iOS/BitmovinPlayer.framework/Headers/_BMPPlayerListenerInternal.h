//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerListener.h>
@class BMPUpdatePlayerStateEvent;
@class BMPMasterPlaylistLoadedEvent;
@class BMPVariantPlaylistLoadedEvent;
@class BMPScteTagsParsedEvent;
@class BMPInternalTimeChangedEvent;
@class BMPInternalReadyEvent;

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
- (void)onUpdatePlayerState:(BMPUpdatePlayerStateEvent *)event;

/**
 Is called once after a new BMPPlayerListener was added to the event system.

 @param unseenEvents Contains all events which were already fired prior to adding the listener.
 */
- (void)onUnseen:(NSArray<BMPPlayerEvent *> *)unseenEvents;

/**
 Is called when master playlist data has been loaded.
 */
- (void)onMasterPlaylistLoaded:(BMPMasterPlaylistLoadedEvent *)event;

/**
 Is called when variant playlist data has been loaded.
 */
- (void)onVariantPlaylistLoaded:(BMPVariantPlaylistLoadedEvent *)event;

/**
 Is called when variant playlist SCTE-35 tags have been parsed.
 */
- (void)onScteTagsParsed:(BMPScteTagsParsedEvent *)event;
/**
 Is called when the current playback time has changed. Will be fired every 0.2 seconds.
 Public configuration of the firing interval for time changed events is not affecting this event.
 */
- (void)onInternalTimeChanged:(BMPInternalTimeChangedEvent *)event;
/**
 Is fired as soon as the AVPlayerItem enters the AVPlayerItemStatusReadyToPlay state for the first time after the source
 was loaded. This event is always fired before onReady.
 */
- (void)onInternalReady:(BMPInternalReadyEvent *)event;
@end

NS_ASSUME_NONNULL_END
