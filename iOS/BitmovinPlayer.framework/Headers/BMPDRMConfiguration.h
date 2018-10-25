//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for all DRM configurations.

 @note This class acts as an abstract class.
 */
NS_SWIFT_NAME(DRMConfiguration)
@interface BMPDRMConfiguration : BMPConfiguration
/** The DRM license acquisition URL. */
@property (nonatomic, strong, nullable) NSURL *licenseUrl;
/** The UUID for the respective DRM system. Possible values are defined in BMPDRMSystems. */
@property (nonatomic, strong) NSUUID *uuid;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_DESIGNATED_INITIALIZER;
/// :nodoc:
- (instancetype)initWithUUID:(NSUUID *)uuid;
@end

NS_ASSUME_NONNULL_END
