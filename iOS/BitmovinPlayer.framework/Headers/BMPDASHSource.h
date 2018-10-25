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
 Represents a DASH media source.
 */
NS_SWIFT_NAME(DASHSource)
@interface BMPDASHSource : BMPAdaptiveSource
/// :nodoc:
- (instancetype)initWithType:(BMPMediaSourceType)mediaSourceType url:(NSURL *)url NS_UNAVAILABLE;
/**
 Creates a new DASHSource from the given URL.

 @param url The URL to use for the DASH source.
 @return A DASH media source initialized with the given URL.
 */
- (instancetype)initWithUrl:(NSURL *)url NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
