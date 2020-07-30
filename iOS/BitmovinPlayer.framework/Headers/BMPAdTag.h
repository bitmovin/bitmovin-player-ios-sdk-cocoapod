//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdTagType.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines the url and type of an ad manifest.
 */
NS_SWIFT_NAME(AdTag)
@interface BMPAdTag : NSObject <BMPJsonable>

/**
 * The AdTagType of the ad tag.
 *
 * @return The AdTagType of the ad tag.
 * @see BMPAdTagType
 */
@property (nonatomic, readonly) BMPAdTagType type;

/**
 * Defines the path to an ad manifest. If the tag is a VMAP manifest, the resulting ad breaks will be scheduled as
 * described in the manifest, otherwise the ad breaks will be handled as pre-roll ads if no further information is
 * specified in the AdBreakConfig.position property.
 *
 * @return The path to an ad manifest.
 * @see AdBreakConfig
 */
@property (nonatomic, readonly) NSURL *url;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithUrl:(NSURL *)url ofType:(BMPAdTagType)type NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
