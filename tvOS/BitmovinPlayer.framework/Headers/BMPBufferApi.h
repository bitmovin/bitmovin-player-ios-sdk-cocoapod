//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPBufferType.h>

@class BMPBufferLevel;

NS_ASSUME_NONNULL_BEGIN

/**
 * Provides methods to get the information about the buffer levels.
 */
NS_SWIFT_NAME(BufferApi)
@protocol BMPBufferApi <NSObject>

/**
 * Returns the buffer level in seconds for the specified type.
 * @param type The type of buffer to return the level for.
 */
- (BMPBufferLevel *)getLevel:(BMPBufferType)type;

/**
 * Sets the target level in seconds for the forward buffer.
 * @param value The value to set.
 */
- (void)setTargetLevel:(NSTimeInterval)value;

@end

NS_ASSUME_NONNULL_END
