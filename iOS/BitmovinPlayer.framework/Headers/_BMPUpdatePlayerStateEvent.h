//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEvent.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_UpdatePlayerStateEvent)
@interface _BMPUpdatePlayerStateEvent : BMPPlayerEvent
@property (nonatomic, readonly, strong) NSDictionary<NSString *, NSString *> *stateValues;

- (void)addStatePropertyWithName:(NSString *)jsPropertyName value:(NSString *)value;
@end

NS_ASSUME_NONNULL_END
