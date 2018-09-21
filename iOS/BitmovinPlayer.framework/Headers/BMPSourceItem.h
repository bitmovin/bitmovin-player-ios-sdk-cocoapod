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

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a source item which can be played back in a player instance.
 */
NS_SWIFT_NAME(SourceItem)
@interface BMPSourceItem : NSObject <BMPJsonable>
@property (nonatomic, nullable, strong) NSString *itemTitle;
@property (nonatomic, nullable, strong) NSString *itemDescription;
@property (nonatomic, nullable, strong, readonly) BMPHLSSource *hlsSource;
@property (nonatomic, nullable, strong, readonly) BMPDASHSource *dashSource;
@property (nonatomic, nullable, strong, readonly) NSArray<BMPProgressiveSource *> *progressiveSources;
@property (nonatomic, nullable, strong) NSURL *posterSource;
@property (nonatomic, getter=isPosterPersistent) BOOL persistentPoster;
@property (nonatomic, nonnull, strong) BMPLabelingConfiguration *labelingConfiguration;
@property (nonatomic, nullable, strong, readonly) NSArray<BMPDRMConfiguration *> *drmConfigurations;
@property (nonatomic, nonnull, copy, readonly) NSArray<BMPTrack *> *tracks;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (nullable instancetype)initWithUrl:(NSURL *)url;
- (nullable instancetype)initWithAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource;
- (instancetype)initWithHLSSource:(BMPHLSSource *)hlsSource;
- (instancetype)initWithDASHSource:(BMPDASHSource *)dashSource;
- (instancetype)initWithProgressiveSource:(BMPProgressiveSource *)progressiveSource;
- (instancetype)initWithProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources;

- (nullable NSURL *)urlForType:(BMPMediaSourceType)type NS_SWIFT_NAME(url(forType:));
- (nullable BMPDRMConfiguration *)drmConfigurationForDRMScheme:(NSUUID *)uuid NS_SWIFT_NAME(drmConfigurationForDRMScheme(uuid:));
- (void)addDRMConfiguration:(BMPDRMConfiguration *)drmConfiguration NS_SWIFT_NAME(add(drmConfiguration:));
- (BOOL)hasSourceOfType:(BMPMediaSourceType)type NS_SWIFT_NAME(hasSource(ofType:));
- (BOOL)addSource:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(add(sourceUrl:));
- (BOOL)addAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource error:(NSError **)error NS_SWIFT_NAME(add(adaptiveSource:));
- (BOOL)addProgressiveSource:(BMPProgressiveSource *)progressiveSource error:(NSError **)error NS_SWIFT_NAME(add(progressiveSource:));
- (BOOL)addProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources error:(NSError **)error NS_SWIFT_NAME(add(progressiveSources:));
/**
 * Can be used to add external subtitles to the BMPSourceItem.
 *
 * @note Subtitles which are added using this method are only supported for SourceItems which are loaded into a
 * Chromecast session. Subtitles for local playback need to be referenced in the manifest of the stream.
 *
 * @param subtitleTrack The BMPSubtitleTrack to add.
 */
- (void)addSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack NS_SWIFT_NAME(add(subtitleTrack:));
@end

NS_ASSUME_NONNULL_END
