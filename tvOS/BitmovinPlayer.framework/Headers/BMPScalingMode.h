//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Specifies how the video content is scaled or stretched.
 */
typedef NS_ENUM(NSInteger, BMPScalingMode) {
    /** Specifies that the player should preserve the video’s aspect ratio and fill the container’s bounds. */
    BMPScalingModeZoom,
    /** Specifies that the video should be stretched to fill the container’s bounds. The aspect ratio may not be preserved. */
    BMPScalingModeStretch,
    /** Specifies that the player should preserve the video’s aspect ratio and fit the video within the container's bounds (default). */
    BMPScalingModeFit
} NS_SWIFT_NAME(ScalingMode);

NS_ASSUME_NONNULL_END
