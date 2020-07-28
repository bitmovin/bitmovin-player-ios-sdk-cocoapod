//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPUniversalAdId.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains various data about the `Creative`. Specified in `InLine.Creative` or `Wrapper.Creative` in the
 * VAST Response.
 */
NS_SWIFT_NAME(Creative)
@interface BMPCreative : NSObject <BMPJsonable>

/**
 * Identifies the ad server that provides the creative. Specified in `Creative.id` in the VAST response.
 *
 * @return Identifies the ad server that provides the creative. Specified in `Creative.id` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *identifier;

/**
 * The ad server's unique identifier for the creative. Specified in `Creative.adId` in the VAST response.
 *
 * @return The ad server's unique identifier for the creative. Specified in `Creative.adId` in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *adId;

/**
 * A unique creative identifier that is maintained across systems. Specified in `Creative.UniversalAdId` in the
 * VAST response.
 *
 * @return A unique creative identifier that is maintained across systems. Specified in `Creative.UniversalAdId` in the
 * VAST response.
 * @see BMPUniversalAdId
 */
@property (nonatomic, readonly, nullable) BMPUniversalAdId *universalAdId;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithIdentifier:(nullable NSString *)identifier
                              adId:(nullable NSString *)adId
                     universalAdId:(nullable BMPUniversalAdId *)universalAdId NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
