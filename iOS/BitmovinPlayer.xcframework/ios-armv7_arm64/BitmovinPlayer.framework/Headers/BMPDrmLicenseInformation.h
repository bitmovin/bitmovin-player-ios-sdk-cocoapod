//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(DrmLicenseInformation)
@interface BMPDrmLicenseInformation : NSObject
/**
 The duration in seconds how long this DRM license is valid.
 */
@property (nonatomic, readonly) NSTimeInterval licenseDuration;
/**
 The duration in seconds how long this DRM license is valid after playback was started for the first time.
 */
@property (nonatomic, readonly) NSTimeInterval playbackDuration;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithLicenseDuration:(NSTimeInterval)licenseDuration
                       playbackDuration:(NSTimeInterval)playbackDuration NS_DESIGNATED_INITIALIZER;
/**
 Returns the remaining license duration in seconds.

 @return the remaining license duration in seconds.
 */
- (NSTimeInterval)remainingLicenseDuration;
@end

NS_ASSUME_NONNULL_END
