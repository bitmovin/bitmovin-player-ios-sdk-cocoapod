//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 This class is used to turn on/off special features of the player that are implemented for specific customers which might not be suitable for all use-cases.
 */
NS_SWIFT_NAME(TweaksConfiguration)
@interface BMPTweaksConfiguration : BMPConfiguration

/**
 If enabled, HLS playlists would be parsed and corresponding events carrying segment-specific metadata, e.g. #EXT-X-SCTE35 tag if present in the manifest,
 are going to be sent.
 Default is NO.
 */
@property (nonatomic, assign, getter=isNativeHlsParsingEnabled) BOOL nativeHlsParsingEnabled;

@end

NS_ASSUME_NONNULL_END
