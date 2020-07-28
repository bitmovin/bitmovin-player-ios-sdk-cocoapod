//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMediaType.h>
#import <BitmovinPlayer/BMPBufferType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Holds different information about the buffer levels.
 */
NS_SWIFT_NAME(BufferLevel)
@interface BMPBufferLevel : NSObject

/**
 * The amount of currently buffered data, e.g. audio or video buffer level.
 */
@property (nonatomic, readonly) NSTimeInterval level;

/**
 * The target buffer level the player tries to maintain.
 */
@property (nonatomic, readonly) NSTimeInterval targetLevel;

/**
 * The media type the buffer data applies to.
 */
@property (nonatomic, readonly) BMPMediaType media;

/**
 * The buffer type the buffer data applies to.
 */
@property (nonatomic, readonly) BMPBufferType type;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
