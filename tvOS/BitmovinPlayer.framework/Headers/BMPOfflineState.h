//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 * States a source item can have regarding to offline playback and offline DRM
 */
NS_SWIFT_NAME(OfflineState)
typedef NS_ENUM(NSInteger, BMPOfflineState) {
    /** Indicates that the content is downloaded */
    BMPOfflineStateDownloaded,
    /** Indicates that the content is currently downloading */
    BMPOfflineStateDownloading,
    /** Indicates that the content is not downloaded */
    BMPOfflineStateNotDownloaded
};
