//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>

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
@end

NS_ASSUME_NONNULL_END
