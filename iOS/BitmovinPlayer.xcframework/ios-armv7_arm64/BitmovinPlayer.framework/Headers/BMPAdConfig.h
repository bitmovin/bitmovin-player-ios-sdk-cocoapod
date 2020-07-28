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
 * Contains the base configuration options for an ad.
 */
NS_SWIFT_NAME(AdConfig)
@protocol BMPAdConfig <BMPJsonable>

/**
 * Specifies how many seconds of the main video content should be replaced by ad break(s) or NaN if it doesn't apply.
 *
 * @return How many seconds of the main video content should be replaced by ad break(s) or NaN if it doesn't apply.
 */
@property (nonatomic, readonly) NSTimeInterval replaceContentDuration;

@end

NS_ASSUME_NONNULL_END
