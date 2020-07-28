//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A BMPFullscreenHandler implementation can be set on a BMPBitmovinPlayerView using its fullscreenHandler property. A
 * BMPFullscreenHandler acts as a delegate for handling the fullscreen related behaviour of the player view.
 */
NS_SWIFT_NAME(FullscreenHandler)
@protocol BMPFullscreenHandler <NSObject>
/**
 * Is called when the UI want's to know the current fullscreen state of the UI. Must return YES if the UI is in
 * fullscreen, otherwise NO.
 */
@property (nonatomic, readonly, getter=isFullscreen) BOOL fullscreen;

/**
 * Is called when the UI want's to enter fullscreen. This can be the result of either calling enterFullscreen on a
 * BMPBitmovinPlayerView or tapping the fullscreen button in Bitmovin's default UI. When a call to onFullscreenRequested
 * was successful, BMPFullscreenHandler#isFullscreen must return YES after the method returned.
 */
- (void)onFullscreenRequested;
/**
 * Is called when the UI want's to exit fullscreen. This can be the result of either calling exitFullscreen on a
 * BMPBitmovinPlayerView or tapping the fullscreen button in Bitmovin's default UI. When a call to
 * onFullscreenExitRequested was successful, BMPFullscreenHandler#isFullscreen must return NO after the method
 * returned.
 */
- (void)onFullscreenExitRequested;
@end

NS_ASSUME_NONNULL_END
