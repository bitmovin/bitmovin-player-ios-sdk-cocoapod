//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdConfig.h>
#import <BitmovinPlayer/BMPAdTag.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration options for an AdTag.
 *
 * @see BMPAdTag
 */
NS_SWIFT_NAME(AdTagConfig)
@protocol BMPAdTagConfig <BMPAdConfig>

/**
 * Defines the url and type of the ad manifest. If the tag is a VAST or VPAID manifest, then more specific
 * scheduling options can be defined in the AdBreakConfig.
 *
 * @return The AdTag of the configuration.
 * @see BMPAdTag
 */
@property (nonatomic, readonly, nonnull) BMPAdTag *tag;

/**
 * Defines an array of fallback ad tags which will be tried one after the other if the original ad tag does not
 * provide a valid response.
 *
 * @return An array of fallback ad tags.
 * @see BMPAdTag
 */
@property (nonatomic, readonly, nonnull) NSArray<BMPAdTag *> *fallbackTags;

@end

NS_ASSUME_NONNULL_END
