//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPAVPlayerItem.h"
@class _BMPAVPlayer;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AVPlayerObserver)
@protocol _BMPAVPlayerObserver <NSObject>
@optional
- (void)player:(_BMPAVPlayer *)player willSeekToTargetTime:(CMTime)seekTarget suppressEvents:(BOOL)suppressEvents;
- (void)player:(_BMPAVPlayer *)player didSeekWithSuccess:(BOOL)finished suppressEvents:(BOOL)suppressEvents;
- (void)player:(_BMPAVPlayer *)player didChangeStatus:(AVPlayerStatus)oldStatus newStatus:(AVPlayerStatus)newStatus;
- (void)player:(_BMPAVPlayer *)player didChangeCurrentItem:(nullable _BMPAVPlayerItem *)oldItem newItem:(nullable _BMPAVPlayerItem *)newItem;
- (void)player:(_BMPAVPlayer *)player didChangeTimeControlStatus:(AVPlayerTimeControlStatus)oldTimeControlStatus newTimeControlStatus:(AVPlayerTimeControlStatus)newTimeControlStatus;
- (void)player:(_BMPAVPlayer *)player didChangeExternalPlaybackActive:(BOOL)oldValue newExternalPlaybackActive:(BOOL)newValue;
@end

NS_ASSUME_NONNULL_END
