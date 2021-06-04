//
// Bitmovin Player iOS SDK
// Copyright (C) 2021, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_HashProvider)
@interface _BMPHashProvider : NSObject
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
/**
 Returns the ObjC NSObject.hash value for the given object.

 NSObject.hash from ObjC and NSObject.hashValue used from Swift doesn't provide the same value.
 */
+ (NSUInteger)hashForObject:(id)object;
@end

NS_ASSUME_NONNULL_END
