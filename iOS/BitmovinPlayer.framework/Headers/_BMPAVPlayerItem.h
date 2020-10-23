//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVPlayerItem.h>

@protocol _BMPAVPlayerItemListener;

NS_ASSUME_NONNULL_BEGIN

@interface _BMPAVPlayerItem : AVPlayerItem
- (void)addListener:(id<_BMPAVPlayerItemListener>)listener;
- (void)removeListener:(id<_BMPAVPlayerItemListener>)listener;

- (void)selectMediaOption:(nullable AVMediaSelectionOption *)mediaSelectionOption
    inMediaSelectionGroup:(AVMediaSelectionGroup *)mediaSelectionGroup
          notifyListeners:(BOOL)notifyListeners;
@end

NS_ASSUME_NONNULL_END
