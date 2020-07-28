//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAd.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Defines a linear ad which requires the playback of the content to stop
 */
NS_SWIFT_NAME(LinearAd)
@protocol BMPLinearAd <BMPAd>

/**
 * The duration of the ad.
 *
 * @return The duration of the ad.
 */
@property (nonatomic) NSTimeInterval duration;

/**
 * Time in seconds, after which the ad is skippable. The ad is not skippable if this property is to NaN.
 *
 * @return Time in seconds, after which the ad is skippable. The ad is not skippable if this property is set to NaN.
 */
@property (nonatomic) NSTimeInterval skippableAfter;

@end

NS_ASSUME_NONNULL_END
