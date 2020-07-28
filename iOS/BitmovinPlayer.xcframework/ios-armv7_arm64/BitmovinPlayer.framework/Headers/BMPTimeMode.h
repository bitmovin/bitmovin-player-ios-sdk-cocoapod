//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/// Represents different types of time modes.
typedef NS_ENUM(NSUInteger, BMPTimeMode) {
    /**
     * Returns the relative timestamp of the current playback time.
     * The beginning of the DVR window is 0 when a user just tuned into a stream
     * and this value is the offset from the beginning of the DVR window at that
     * point in time.
     * For VoD the start of the VoD is 0 and this value is the offset.
     */
    BMPTimeModeRelativeTime,
    /**
     * Returns the Unix timestamp of the current playback time.
     * In case of VOD HLS assets, this relies on the existence of the
     * `EXT-X-PROGRAM-DATE-TIME` tags in the manifest.
     * For VoD this does not have any affect.
     */
    BMPTimeModeAbsoluteTime
} NS_SWIFT_NAME(TimeMode);
