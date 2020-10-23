//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVPlayerItem.h>

@class _BMPAVPlayerItem;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AVPlayerItemListener)
@protocol _BMPAVPlayerItemListener <NSObject>
@optional
- (void)playerItem:(_BMPAVPlayerItem *)playerItem willChangeMediaOptionFrom:(nullable AVMediaSelectionOption *)from to:(nullable AVMediaSelectionOption *)to inMediaSelectionGroup:(AVMediaSelectionGroup *)mediaSelectionGroup;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangeMediaOptionFrom:(nullable AVMediaSelectionOption *)from to:(nullable AVMediaSelectionOption *)to inMediaSelectionGroup:(AVMediaSelectionGroup *)mediaSelectionGroup;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangeStatus:(AVPlayerItemStatus)oldStatus newStatus:(AVPlayerItemStatus)newStatus;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangeDuration:(CMTime)oldDuration newDuration:(CMTime)newDuration;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangePlaybackBufferEmpty:(BOOL)playbackBufferEmpty;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangePlaybackLikelyToKeepUp:(BOOL)playbackLikelyToKeepUp;
- (void)playerItemDidPlayToEnd:(_BMPAVPlayerItem *)playerItem;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didFailToToPlayToEnd:(nullable NSError *)error;
- (void)playerItem:(_BMPAVPlayerItem *)playerItem didChangeTimedMetadata:(NSArray<AVMetadataItem *> *)timedMetadata;
- (void)playerItemDidReceiveNewAccessLogEntry:(_BMPAVPlayerItem *)playerItem;
@end

NS_ASSUME_NONNULL_END
