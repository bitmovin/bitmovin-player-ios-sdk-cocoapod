//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BufferMediaTypeConfiguration)
@interface BMPBufferMediaTypeConfiguration : BMPConfiguration

/**
 * The amount of data in seconds the player tries to buffer in advance.
 * If set to 0, the player will choose an appropriate forward buffer duration suitable for most use-cases.
 *
 * Default value is 0.
 */
@property (nonatomic, assign) NSTimeInterval forwardDuration;

@end

NS_ASSUME_NONNULL_END
