//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

/**
 * Types that can be specified for an AdTag.
 */
typedef NS_ENUM(NSInteger, BMPAdTagType) {
    /** Unknown advertising tag type */
    BMPAdTagTypeUnknown,
    /** VAST advertising tag type */
    BMPAdTagTypeVAST,
    /** VMAP advertising tag type */
    BMPAdTagTypeVMAP
} NS_SWIFT_NAME(AdTagType);
