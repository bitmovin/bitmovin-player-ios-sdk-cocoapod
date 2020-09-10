//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a PlayReady DRM configuration.
 */
NS_SWIFT_NAME(PlayReadyConfiguration)
@interface BMPPlayReadyConfiguration : BMPDRMConfiguration
/** A dictionary to specify custom HTTP headers for the license request. */
@property (nonatomic, nonnull, copy) NSDictionary<NSString *, NSString *> *licenseRequestHeaders;
/** Specifies how long in milliseconds should be waited before a license request should be retried. Default is 0. */
@property (nonatomic) NSUInteger licenseRequestRetryDelay;
/**
 Specifies how often a license request should be retried if was not successful (e.g. the license server was not
 reachable). Default is 1. Assigning 0 disables retries.
 */
@property (nonatomic) NSUInteger maxLicenseRequestRetries;
/**
 A JSON String which allows to specify configuration options of the DRM key system, such as
 distinctiveIdentifier or persistentState.
 */
@property (nonatomic, nullable, copy) NSString *mediaKeySystemConfig;
/// :nodoc:
- (instancetype)initWithUUID:(NSUUID *)uuid NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_UNAVAILABLE;
/**
 Creates a new BMPPlayReadyConfiguration based on the given license URL.

 @param licenseUrl The URL to the license server.
 @return A new PlayReady configuration initialized with the given URL.
 */
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
