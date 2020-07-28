//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPDRMConfiguration.h>
#import <BitmovinPlayer/BMPDrmLicenseInformation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a FairPlay Streaming DRM configuration.
 */
NS_SWIFT_NAME(FairplayConfiguration)
@interface BMPFairplayConfiguration : BMPDRMConfiguration
/** The URL to the FairPlay Streaming certificate of the license server. */
@property (nonatomic, strong) NSURL *certificateUrl;
/** A dictionary to specify custom HTTP headers for the license request. */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *licenseRequestHeaders;
/** A dictionary to specify custom HTTP headers for the certificate request. */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *certificateRequestHeaders;
/**
 A block to prepare the data which is sent as the body of the POST license request. As many DRM providers
 expect different, vendor-specific messages, this can be done using this user-defined block.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareMessage)(NSData *spcData, NSString *assetID);
/**
 A block to prepare the contentId, which is sent to the FairPlay Streaming license server as request body,
 and which is used to build the SPC data. As many DRM providers expect different, vendor-specific messages, this can
 be done using this user-defined block. The parameter is the skd:// URI extracted from the HLS manifset (m3u8) and the return value
 should be the contentID as string.
 */
@property (nonatomic, copy, nullable) NSString *(^prepareContentId)(NSString *contentId);
/**
 A block to prepare the loaded certificate before building SPC data and passing it into the system. This is needed
 if the server responds with anything else than the certificate, e.g. if the certificate is wrapped into a JSON object.
 The server response for the certificate request is passed as parameter “as is”.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareCertificate)(NSData *certificate);
/**
 A block to prepare the loaded CKC Data before passing it to the system. This is needed if the server responds
 with anything else than the license, e.g. if the license is wrapped into a JSON object.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareLicense)(NSData *ckc);
/**
 A block to prepare the URI (without the `skd://`) from the HLS manifest before passing it to the system. 
 */
@property (nonatomic, copy, nullable) NSString *(^prepareLicenseServerUrl)(NSString *licenseServerUrl);
/**
 A block to prepare the loaded CKC data received by the Sync SPC call to the respective Key Security Module (KSM).
 This data may contain information about the expiration dates of a DRM license.
 */
@property (nonatomic, copy, nullable) BMPDrmLicenseInformation *(^prepareOfflineDrmLicenseInformation)(NSData *data);
/**
 A block to prepare the data which is sent as the body of the POST request for syncing the DRM license information.
 */
@property (nonatomic, copy, nullable) NSData *(^prepareSyncMessage)(NSData *syncSpcData, NSString *assetID);
/// :nodoc:
- (instancetype)initWithUUID:(NSUUID *)uuid NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl uuid:(NSUUID *)uuid NS_UNAVAILABLE;
/**
 Creates a new FairPlay Streaming configuration based on the given license URL and certificate URL.

 @param licenseUrl The URL to the license server.
 @param certificateUrl The URL to the FairPlay Streaming certificate of the license server.
 @return A new FairPlay Streaming configuration initialized with the given licenseURL and certificateURL.
 */
- (instancetype)initWithLicenseUrl:(nullable NSURL *)licenseUrl certificateURL:(NSURL *)certificateUrl NS_DESIGNATED_INITIALIZER;
/**
 Creates a new FairPlay Streaming configuration based on the given certificate URL.

 @param certificateUrl The URL to the FairPlay Streaming certificate of the license server.
 @return A new FairPlay Streaming configuration initialized with the given cerfificateURL. The license URL defaults to nil.
 */
- (instancetype)initWithCertificateURL:(NSURL *)certificateUrl;
@end

NS_ASSUME_NONNULL_END
