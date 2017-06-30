//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerConfiguration.h>
#import <AVKit/AVKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the public API of the BitmovinPlayer. See the documentation of each single API method for further information.
 */
NS_SWIFT_NAME(PlayerAPI)
@protocol BMPPlayerAPI
/**
 * Returns YES if the player has been muted.
 */
@property (nonatomic, readonly, getter=isMuted) BOOL muted;

/**
 * Returns YES if the player has started playback but is currently paused.
 */
@property (nonatomic, readonly, getter=isPaused) BOOL paused;

/**
 * Returns YES if the player is currently playing, i.e. has started and is not paused.
 */
@property (nonatomic, readonly, getter=isPlaying) BOOL playing;

/**
 * Returns YES if the displayed video is a live stream.
 */
@property (nonatomic, readonly, getter=isLive) BOOL live;

/**
 * Returns the total duration in seconds of the current video or INFINITY if it’s a live stream.
 */
@property (nonatomic, readonly) NSTimeInterval duration;

/**
 * Returns the current playback time in seconds of the video.
 */
@property (nonatomic, readonly) NSTimeInterval currentTime;

/**
 * Returns the player config object of the current player instance.
 *
 * @return The current PlayerConfiguration of the player instance
 */
@property (nonatomic, nonnull, readonly) BMPPlayerConfiguration *config;

/**
 * Sets up player instance with the given configuration.
 *
 * @param configuration The configuration used to setup the player
 */
- (void)setup:(BMPPlayerConfiguration *)configuration;

/**
 * Sets a new media source.
 *
 * @param sourceConfiguration The source configuration used to set a new media source.
 */
- (void)load:(BMPSourceConfiguration *)sourceConfiguration;

/**
 * Starts preloading the content of the currently loaded source.
 */
- (void)preload;

/**
 * Unloads the current video source.
 */
- (void)unload;

/**
 * Destroys the player and releases all allocated resources.
 *
 * The player instance must not be used after calling this method.
 */
- (void)destroy;

/**
 * Starts playback or resumes after being paused. Has no effect if the player is already playing.
 */
- (void)play;

/**
 * Pauses the video if it is playing. Has no effect if the player is already paused.
 */
- (void)pause;

/**
 * Seeks to the given playback time.
 *
 * Seeks to the given playback time specified by the parameter time in seconds. Must not be
 * greater than the total duration of the video. Has no effect when watching a live stream as
 * seeking is not possible.
 *
 * @param time The time to seek to.
 */
- (void)seek:(NSTimeInterval)time;

/**
 * Mutes the player if an audio track is available. Has no effect if the player is already muted.
 */
- (void)mute;

/**
 * Unmutes the player it it is already muted. Has no effect if the player is not muted.
 */
- (void)unmute;


@end

NS_ASSUME_NONNULL_END
