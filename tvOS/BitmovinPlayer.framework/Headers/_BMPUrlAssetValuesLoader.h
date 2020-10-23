//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_UrlAssetValuesLoader)
@protocol _BMPUrlAssetValuesLoader
- (void)loadValuesAsynchronouslyForAsset:(AVURLAsset *)asset onComplete:(void (^ _Nullable)(AVURLAsset *asset, BOOL success, BOOL canceled))onComplete;
- (void)triggerContentKeyRequestForAsset:(AVURLAsset *)asset;
@end

NS_ASSUME_NONNULL_END
