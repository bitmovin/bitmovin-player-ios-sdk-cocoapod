//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Indicates which type of UI should be used.
 */
typedef NS_ENUM(NSInteger, BMPUserInterfaceType) {
    /** Indicates that Bitmovins customizable UI should be used. */
    BMPUserInterfaceTypeBitmovin __TVOS_PROHIBITED,
    /** Indicates that the system UI should be used. */
    BMPUserInterfaceTypeSystem,
    /** Indicates that only subtitles should be displayed along with the video content */
    BMPUserInterfaceTypeSubtitle
} NS_SWIFT_NAME(UserInterfaceType);

NS_ASSUME_NONNULL_END
