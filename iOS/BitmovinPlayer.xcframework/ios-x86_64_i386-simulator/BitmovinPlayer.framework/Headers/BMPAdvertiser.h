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
 * Describes he advertiser as defined by the ad serving party. Specified in `InLine.Advertiser` in the VAST response.
 */
NS_SWIFT_NAME(Advertiser)
@interface BMPAdvertiser : NSObject <BMPJsonable>

/**
 * The name of the advertiser as defined by the ad serving party.
 *
 * @return The name of the advertiser as defined by the ad serving party.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * An identifier for the advertiser, provided by the ad server.
 *
 * @return An identifier for the advertiser, provided by the ad server.
 */
@property (nonatomic, readonly, nullable) NSString *identifier;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name
                  identifier:(nullable NSString *)identifier NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
