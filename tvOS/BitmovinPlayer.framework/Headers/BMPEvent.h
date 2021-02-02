//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Event)
@protocol BMPEvent <NSObject>
@property (nonatomic, readonly, copy) NSString *name;
@property (nonatomic, readonly) NSTimeInterval timestamp;
@end

NS_ASSUME_NONNULL_END
