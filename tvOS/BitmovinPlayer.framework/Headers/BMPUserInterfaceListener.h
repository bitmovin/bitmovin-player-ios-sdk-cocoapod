//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvents.h>

@class BMPBitmovinPlayerView;

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines listener methods for all events available for the BitmovinPlayerView. See the documentation of the single listener
 * methods for further information.
 */
NS_SWIFT_NAME(UserInterfaceListener)
@protocol BMPUserInterfaceListener <NSObject>
@optional
/**
 * Is called when the player enters fullscreen mode.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onFullscreenEnter:(BMPFullscreenEnterEvent *)event view:(BMPBitmovinPlayerView *)view;

/**
 * Is called when the player exits fullscreen mode.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onFullscreenExit:(BMPFullscreenExitEvent *)event view:(BMPBitmovinPlayerView *)view;

/**
 * Is called when a fullscreen handler has been set.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onFullscreenEnabled:(BMPFullscreenEnabledEvent *)event view:(BMPBitmovinPlayerView *)view;

/**
 * Is called when the current fullscreen handler was removed.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onFullscreenDisabled:(BMPFullscreenDisabledEvent *)event view:(BMPBitmovinPlayerView *)view;

/**
 * Fires when the UI controls are showing.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onControlsShow:(BMPControlsShowEvent *)event view:(BMPBitmovinPlayerView *)view;

/**
 * Fires when the UI controls are hiding.
 *
 * @param event An object holding specific event data.
 * @param view The player view instance which is associated with the emitted event
 */
- (void)onControlsHide:(BMPControlsHideEvent *)event view:(BMPBitmovinPlayerView *)view;
@end

NS_ASSUME_NONNULL_END
