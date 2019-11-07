//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPConfiguration.h>
#import <BitmovinPlayer/BMPBufferMediaTypeConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/// Player buffer configuration object to configure buffering behavior.
NS_SWIFT_NAME(BufferConfiguration)
@interface BMPBufferConfiguration : BMPConfiguration

/**
 * Configures various settings for the audio and video buffer.
 */
@property (nonatomic, nonnull, strong) BMPBufferMediaTypeConfiguration *audioAndVideo;

@end

NS_ASSUME_NONNULL_END
