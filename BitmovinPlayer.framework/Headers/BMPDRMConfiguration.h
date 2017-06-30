//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Base class for all DRM configurations.
 */
NS_SWIFT_NAME(DRMConfiguration)
@interface BMPDRMConfiguration : NSObject
@property (nonatomic, strong) NSURL *licenseUrl;
@property (nonatomic, strong) NSUUID *uuid;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithLicenseUrl:(NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
