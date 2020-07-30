//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 This configuration is used as an incubator for experimental features.
 Tweaks are not officially supported and are not guaranteed to be stable, i.e.
 their naming, functionality and API can change at any time within the tweaks
 or when being promoted to an official feature and moved into its final
 configuration namespace.
 */
NS_SWIFT_NAME(DownloadTweaksConfiguration)
@interface BMPDownloadTweaksConfiguration : BMPConfiguration
/**
 If enabled, tag EXT-X-PLAYLIST-TYPE:VOD will be inserted into downloaded playlists if EXT-X-PLAYLIST-TYPE is missing.
 Default is NO.
 */
@property (nonatomic, assign) BOOL shouldInsertPlaylistTypeTagIfMissing;
@end

NS_ASSUME_NONNULL_END
