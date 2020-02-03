//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSErrorDomain const BMPBitmovinPlayerWarningDomain;

NS_ERROR_ENUM(BMPBitmovinPlayerWarningDomain)
{
    BMPWarningGeneral = 1000,
    BMPWarningSetupRemotePlaybackFailed = 1102,
    BMPWarningSourceCouldNotParseThumbnails = 1206,
    BMPWarningSourceHlsPlaylistTypeMissing = 1207,
    BMPWarningSourceCouldNotParseSubtitles = 1208,
    BMPWarningNetworkCouldNotLoadSubtitle = 1402,
    BMPWarningNetworkCouldNotLoadThumbnails = 1403
};

NS_ASSUME_NONNULL_END
