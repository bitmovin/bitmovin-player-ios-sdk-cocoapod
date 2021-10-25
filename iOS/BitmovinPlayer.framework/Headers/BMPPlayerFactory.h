//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPBitmovinPlayer.h>

@class BMPPlayerConfiguration;

NS_ASSUME_NONNULL_BEGIN

/**
 * Factory to create a `BMPBitmovinPlayer` instance.
 */
NS_SWIFT_UNAVAILABLE("Use PlayerFactory instead")
@interface BMPPlayerFactory : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 * Creates a player instance configured via the provided `BMPPlayerConfiguration`.
 */
+ (BMPBitmovinPlayer *)createWithPlayerConfiguration:(BMPPlayerConfiguration *)playerConfiguration;

/**
 * Creates a player instance with the default `BMPPlayerConfiguration`.
 */
+ (BMPBitmovinPlayer *)create;
@end

NS_ASSUME_NONNULL_END
