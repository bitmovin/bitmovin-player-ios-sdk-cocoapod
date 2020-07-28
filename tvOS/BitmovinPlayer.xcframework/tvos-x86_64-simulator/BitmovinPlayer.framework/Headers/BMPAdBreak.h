//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdConfig.h>
#import <BitmovinPlayer/BMPAd.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains information about an ad break.
 */
NS_SWIFT_NAME(AdBreak)
@protocol BMPAdBreak <BMPAdConfig, BMPJsonable>

/**
 * The identifier of the corresponding AdBreakConfig.
 * If the AdBreak was generated out of a VMAP tag, then the ID present in the
 * VMAP tag will be taken. If none is present in the VMAP tag, it will be generated.
 *
 * @return The identifier of the corresponding AdBreakConfig.
 * @see BMPAdBreakConfig
 */
@property (nonatomic, readonly) NSString *identifier;

/**
 * The time in seconds in the media timeline the AdBreak is scheduled for.
 *
 * @return The time in seconds in the media timeline the AdBreak is scheduled for.
 */
@property (nonatomic, readonly) NSTimeInterval scheduleTime;

/**
 * The ads scheduled for this AdBreak.
 *
 * @return The ads scheduled for this AdBreak.
 * @see BMPAd
 */
@property (nonatomic, readonly) NSArray<id<BMPAd>> *ads;

/**
 * Adds an AdItem to the ads Array
 */
- (void)registerAd:(id<BMPAd>)adItem;

@end

NS_ASSUME_NONNULL_END
