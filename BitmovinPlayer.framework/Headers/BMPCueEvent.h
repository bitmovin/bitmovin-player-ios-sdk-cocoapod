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

NS_SWIFT_NAME(CueEvent)
@interface BMPCueEvent : BMPPlayerEvent
@property (nonatomic, readonly) NSTimeInterval startTime;
@property (nonatomic, readonly) NSTimeInterval endTime;
@property (nonatomic, readonly, nullable, copy) NSString *text;
@property (nonatomic, readonly, nullable, copy) NSString *position;
@property (nonatomic, readonly, nullable, copy) NSString *region;
@property (nonatomic, readonly, nullable, copy) NSString *regionStyle;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithStartTime:(NSTimeInterval)startTime
                          endTime:(NSTimeInterval)endTime
                             text:(nullable NSString *)text
                         position:(nullable NSString *)position
                           region:(nullable NSString *)region
                      regionStyle:(nullable NSString *)regionStyle NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithStartTime:(NSTimeInterval)startTime
                          endTime:(NSTimeInterval)endTime;

- (instancetype)initWithStartTime:(NSTimeInterval)startTime
                          endTime:(NSTimeInterval)endTime
                             text:(NSString *)text;
@end

NS_ASSUME_NONNULL_END
