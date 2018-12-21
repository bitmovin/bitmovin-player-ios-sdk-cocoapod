//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMediaSourceType.h>
#import <BitmovinPlayer/BMPHLSSource.h>
#import <BitmovinPlayer/BMPDASHSource.h>
#import <BitmovinPlayer/BMPProgressiveSource.h>
#import <BitmovinPlayer/BMPAdaptiveSource.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>
#import <BitmovinPlayer/BMPJsonable.h>
#import <BitmovinPlayer/BMPLabelingConfiguration.h>
#import <BitmovinPlayer/BMPTrack.h>
#import <BitmovinPlayer/BMPSubtitleTrack.h>
#import <BitmovinPlayer/BMPThumbnailTrack.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a source item which can be played back in a player instance.
 */
NS_SWIFT_NAME(SourceItem)
@interface BMPSourceItem : NSObject <BMPJsonable>
/** The title of the video source. */
@property (nonatomic, nullable, strong) NSString *itemTitle;
/** The description of the video source. */
@property (nonatomic, nullable, strong) NSString *itemDescription;
/**
 The HLS source for this source item.
 HLS content can easily and for free be generated using Bitmovin's video encoding solution.
 */
@property (nonatomic, nullable, strong, readonly) BMPHLSSource *hlsSource;
/**
 The DASH source for this source item which can ONLY be used for remote playback (e.g. Chromecast).
 DASH content can easily and for free be generated using Bitmovin's video encoding solution.
 */
@property (nonatomic, nullable, strong, readonly) BMPDASHSource *dashSource;
/**
 An array of progressive multimedia sources which are used as fallback when no HLS source is set.
 */
@property (nonatomic, nullable, strong, readonly) NSArray<BMPProgressiveSource *> *progressiveSources;
/** The URL to a preview image displayed until the video starts. */
@property (nonatomic, nullable, strong) NSURL *posterSource;
/**
 Indicates whether to show the poster image during playback.
 Useful, for example, for audio-only streams.
 */
@property (nonatomic, getter=isPosterPersistent) BOOL persistentPoster;
/** Configuration for audio and subtitle track labels. */
@property (nonatomic, nonnull, strong) BMPLabelingConfiguration *labelingConfiguration;
/** The DRM configuration for the main source. */
@property (nonatomic, nullable, strong, readonly) NSArray<BMPDRMConfiguration *> *drmConfigurations;
/** An array of timed data, such as thumbnail- or subtitle tracks. */
@property (nonatomic, nonnull, copy, readonly) NSArray<BMPTrack *> *tracks;
/** The thumbnail track for this source item */
@property (nonatomic, nullable, strong) BMPThumbnailTrack *thumbnailTrack;
/**
 Holds metadata for this source item. This data can be used by the player UI to display additional information about the
 currently played source. The following key-value pairs are supported for tvOS, where the system UI is used by default:

 key                                        | value type
 -------------------------------------------|----------------
 AVMetadataCommonKeyTitle                   | AVMetadataItem
 AVMetadataCommonKeyDescription             | AVMetadataItem
 AVMetadataCommonIdentifierArtwork          | AVMetadataItem
 AVMetadataiTunesMetadataKeyContentRating   | AVMetadataItem
 AVMetadataQuickTimeMetadataKeyGenre        | AVMetadataItem
 */
@property (nonatomic, copy) NSMutableDictionary<NSString *, id<NSObject, NSCopying>> *metadata;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

/**
 Creates a new BMPSourceItem based on the given source URL.

 @param url The URL for the media source.
 @return A new source item initialized with the given URL, or nil on failure.
 */
- (nullable instancetype)initWithUrl:(NSURL *)url;

/**
 Creates a new BMPSourceItem based on the given adaptive source.

 @param adaptiveSource The adaptive source for the source configuration.
 @return A new source item initialized with the given adaptive source, or nil on failure.
 */
- (nullable instancetype)initWithAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource;
/**
 Creates a new BMPSourceItem based on the given HLS source.

 @param hlsSource The HLS source for this source configuration.
 @return A new source item initialized with the given HLS source.
 */
- (instancetype)initWithHLSSource:(BMPHLSSource *)hlsSource;
/**
 Creates a new BMPSourceItem based on the given DASH source.

 @param dashSource The DASH source for this source configuration.
 @return A new source item initialized with the given DASH source.
 */
- (instancetype)initWithDASHSource:(BMPDASHSource *)dashSource;
/**
 Creates a new BMPSourceItem based on the given progressive source.

 @param progressiveSource The progressive source for this source configuration.
 @return A new source item initialized with the given progressive source.
 */
- (instancetype)initWithProgressiveSource:(BMPProgressiveSource *)progressiveSource;
/**
 Creates a new BMPSourceItem based on the given progressive sources.

 @param progressiveSources The progressive sources for this source configuration.
 @return A new source item initialized with the given progressive sources.
 */
- (instancetype)initWithProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources;
/**
 Returns the stream URL for the given media source type. Possible parameter values are defined in BMPMediaSourceType.h.

 @param type The media source type to get the URL for.
 @return The URL for the given media source type or nil if an invalid type was passed.
 */
- (nullable NSURL *)urlForType:(BMPMediaSourceType)type NS_SWIFT_NAME(url(forType:));
/**
 Returns the BMPDRMConfiguration for the given DRM scheme. Possible parameter values are defined in BMPDRMSystems.h.

 @param uuid The UUID of the corresponding DRM scheme.
 @return The BMPDRMConfiguration for the given UUID or nil if an invalid UUID was passed.
 */
- (nullable BMPDRMConfiguration *)drmConfigurationForDRMScheme:(NSUUID *)uuid NS_SWIFT_NAME(drmConfigurationForDRMScheme(uuid:));
/**
 Adds a given BMPDRMConfiguration to this source item.

 @param drmConfiguration The BMPDRMConfiguration to add.
 */
- (void)addDRMConfiguration:(BMPDRMConfiguration *)drmConfiguration NS_SWIFT_NAME(add(drmConfiguration:));
/**
 Indicates whether this source item contains a source for the given media source type.
 Possible parameter values are defined in BMPMediaSourceType.h.

 @param type The media source type to check.
 @return YES if a source for the given type is set, NO otherwise.
 */
- (BOOL)hasSourceOfType:(BMPMediaSourceType)type NS_SWIFT_NAME(hasSource(ofType:));

/**
 Tries to a add a new media source for the given URL.

 @note If an invalid URL was passed or media source for the URL cannot be identified, this method will fail.

 @param url The URL of the media source to add.
 @param error A pointer to an error object for receiving information about any problems that occurred when adding the source.
 @return YES if the media source was added correctly, NO otherwise.
 */
- (BOOL)addSource:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(add(sourceUrl:));
/**
 Tries to add a given adaptive source to this source item.

 @note If an adaptive source gets added and a source for the according type is already set, this method will fail.
 For example, adding a HLS source altough already set.

 @param adaptiveSource The adaptive source to add.
 @param error A pointer to an error object for receiving information about any problems that occurred when adding the source.
 @return YES if the adaptive source was added correctly, NO otherwise.
 */
- (BOOL)addAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource error:(NSError **)error NS_SWIFT_NAME(add(adaptiveSource:));
/**
 Tries to add a given progressive source to this source item.

 @note If an progressive source gets added and there are already progressive sources set, this method will fail.
 If you want to add multiple progressive source at a time, use #addProgressiveSources:error.

 @param progressiveSource The progressive source to add.
 @param error A pointer to an error object for receiving information about any problems that occurred when adding the source.
 @return YES if the progressive source was added correctly, NO otherwise.
 */
- (BOOL)addProgressiveSource:(BMPProgressiveSource *)progressiveSource error:(NSError **)error NS_SWIFT_NAME(add(progressiveSource:));
/**
 Tries to add the given progressive sources to this source item.

 @note If progressive sources get added and there are already progressive sources set, this method will fail.

 @param progressiveSources The progressive sources to add.
 @param error A pointer to an error object for receiving information about any problems that occurred when adding the sources.
 @return YES if the adaptive source was added correctly, NO otherwise.
 */
- (BOOL)addProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources error:(NSError **)error NS_SWIFT_NAME(add(progressiveSources:));
/**
 Can be used to add external subtitles to this source item.

 @note Subtitles which are added using this method are only supported for source items which are loaded into a
 Chromecast session. Subtitles for local playback need to be referenced in the manifest of the stream.

 @param subtitleTrack The subtitle track to add.
 */
- (void)addSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack NS_SWIFT_NAME(add(subtitleTrack:));
@end

NS_ASSUME_NONNULL_END
