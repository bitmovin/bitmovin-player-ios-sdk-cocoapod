//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdTagConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration options for an AdBreak.
 *
 * @see BMPAdBreak
 */
NS_SWIFT_NAME(AdBreakConfig)
@protocol BMPAdBreakConfig <BMPAdTagConfig>

/**
 * Unique identifier of the ad break.
 *
 * @return Unique identifier of the ad break.
 */
@property (nonatomic, readonly) NSString *identifier;

/**
 * Defines when the ad break should be played. Default is 'pre'.
 *
 * Allowed values are:
 * - 'pre': pre-roll ad
 * - 'post': post-roll ad
 * - fractional seconds: '10', '12.5' (mid-roll ad)
 * - percentage of the entire video duration: '25%', '50%' (mid-roll ad)
 * - timecode [hh:mm:ss.mmm]: '00:10:30.000', '01:00:00.000' (mid-roll ad)
 *
 * @return The defined position at which the ad should play.
 */
@property (nonatomic, readonly) NSString *position;

/**
 * Specifies after which time ads in the ad break become skippable. By setting it to `-1`, an ad is marked as
 * not skippable. Unless set to NaN, this will override the skip settings from the downloaded ads.
 *
 * @return The time after which ads in the ad break become skippable.
 */
@property (nonatomic, readonly) NSTimeInterval skippableAfter;

@end

NS_ASSUME_NONNULL_END
