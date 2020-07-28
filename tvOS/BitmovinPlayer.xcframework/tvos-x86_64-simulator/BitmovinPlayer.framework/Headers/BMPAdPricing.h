//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Used to provide a value that represents a price that can be used by real-time bidding (RTB) systems. Specified
 * in `Inline.Pricing` in the VAST response.
 */
NS_SWIFT_NAME(AdPricing)
@interface BMPAdPricing : NSObject <BMPJsonable>
/**
 * A numerical value that represents a price that can be used in real-time bidding systems.
 *
 * @return A numerical value that represents a price that can be used in real-time bidding systems.
 */
@property (nonatomic, readonly) double value;

/**
 * Identifies the pricing model as one of: CPM, CPC, CPE, or CPV.
 *
 * @return Identifies the pricing model as one of: CPM, CPC, CPE, or CPV.
 */
@property (nonatomic, readonly) NSString *model;

/**
 * The three-letter ISO-4217 currency symbol that identifies the currency of the value provided (e.g. USD, GBP, etc.).
 *
 * @return The three-letter ISO-4217 currency symbol that identifies the currency of the value provided (e.g. USD, GBP, etc.).
 */
@property (nonatomic, readonly) NSString *currency;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithValue:(double)value
                        model:(NSString *)model
                     currency:(NSString *)currency NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
