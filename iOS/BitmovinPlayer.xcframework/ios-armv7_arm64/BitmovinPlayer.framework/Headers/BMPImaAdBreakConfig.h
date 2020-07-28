//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdBreakConfig.h>
#import <BitmovinPlayer/BMPImaAdTagConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains IMA specific AdBreakConfig options.
 *
 * @see BMPAdBreakConfig
 */
NS_SWIFT_NAME(ImaAdBreakConfig)
@protocol BMPImaAdBreakConfig <BMPAdBreakConfig, BMPImaAdTagConfig>

@end

NS_ASSUME_NONNULL_END
