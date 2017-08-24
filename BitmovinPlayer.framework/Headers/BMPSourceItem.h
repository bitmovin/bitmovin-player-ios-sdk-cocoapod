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
#import <BitmovinPlayer/BMPProgressiveSource.h>
#import <BitmovinPlayer/BMPAdaptiveSource.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>
#import <BitmovinPlayer/BMPJsonable.h>
#import <BitmovinPlayer/BMPLabelingConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a source item which can be played back in a player instance.
 */
NS_SWIFT_NAME(SourceItem)
@interface BMPSourceItem : NSObject <BMPJsonable>
@property (nonatomic, nullable, strong) NSString *itemTitle;
@property (nonatomic, nullable, strong) NSString *itemDescription;
@property (nonatomic, readonly) BMPMediaSourceType type;
@property (nonatomic, nullable, strong, readonly) BMPHLSSource *hlsSource;
@property (nonatomic, nullable, strong, readonly) NSArray<BMPProgressiveSource *> *progressiveSources;
@property (nonatomic, nullable, strong, readonly) NSURL *url;
@property (nonatomic, nullable, strong) NSURL *posterSource;
@property (nonatomic, getter=isPosterPersistent) BOOL persistentPoster;
@property (nonatomic, nonnull, strong) BMPLabelingConfiguration *labelingConfiguration;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithUrl:(NSURL *)url;
- (instancetype)initWithAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource;
- (instancetype)initWithProgressiveSource:(BMPProgressiveSource *)progressiveSource;
- (instancetype)initWithProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources;

- (nullable NSArray<BMPDRMConfiguration *> *)drmConfigurations;
- (nullable BMPDRMConfiguration *)drmConfigurationForDRMScheme:(NSUUID *)uuid;
- (void)addDRMConfiguration:(BMPDRMConfiguration *)drmConfiguration;
@end

NS_ASSUME_NONNULL_END
