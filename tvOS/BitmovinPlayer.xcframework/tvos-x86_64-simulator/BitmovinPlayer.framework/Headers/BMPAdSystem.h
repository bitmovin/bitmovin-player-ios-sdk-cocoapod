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
 * Describes the ad system that returned the ad. Specified in `InLine.AdSystem` in the VAST response.
 */
NS_SWIFT_NAME(AdSystem)
@interface BMPAdSystem : NSObject <BMPJsonable>

/**
 * The name of the ad system that returned the ad.
 *
 * @return The name of the ad system that returned the ad.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * The version number of the ad system that returned the ad.
 *
 * @return The version number of the ad system that returned the ad.
 */
@property (nonatomic, readonly, nullable) NSString *version;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithName:(NSString *)name
                     version:(nullable NSString *)version NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
