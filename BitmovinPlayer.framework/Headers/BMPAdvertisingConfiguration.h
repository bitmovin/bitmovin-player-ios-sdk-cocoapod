//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPAdItem.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(AdvertisingConfiguration)
@interface BMPAdvertisingConfiguration : BMPConfiguration
@property (nonatomic, readonly, copy) NSArray<BMPAdItem *> *schedule;

- (instancetype)initWithSchedule:(NSArray<BMPAdItem *> *)schedule;
@end

NS_ASSUME_NONNULL_END

