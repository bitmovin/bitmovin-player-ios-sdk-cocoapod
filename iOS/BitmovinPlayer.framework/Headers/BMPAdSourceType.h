//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 * Type of the BMPAdSource
 */
typedef NS_ENUM(NSInteger, BMPAdSourceType) {
    /** Missing advertising source type */
    BMPAdSourceTypeNone = 0,
    /** Interactive Media Ads */
    BMPAdSourceTypeIMA,
    /** Unknown advertising source type */
    BMPAdSourceTypeUnknown,
    /** Progressive ad type */
    BMPAdSourceTypeProgressive
} NS_SWIFT_NAME(AdSourceType);
