//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_CodecHelper)
@interface _BMPCodecHelper : NSObject
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;

+ (NSDictionary<NSString *, NSString *> *)extractCodecStrings:(nullable NSArray<NSString *> *)codecs;
@end

NS_ASSUME_NONNULL_END

