//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

@protocol _BMPLogger;
@protocol _BMPEventEmitter;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_NamespacedServiceLocator)
@protocol _BMPNamespacedServiceLocator <NSObject>
@property (nullable, nonatomic, strong, readonly) id<_BMPEventEmitter> eventEmitter;
@property (nonatomic, strong, readonly) id<_BMPLogger> logger;
@end

NS_ASSUME_NONNULL_END
