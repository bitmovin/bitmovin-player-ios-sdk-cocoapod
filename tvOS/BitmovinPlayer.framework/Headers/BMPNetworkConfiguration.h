//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPHttpRequest.h>
#import <BitmovinPlayer/BMPPreprocessHttpRequestDelegate.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The network configuration gives the ability to influence network requests. It enables preprocessing requests,
 * processing responses or influencing the retry behavior.
 */
NS_SWIFT_NAME(NetworkConfiguration)
@interface BMPNetworkConfiguration : NSObject
/**
 * Can be used to change request parameters before a request is made.
 * Default value is nil.
 */
@property (nonatomic, weak, nullable) id<BMPPreprocessHttpRequestDelegate> preprocessHttpRequestDelegate;
@end

NS_ASSUME_NONNULL_END
