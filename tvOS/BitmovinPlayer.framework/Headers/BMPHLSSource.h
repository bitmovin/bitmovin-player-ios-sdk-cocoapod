//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdaptiveSource.h>
#import <BitmovinPlayer/BMPMediaSourceType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a HLS media source.
 */
NS_SWIFT_NAME(HLSSource)
@interface BMPHLSSource : BMPAdaptiveSource
/// :nodoc:
- (instancetype)initWithType:(BMPMediaSourceType)mediaSourceType url:(NSURL *)url NS_UNAVAILABLE;
/**
 Creates a new HLS source based on the given URL.

 @param url The HLS media URL.
 @return A new HLS source initialized with the given URL.
 */
- (instancetype)initWithUrl:(NSURL *)url NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
