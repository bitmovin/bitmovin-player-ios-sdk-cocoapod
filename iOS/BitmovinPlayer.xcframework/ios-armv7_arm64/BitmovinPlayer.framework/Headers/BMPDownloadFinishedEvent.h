//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * See BMPPlayerListener.h for more information on this event.
 */
NS_SWIFT_NAME(DownloadFinishedEvent)
@interface BMPDownloadFinishedEvent : BMPPlayerEvent
/**
 * Specifies the type of the request. Possible values are defined in BMPHttpRequestTypes.h.
 */
@property (nonatomic, readonly, copy) NSString *downloadType;
/**
 * The URL of the request.
 */
@property (nonatomic, readonly, copy) NSURL *url;
/**
 * The URL of the last redirect location in case a redirect happened
 */
@property (nonatomic, readonly, copy, nullable) NSURL *lastRedirectLocation;
/**
 * The time needed to finish the request.
 */
@property (nonatomic, readonly) NSTimeInterval downloadTime;
/**
 * The HTTP status code of the request.
 * Status code 0 means that a general network error happened, e.g. no network connectivity
 */
@property (nonatomic, readonly) NSUInteger httpStatus;
/**
 * The size of the downloaded data, in bytes
 */
@property (nonatomic, readonly) NSUInteger size;
/**
 * Indicates whether the request was successful (YES) or failed (NO).
 */
@property (nonatomic, readonly, getter=wasSuccessful) BOOL successful;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithType:(NSString *)type
                         url:(NSURL *)url
                downloadTime:(NSTimeInterval)downloadTime
                  httpStatus:(NSUInteger)httpStatus
                        size:(NSUInteger)size
                     success:(BOOL)successful
        lastRedirectLocation:(nullable NSURL *)lastRedirectLocation NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
