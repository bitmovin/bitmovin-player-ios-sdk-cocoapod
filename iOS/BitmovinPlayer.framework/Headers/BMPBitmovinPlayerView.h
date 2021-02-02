//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#ifndef BMPBitmovinPlayerView_h
#define BMPBitmovinPlayerView_h

#import <UIKit/UIKit.h>
#import <BitmovinPlayer/BMPPlayer.h>
#import <BitmovinPlayer/BMPPlayerView.h>
#import <BitmovinPlayer/BMPFullscreenHandler.h>
#import <BitmovinPlayer/BMPUserInterfaceAPI.h>
#import <BitmovinPlayer/BMPUserInterfaceEventHandler.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A view containing a BMPPlayer which can be added to the view hierarchy of your view controller. This view
 * needs a BMPPlayer instance to work properly. This instance can be passed to the initializer, or using the
 * according property if the view is created using the interface builder.
 * @Note If you are composing the view via the interface builder make sure you use the obj-c class name "BMPBitmovinPlayerView"
 */
NS_SWIFT_NAME(BitmovinPlayerView)
@interface BMPBitmovinPlayerView : BMPPlayerView <BMPUserInterfaceAPI, BMPUserInterfaceEventHandler>
/**
 * Get/set a fullscreen handler for this BMPBitmovinPlayerView. See the documentation of the BMPFullscreenHandler for
 * more information.
 */
@property (nonatomic, weak) id<BMPFullscreenHandler> fullscreenHandler;
- (void)willRotate;
- (void)didRotate;
@end

NS_ASSUME_NONNULL_END

#endif /* BMPBitmovinPlayerView_h */
