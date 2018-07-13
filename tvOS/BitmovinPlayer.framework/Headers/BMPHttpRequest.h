//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A configuration object representing an HTTP request.
 */
NS_SWIFT_NAME(HttpRequest)
@interface BMPHttpRequest : NSObject <NSCopying>
/** HTTP request body to send to the server. */
@property (nonatomic, copy, nullable) NSData *body;
/** HTTP headers of this request. */
@property (nonatomic, copy, nonnull) NSMutableDictionary<NSString *, NSString *> *headers;
/** HTTP method of the request. Can be "GET" | "POST" | "HEAD" */
@property (nonatomic, copy, nonnull) NSString *method;
/** URL of the request */
@property (nonatomic, copy, nonnull) NSURL *url;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithUrl:(NSURL *)url method:(NSString *)method NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
