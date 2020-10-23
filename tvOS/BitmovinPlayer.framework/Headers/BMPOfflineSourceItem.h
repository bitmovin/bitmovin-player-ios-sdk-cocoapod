//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayer/BMPSourceItem.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a BMPSourceItem which references already downloaded or currently downloading offline content. It can be
 * passed to a BMPBitmovinPlayer instance for playback. Do not create instances of this class on your own, instead
 * use BMPOfflineManager#createOfflineSourceItemForSourceItem:restrictedToAssetCache:.
 */
NS_SWIFT_NAME(OfflineSourceItem)
@interface BMPOfflineSourceItem : BMPSourceItem
/** Defines if the player is restricted to the usage of completely offline stored media renditions */
@property (nonatomic, readonly, getter=isRestrictedToAssetCache) BOOL restrictedToAssetCache;
/// :nodoc:
/// This references either the asset which is used to download offline content or the asset pointing to the already downloaded and stored local asset bundle
@property (nonatomic, strong, readonly) AVURLAsset *_urlAsset;
/// :nodoc:
/** The offline DRM license data which contains the content decryption keys needed to properly playback this asset */
@property (nonatomic, copy, readonly, nullable) NSData *_offlineDRMLicense;

- (instancetype)initWithUrl:(NSURL *)url NS_UNAVAILABLE;
- (instancetype)initWithAdaptiveSource:(BMPAdaptiveSource *)adaptiveSource NS_UNAVAILABLE;
- (instancetype)initWithProgressiveSource:(BMPProgressiveSource *)progressiveSource NS_UNAVAILABLE;
- (instancetype)initWithProgressiveSources:(NSArray<BMPProgressiveSource *> *)progressiveSources NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
