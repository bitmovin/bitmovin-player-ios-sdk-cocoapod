//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/// Represents different types of buffered data.
NS_SWIFT_NAME(BufferType)
typedef NS_ENUM(NSUInteger, BMPBufferType) {
    /// Represents the buffered data starting at the current playback time.
    BMPBufferTypeForwardDuration,
    /// Represents the buffered data up until the current playback time.
    BMPBufferTypeBackwardDuration
} NS_SWIFT_NAME(BufferType);
