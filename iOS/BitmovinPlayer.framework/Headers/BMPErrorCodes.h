//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const BMPBitmovinPlayerErrorDomain;

NS_ERROR_ENUM(BMPBitmovinPlayerErrorDomain)
{
    BMPErrorPlayerLicenseKeyNotFound = 1016,
    BMPErrorPlayerLicenseInvalidDomain = 1017,
    BMPErrorInvalidPlayerLicenseServerUrl = 1018,
    BMPErrorJsonDeserializationFailed = 1114,
    BMPErrorPlaybackFailed = 1300,
    BMPErrorDrmGeneral = 2000,
    BMPErrorDrmMissingConfiguration = 2001,
    BMPErrorDrmNoLicenseServerUrlProvided = 2002,
    BMPErrorDrmLicenseRequestFailed = 2003,
    BMPErrorDrmInvalidCertificate = 2011,
    BMPErrorOfflineInsufficientStorage = 2201,
    BMPErrorOfflineFailedPersistingDrmLicense = 2202,
    BMPErrorManifestDownloadFailed = 3006,
    BMPErrorBadSource = 3032
};

NS_ASSUME_NONNULL_END
