//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPSubtitleTrack.h>

@protocol _BMPCaptionHandler;

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
NS_SWIFT_NAME(_CaptionHandlerDelegate)
@protocol _BMPCaptionHandlerDelegate <NSObject>
/**
* Will be called before the selection of the subtitle is performed
*
* @note subtitleTrack will be nil if the active subtitle got deselected
* @note subtitleCues will be nil if an AVPlayer subtitle was selected or the active subtitle got deselected
*/
- (void)captionHandler:(id<_BMPCaptionHandler>)handler willSelectSubtitleTrack:(nullable BMPSubtitleTrack *)subtitleTrack withSubtitleCues:(nullable NSArray<BMPCue *> *)subtitleCues;
/**
 * Will be called when the selection of the subtitle finished
 *
 * @note subtitleTrack will be nil if the active subtitle got deselected
 * @note subtitleCues will be nil if an AVPlayer subtitle was selected or the active subtitle got deselected
 */
- (void)captionHandler:(id<_BMPCaptionHandler>)handler didSelectSubtitleTrack:(nullable BMPSubtitleTrack *)subtitleTrack withSubtitleCues:(nullable NSArray<BMPCue *> *)subtitleCues;
- (void)captionHandler:(id<_BMPCaptionHandler>)handler didAddSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack;
- (void)captionHandler:(id<_BMPCaptionHandler>)handler didRemoveSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack;
@end

NS_ASSUME_NONNULL_END
