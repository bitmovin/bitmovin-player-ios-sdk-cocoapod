//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayer/BMPFairplayConfiguration.h>
#import <BitmovinPlayer/BMPNetworkConfiguration.h>

@protocol _BMPFairplayHandlerDelegate;
@protocol BMPFairplayHandlerOfflineContentDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_FairplayHandler)
@interface _BMPFairplayHandler : NSObject <AVAssetResourceLoaderDelegate>
@property (nonatomic, weak, nullable) id<BMPFairplayHandlerOfflineContentDelegate> offlineContentDelegate;
@property (nonatomic, weak, nullable) id<_BMPFairplayHandlerDelegate> fairplayHandlerDelegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/**
 * When an offlineDRMLicense != nil is provided, it is used to satisfy DRM license requests. In this case no
 * network requests are made.
 *
 * @param fairplayConfiguration The FairPlay configuration which provides additional information and callbacks to be able
 *      to handle DRM license requests.
 * @param offlineDRMLicense The persisted DRM license which should be used to satisfy DRM license requests.
 */
- (instancetype)initWithFairplayConfiguration:(BMPFairplayConfiguration *)fairplayConfiguration
                         networkConfiguration:(nullable BMPNetworkConfiguration *)networkConfiguration
                            offlineDRMLicense:(nullable NSData *)offlineDRMLicense NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
