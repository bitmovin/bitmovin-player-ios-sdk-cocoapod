//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPVastAdData.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Holds additional ad data that's available when using the Google IMA SDK implementation.
 */
NS_SWIFT_NAME(ImaAdData)
@protocol BMPImaAdData <BMPVastAdData>

/**
 * The first deal ID present in the wrapper chain for the ad, starting from the top.
 *
 * @return The first deal ID present in the wrapper chain for the ad, starting from the top.
 */
@property (nonatomic, readonly, nullable) NSString *dealId;

@end

NS_ASSUME_NONNULL_END
