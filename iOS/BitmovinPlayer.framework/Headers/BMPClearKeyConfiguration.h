//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>
#import <BitmovinPlayer/BMPDecryptionKey.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Represents a ClearKey configuration.
 */
NS_SWIFT_NAME(ClearKeyConfiguration)
@interface BMPClearKeyConfiguration : BMPDRMConfiguration
@property (nonatomic, nonnull, copy) NSArray<BMPDecryptionKey *> *decryptionKeys;

- (instancetype)initWithUUID:(NSUUID *)uuid NS_UNAVAILABLE;
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_UNAVAILABLE;
- (instancetype)initWithDecryptionKeys:(NSArray<BMPDecryptionKey *> *)decryptionKeys NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
