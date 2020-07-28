//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Holds various additional ad data.
 * @see ImaAdData for more information on what additional data is available when using the Google IMA SDK implementation.
 */
NS_SWIFT_NAME(AdData)
@protocol BMPAdData <BMPJsonable>

/**
 * The MIME type of the media file or creative as defined in the VAST response.
 *
 * @return The MIME type of the media file or creative as defined in the VAST response.
 */
@property (nonatomic, readonly, nullable) NSString *mimeType;

/**
 * The average bitrate of the progressive media file as defined in the VAST response or -1, if not defined.
 *
 * @return The average bitrate of the progressive media file as defined in the VAST response or -1, if not defined.
 */
@property (nonatomic, readonly) NSInteger bitrate;

/**
 * The minimum bitrate of the streaming media file as defined in the VAST response or -1, if not defined.
 *
 * @return The minimum bitrate of the streaming media file as defined in the VAST response or -1, if not defined.
 */
@property (nonatomic, readonly) NSInteger minBitrate;

/**
 * The maximum bitrate of the streaming media file as defined in the VAST response or -1, if not defined.
 *
 * @return The maximum bitrate of the streaming media file as defined in the VAST response or -1, if not defined.
 */
@property (nonatomic, readonly) NSInteger maxBitrate;

@end

NS_ASSUME_NONNULL_END
