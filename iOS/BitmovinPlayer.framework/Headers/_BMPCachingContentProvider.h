//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPContentLoaderFactory.h"

@class _BMPRequestMetadata;

NS_ASSUME_NONNULL_BEGIN

typedef void(^CompletionBlock)(NSData *, _BMPRequestMetadata * _Nullable, BOOL cached);
typedef void(^ErrorBlock)(NSError * _Nullable, _BMPRequestMetadata * _Nullable);

NS_SWIFT_NAME(_CachingContentProvider)
@interface _BMPCachingContentProvider : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithUrl:(NSURL *)url contentLoaderFactory:(id<_BMPContentLoaderFactory>)contentLoaderFactory NS_DESIGNATED_INITIALIZER;
/**
 * Triggers loading or returns cached data immediately.
 *
 * @param onCompleted Will be called once loading finished. BMPRequestMetadata will be nil if cached data is used.
 * @param onError Will be called when an error occurs.
 *
 * @note must be called from main thread
 */
- (void)getDataWithCompletionBlock:(CompletionBlock)onCompleted onError:(ErrorBlock)onError;
/**
 * Will cancel ongoing loads and cleanup the instance.
 *
 * @note Must be called from the main thread. After calling this method the instance must not be used anymore.
 */
- (void)dispose;
@end

NS_ASSUME_NONNULL_END
