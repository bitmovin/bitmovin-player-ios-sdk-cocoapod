//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values which can be used to alter the playback behaviour of the player.
 */
NS_SWIFT_NAME(PlaybackConfiguration)
@interface BMPPlaybackConfiguration : BMPConfiguration
/** Whether the player starts playing automatically after loading a source or not. Default value is NO. */
@property (nonatomic, getter=isAutoplayEnabled) BOOL autoplayEnabled;
/** Whether the sound is muted on startup or not. Default value is NO. */
@property (nonatomic, getter=isMuted) BOOL muted;
/** Whether time shift / DVR for live streams is enabled or not. Default is YES. */
@property (nonatomic, getter=isTimeShiftEnabled) BOOL timeShiftEnabled;
/**
 * Whether background playback is enabled or not. Default is NO. When set to YES, playback is not automatically paused
 * anymore when the app moves to the background. When set to YES, also make sure to properly configure your app to allow
 * background playback.
 */
@property (nonatomic, getter=isBackgroundPlaybackEnabled) BOOL backgroundPlaybackEnabled;
@end

NS_ASSUME_NONNULL_END
