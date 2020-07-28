//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPHttpRequest.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Can be used to change request parameters before a request is made.
 */
NS_SWIFT_NAME(PreprocessHttpRequestDelegate)
@protocol BMPPreprocessHttpRequestDelegate <NSObject>
/**
 * Can be used to change request parameters before a request is made.
 *
 * @param type Type of the request to be made. Possible values are defined in BMPHttpRequestTypes.h.
 * @param httpRequest Configuration object of the request.
 * @param completionHandler Completion handler which must be called with the modified BMPHttpRequest. Not calling
 *  the completion handler prevents the HTTP request from being sent at all and blocks the player.
 */
- (void)preprocessHttpRequest:(NSString *)type httpRequest:(BMPHttpRequest *)httpRequest completionHandler:(void (^)(BMPHttpRequest * httpRequest))completionHandler;
@end

NS_ASSUME_NONNULL_END