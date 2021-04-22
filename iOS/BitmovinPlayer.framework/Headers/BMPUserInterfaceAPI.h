//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPScalingMode.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * API methods related to the user interface.
 */
NS_SWIFT_NAME(UserInterfaceAPI)
@protocol BMPUserInterfaceAPI <NSObject>
/**
 * Returns YES if the player is currently in fullscreen mode.
 *
 * @return YES if the player is currently in fullscreen mode.
 */
@property (nonatomic, readonly, getter=isFullscreen) BOOL fullscreen;

/**
 * Returns YES if the players playback controls are currently shown, NO if they are hidden.
 *
 * @return YES if the players playback controls are currently shown, NO if they are hidden.
 */
@property (nonatomic, readonly, getter=areControlsShown) BOOL controlsShown;

/**
 * Returns if Picture-In-Picture is available.
 * Picture in Picture-In-Picture in the following use-cases:
 * - on iPhone using iOS 14.2 and above. (We disabled PiP on iOS 14.0 and 14.1 due to an underlying iOS bug)
 * - on iPads using iOS 9 and above.
 * - if not explicitly disabled through BMPPlaybackConfiguration#isPictureInPictureEnabled (default is disabled)
 *
 * @return YES if the Picture-In-Picture is available.
 */
@property (nonatomic, readonly, getter=isPictureInPictureAvailable) BOOL pictureInPictureAvailable;

/**
 * Returns YES  if player is currently in Picture-in-Picture (PiP) mode.
 *
 * @return YES if Picture-In-Picture is active, NO otherwise.
 */
@property (nonatomic, readonly, getter=isPictureInPicture) BOOL pictureInPicture;

/**
 * A value defining how the video is displayed within the parent container's bounds.
 * Possible values are defined in `ScalingMode`.
 *
 * When a value was set before the `Player` was added to the view, it will have precedence over the value configured in `StyleConfig.scalingMode`
 */
@property (nonatomic) BMPScalingMode scalingMode;

/**
 * The player enters Picture-In-Picture mode. Has no effects if already in picture in picture.
 *
 * @note:
 * - Starting Picture-In-Picture during casting is not supported and will result in a no-op.
 * - This has no effect when using system UI.
 */
- (void)enterPictureInPicture;

/**
 * The player exits Picture-In-Picture mode. Has no effect if not in Picture-In-Picture mode.
 *
 * @note: This has no effect when using system UI.
 */
- (void)exitPictureInPicture;

/**
 * The player enters fullscreen mode. Has no effect if in fullscreen.
 */
- (void)enterFullscreen;

/**
 * The player exits fullscreen mode. Has no effect if not in fullscreen.
 */
- (void)exitFullscreen;

/**
 * Sets a poster image which will be displayed before playback starts.
 *
 * @param url The URL to the poster image
 * @param keepPersistent Flag to set the poster image persistent so it is also displayed during playback.
 */
- (void)setPosterImage:(NSURL *)url keepPersistent:(BOOL)keepPersistent NS_SWIFT_NAME(setPosterImage(url:keepPersistent:));

/**
 * Set the subtitle styles which should be applied to WebVTT subtitles and other legible text. Setting subtitle styles
 * using this method completely replaces all previously set subtitle styles.
 *
 * Setting subtitle styles is only supported when the userInterfaceType in the StyleConfiguration is set to
 * BMPUserInterfaceTypeSystem or BMPUserInterfaceTypeSubtitle.
 *
 * @param subtitleStyles The subtitle styles which should be applied.
 */
- (void)setSubtitleStyles:(nullable NSArray<AVTextStyleRule *> *)subtitleStyles;
@end

NS_ASSUME_NONNULL_END
