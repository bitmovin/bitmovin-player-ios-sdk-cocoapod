//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPCachingContentProvider.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_CachingCueProvider)
@interface _BMPCachingCueProvider : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithContentProvider:(_BMPCachingContentProvider *)contentProvider NS_DESIGNATED_INITIALIZER;
/**
 * Triggers loading of subtitle cues or returns cached data immediately, if already downloaded.
 *
 * @param onCompleted Will be called once loading finished. BMPRequestMetadata will be nil if cached data is used.
 * @param onError Will be called when an error occurs.
 *
 * @note Must be called from main thread
 */
- (void)getCuesWithCompletionBlock:(void (^)(NSArray *, _BMPRequestMetadata * _Nullable, BOOL cached))onCompleted
                           onError:(void (^)(NSError * _Nullable, _BMPRequestMetadata * _Nullable))onError;
/**
 * Will cancel ongoing loads and cleanup the instance.
 *
 * @note Must be called from main thread. After calling this method the instance must not be used anymore. 
 */
- (void)dispose;
@end

NS_ASSUME_NONNULL_END
