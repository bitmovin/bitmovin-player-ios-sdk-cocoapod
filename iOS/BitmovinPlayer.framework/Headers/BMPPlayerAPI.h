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
#import <BitmovinPlayer/BMPSubtitleTrack.h>
#import <BitmovinPlayer/BMPAudioTrack.h>
#import <BitmovinPlayer/BMPVideoQuality.h>
#import <BitmovinPlayer/BMPThumbnail.h>
#import <BitmovinPlayer/BMPBufferApi.h>
#import <BitmovinPlayer/BMPTimeMode.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the public API of the BitmovinPlayer. See the documentation of each single API method for further information.
 * All calls to the public player API must be done from the main thread. Calling API methods from multiple threads
 * concurrently is not guaranteed to result in consistent and stable behavior.
 */
NS_SWIFT_NAME(PlayerAPI)
@protocol BMPPlayerAPI
/**
 * Returns YES if the player has been muted.
 */
@property (nonatomic, readonly, getter=isMuted) BOOL muted;

/**
 * Get/set the player’s volume between 0 (silent) and 100 (max volume). This property is used to control the player audio
 * volume relative to the system volume.
 */
@property (nonatomic) NSInteger volume;

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
 * Returns the current playback time in seconds.
 * For VoD streams the returned time ranges between 0 and the duration of the asset.
 * For live streams a Unix timestamp denoting the current playback position is returned.
 */
@property (nonatomic, readonly) NSTimeInterval currentTime;

/**
 * Returns the current player configuration object of this player instance.
 */
@property (nonatomic, nonnull, readonly) BMPPlayerConfiguration *config;

/**
 * Returns the limit in seconds for time shift. Is either negative or 0. Is applicable for live streams only.
 */
@property (nonatomic, readonly) NSTimeInterval maxTimeShift;

/**
 * When set, shifts the time to the given offset in seconds from the live edge. Has to be within BMPPlayerAPI#maxTimeShift
 * (which is a negative value) and 0. Only works in live streams. The offset can be positive and is then interpreted as
 * a UNIX timestamp in seconds. The value has to be within the timeShift window, as specified by BMPPlayerAPI#maxTimeShift.
 */
@property (nonatomic) NSTimeInterval timeShift;

/**
 * Returns an array containing BMPSubtitleTrack objects for all available subtitle tracks.
 */
@property (nonatomic, readonly) NSArray<BMPSubtitleTrack *> *availableSubtitles;

/**
 * Returns the currently used BMPSubtitleTrack.
 */
@property (nonatomic, readonly) BMPSubtitleTrack *subtitle;

/**
 * Returns an array containing all available audio tracks.
 */
@property (nonatomic, readonly) NSArray<BMPAudioTrack *> *availableAudio;

/**
 * Returns the currently used audio track.
 */
@property (nonatomic, readonly, nullable) BMPAudioTrack *audio;

/**
 * Returns true while an ad is played back or content playback has been paused for ad playback, false otherwise.
 */
@property (nonatomic, readonly, getter=isAd) BOOL ad;

/**
 * Returns true when media is played externally using AirPlay.
 */
@property (nonatomic, readonly, getter=isAirPlayActive) BOOL airPlayActive;

/**
 * Returns true when AirPlay is available.
 */
@property (nonatomic, readonly, getter=isAirPlayAvailable) BOOL airPlayAvailable;

/**
 * Returns an array containing all available video qualities the player can adapt between.
 *
 * @return An array containing all available video qualities the player can adapt between.
 */
@property (nonatomic, readonly) NSArray<BMPVideoQuality *> *availableVideoQualities;

/**
 * Returns the currently selected video quality.
 *
 * @return The currently selected video quality.
 */
@property (nonatomic, readonly, nullable) BMPVideoQuality *videoQuality;

/**
 * Get/set the playback speed of the player. Fast forward as well as slow motion is supported. Slow motion is used by
 * values between 0 and 1, fast forward by values between 1 and 2. Values less or equal zero are ignored.
 */
@property (nonatomic) float playbackSpeed;

/**
 * Returns the currently used streaming technology.
 */
@property (nonatomic, readonly) BMPMediaSourceType streamType;

/**
 * The upper bitrate boundary in bits per second for network bandwidth consumption of the currently played source. Can
 * be set to 0 for no limitation. The value set here is only valid for the currently played source and will not be
 * carried over to subsequently loaded sources. Use BMPAdaptationConfiguration#maxSelectableBitrate to set a value which
 * is persistent for all loaded sources of one BitmovinPlayer instance.
 *
 * Default value is 0.
 */
@property (nonatomic) NSUInteger maxSelectableBitrate;

/**
 * Get/set metadata for the currently loaded source. All existing metadata will be completely replaced by the provided
 * metadata when the setter is called. For example, if sourceMetadata is an empty object, all existing source metadata
 * will be deleted. Setting new metadata results in a BMPSourceMetadataChanged event to be fired.
 */
@property (nonatomic) NSDictionary<NSString *, id<NSObject, NSCopying>> *sourceMetadata;

/**
 * Returns the currently playing video frame rate in units of frames per second.
 */
@property (nonatomic, readonly) float currentVideoFrameRate;

/**
 * Provides access to the buffer API.
 */
@property (nonatomic, readonly) id<BMPBufferApi> buffer API_AVAILABLE(ios(10.0), tvos(10.0));

/**
 * Sets up player instance with the given configuration.
 *
 * @param configuration The configuration used to setup the player
 */
- (void)setup:(BMPPlayerConfiguration *)configuration NS_SWIFT_NAME(setup(configuration:));

/**
 * Sets a new media source.
 *
 * @param sourceConfiguration The source configuration used to set a new media source.
 */
- (void)load:(BMPSourceConfiguration *)sourceConfiguration NS_SWIFT_NAME(load(sourceConfiguration:));

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
- (void)seek:(NSTimeInterval)time NS_SWIFT_NAME(seek(time:));

/**
 * Mutes the player if an audio track is available. Has no effect if the player is already muted.
 */
- (void)mute;

/**
 * Unmutes the player it it is already muted. Has no effect if the player is not muted.
 */
- (void)unmute;

/**
 * Adds a new external subtitle file. The BMPSubtitleTrack is only added to the available tracks, but is not set active.
 * Use BMPPlayerAPI#subtitle: to active it. If the ID already exists, the existing BMPSubtitleTrack is overwritten with the new one.
 *
 * @param subtitleTrack The BMPSubtitleTrack to be added to the available subtitles.
 */
- (void)addSubtitle:(BMPSubtitleTrack *)subtitleTrack NS_SWIFT_NAME(addSubtitle(track:)) __deprecated_msg("Use SourceItem#add(subtitleTrack:) instead.");

/**
 * Removes the existing BMPSubtitleTrack with the track ID specified by subtitleTrackID. If the track is currently active,
 * it will be deactivated and then removed. If no BMPSubtitleTrack with the given ID exists, the call will be ignored.
 * The BMPSubtitleTrack is removed from the available tracks, use BMPPlayerAPI#subtitle:nil to disable an active BMPSubtitleTrack.
 *
 * @param subtitleTrackID The ID of the BMPSubtitleTrack to be removed.
 */
- (void)removeSubtitle:(NSString *)subtitleTrackID NS_SWIFT_NAME(removeSubtitle(trackIdentifier:));

/**
 * Sets the subtitle track to the ID specified by trackID. A list can be retrieved by calling BMPPlayerAPI#availableSubtitles.
 * Using nil as ID disables subtitles.
 *
 * @param subtitleTrackID The id of the BMPSubtitleTrack which should be set.
 */
- (void)setSubtitleWithIdentifier:(nullable NSString *)subtitleTrackID NS_SWIFT_NAME(setSubtitle(trackIdentifier:));

/**
 * Sets the audio track to the ID specified by audioTrackID. A list can be retrieved by calling BMPPlayerAPI#availableAudio.
 *
 * @param audioTrackID The ID of the BMPAudioTrack which should be set.
 */
- (void)setAudioWithIdentifier:(NSString *)audioTrackID NS_SWIFT_NAME(setAudio(trackIdentifier:));

/**
 * Returns the thumbnail image for a certain time, or nil if there is no thumbnail available.
 * Requires a configured BMPThumbnailTrack in the corresponding BMPSourceItem.
 *
 * @param time The time for which the thumbnail should be returned.
 * @return An instance of BMPThumbnail for the given time, or nil if no thumbnail is available.
 */
- (nullable BMPThumbnail *)thumbnailForTime:(NSTimeInterval)time NS_SWIFT_NAME(thumbnail(forTime:));

/**
 * Skips the current ad. Has no effect if ad is not skippable or if no ad is played back.
 */
- (void)skipAd;

/**
 * Schedules an ad for playback.
 *
 * @param adItem the ad item to be scheduled.
 */
- (void)scheduleAd:(BMPAdItem *)adItem NS_SWIFT_NAME(scheduleAd(adItem:)) __TVOS_PROHIBITED;

/**
 * Shows the AirPlay playback target picker.
 */
- (void)showAirPlayTargetPicker;

/**
 * Returns the current playback time in seconds.
 * For VoD streams the returned time ranges between 0 and the duration of the asset.
 * For live streams it can be specified if an absolute unix timestamp or a value relative to the playback start should be returned.
 *
 * @param timeMode to specify if an absolute unix timestamp or an relative time should be returned.
 */
- (NSTimeInterval)currentTime:(BMPTimeMode)timeMode;

@end

NS_ASSUME_NONNULL_END
