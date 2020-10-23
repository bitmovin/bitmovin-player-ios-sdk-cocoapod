//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _M3U8MediaResolution: NSObject
@property (readonly) float width;
@property (readonly) float height;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithString:(nullable NSString *)string;
- (instancetype)initWithWidth:(float)width height:(float)height NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
