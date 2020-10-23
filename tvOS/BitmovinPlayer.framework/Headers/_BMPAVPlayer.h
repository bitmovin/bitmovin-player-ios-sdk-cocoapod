//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVPlayer.h>

@protocol _BMPAVPlayerObserver;
@class _BMPAVPlayerItem;

NS_ASSUME_NONNULL_BEGIN

@interface _BMPAVPlayer : AVPlayer
@property (nonatomic, readonly, nullable) _BMPAVPlayerItem *currentItem;

- (void)seekToTime:(CMTime)time
   toleranceBefore:(CMTime)toleranceBefore
    toleranceAfter:(CMTime)toleranceAfter
    suppressEvents:(BOOL)suppressEvents
 completionHandler:(void (^)(BOOL))completionHandler;
- (void)addObserver:(id<_BMPAVPlayerObserver>)observer;
- (void)removeObserver:(id<_BMPAVPlayerObserver>)observer;
@end

NS_ASSUME_NONNULL_END
