//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_SWIFT_NAME(MediaSourceType)
typedef NS_ENUM(NSInteger, BMPMediaSourceType) {
    BMPMediaSourceTypeNone,
    BMPMediaSourceTypeHLS,
    BMPMediaSourceTypeProgressive
};