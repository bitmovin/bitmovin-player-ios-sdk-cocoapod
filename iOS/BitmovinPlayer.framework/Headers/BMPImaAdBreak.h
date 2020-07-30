//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPAdBreak.h>
#import <BitmovinPlayer/BMPImaAdBreakConfig.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains IMA specific information about an AdBreak.
 *
 * @see BMPAdBreak
 */
NS_SWIFT_NAME(ImaAdBreak)
@protocol BMPImaAdBreak <BMPAdBreak, BMPImaAdBreakConfig>

@end

NS_ASSUME_NONNULL_END
