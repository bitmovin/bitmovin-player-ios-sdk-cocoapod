//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvents.h>

@class PictureInPictureEnterEvent;
@class PictureInPictureEnteredEvent;
@class PictureInPictureExitEvent;
@class PictureInPictureExitedEvent;
@class BMPScalingModeChangedEvent;

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
 */
- (void)onFullscreenEnter:(BMPFullscreenEnterEvent *)event;

/**
 * Is called when the player exits fullscreen mode.
 *
 * @param event An object holding specific event data.
 */
- (void)onFullscreenExit:(BMPFullscreenExitEvent *)event;

/**
 * Is called when a fullscreen handler has been set.
 *
 * @param event An object holding specific event data.
 */
- (void)onFullscreenEnabled:(BMPFullscreenEnabledEvent *)event;

/**
 * Is called when the current fullscreen handler was removed.
 *
 * @param event An object holding specific event data.
 */
- (void)onFullscreenDisabled:(BMPFullscreenDisabledEvent *)event;

/**
 * Fires when the UI controls are showing.
 *
 * @param event An object holding specific event data.
 */
- (void)onControlsShow:(BMPControlsShowEvent *)event;

/**
 * Fires when the UI controls are hiding.
 *
 * @param event An object holding specific event data.
 */
- (void)onControlsHide:(BMPControlsHideEvent *)event;

/**
 * Is called when the PlayerView is about to enter Picture in Picture mode.
 *
 * @param event An object holding specific event data.
 */
- (void)onPictureInPictureEnter:(PictureInPictureEnterEvent *)event NS_SWIFT_NAME(onPictureInPictureEnter(_:));

/**
 * Is called when the PlayerView finished entering Picture in Picture mode.
 *
 * @param event An object holding specific event data.
 */
- (void)onPictureInPictureEntered:(PictureInPictureEnteredEvent *)event NS_SWIFT_NAME(onPictureInPictureEntered(_:));

/**
 * Is called when the PlayerView is about to exit Picture in Picture mode.
 *
 * @param event An object holding specific event data.
 */
- (void)onPictureInPictureExit:(PictureInPictureExitEvent *)event NS_SWIFT_NAME(onPictureInPictureExit(_:));

/**
 * Is called when the PlayerView finished exiting Picture in Picture mode.
 *
 * @param event An object holding specific event data.
 */
- (void)onPictureInPictureExited:(PictureInPictureExitedEvent *)event NS_SWIFT_NAME(onPictureInPictureExited(_:));

/**
 * Is called when the `ScalingMode` of the `PlayerView` changed.
 *
 * @param event An object holding specific event data.
 */
- (void)onScalingModeChanged:(BMPScalingModeChangedEvent *)event NS_SWIFT_NAME(onScalingModeChanged(_:));
@end

NS_ASSUME_NONNULL_END
