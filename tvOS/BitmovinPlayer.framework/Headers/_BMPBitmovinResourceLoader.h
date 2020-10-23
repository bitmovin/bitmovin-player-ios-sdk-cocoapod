//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import <BitmovinPlayer/_BMPBitmovinResourceLoaderDelegate.h>
#import <BitmovinPlayer/BMPSourceItem.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_BitmovinResourceLoader)
@interface _BMPBitmovinResourceLoader : NSObject <AVAssetResourceLoaderDelegate>
@property (nonatomic, weak) id<_BMPBitmovinResourceLoaderDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithSourceItem:(BMPSourceItem *)sourceItem NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
