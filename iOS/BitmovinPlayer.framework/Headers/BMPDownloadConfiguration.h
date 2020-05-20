//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>
#import <BitmovinPlayer/BMPDownloadTweaksConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains configuration options which can be used to alter the default behaviour of content downloads.
 */
NS_SWIFT_NAME(DownloadConfiguration)
@interface BMPDownloadConfiguration : BMPConfiguration
/**
 The lowest media bitrate greater than or equal to this value in bps will be selected for
 download. If no suitable media bitrate is found or if set to nil, the highest media bitrate will be selected.
 */
@property(nonatomic, strong, nullable) NSNumber *minimumBitrate;
/**
 Indicates whether to scan for ClearKey decryption keys and store them for offline playback.
 Default: false

 @Note
 To prevent issues with playback of offline content, make sure that the `EXT-X-PLAYLIST-TYPE:VOD` tag is present in all variant playlists.
 */
@property(nonatomic) BOOL supportClearKeyContent;
/**
 Contains tweaks which can be used to alter the default behaviour of a source download.
 When using one of the tweaks, be aware that they could be removed or changed in behaviour even
 with minor version updates of the Bitmovin Player SDK. Such changes will be stated in the release
 notes.
 */
@property(nonatomic, strong, nonnull) BMPDownloadTweaksConfiguration *tweaksConfiguration;
@end

NS_ASSUME_NONNULL_END
