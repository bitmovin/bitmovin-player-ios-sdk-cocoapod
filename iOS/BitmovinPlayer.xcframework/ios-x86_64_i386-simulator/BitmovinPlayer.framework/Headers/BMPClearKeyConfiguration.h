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
 Represents a ClearKey configuration.
 */
NS_SWIFT_NAME(ClearKeyConfiguration)
@interface BMPClearKeyConfiguration : BMPDRMConfiguration
/** An array of objects representing the decryption keys. */
@property (nonatomic, nonnull, copy) NSArray<BMPDecryptionKey *> *decryptionKeys;
/// :nodoc:
- (instancetype)initWithUUID:(NSUUID *)uuid NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_UNAVAILABLE;
/**
 Creates a new BMPClearKeyConfiguration based on the given decryption keys.

 @param decryptionKeys The decryption keys to use for the ClearKey configuration.
 @return A ClearKey configuration which contains the given decryption keys for content decryption.
 */
- (instancetype)initWithDecryptionKeys:(NSArray<BMPDecryptionKey *> *)decryptionKeys NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
