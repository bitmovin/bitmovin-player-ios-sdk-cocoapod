//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPSubtitleTrack.h>
#import <BitmovinPlayer/BMPSourceItem.h>
#import "_BMPCaptionHandlerDelegate.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_CaptionHandler)
@protocol _BMPCaptionHandler <NSObject>
@property (nonatomic, strong, readonly) NSArray<BMPSubtitleTrack *> *availableSubtitleTracks;
@property (nonatomic, weak, nullable) id<_BMPCaptionHandlerDelegate> delegate;
@property (nonatomic, strong, readonly, nullable) BMPSubtitleTrack *activeSubtitleTrack;
@property (nonatomic, strong, readonly, nullable) BMPSubtitleTrack *defaultSubtitleTrack;
- (void)initializeSubtitleTracksWithSourceItem:(BMPSourceItem *)sourceItem;
/**
 @note no-op when the passed subtitle is already active
 */
- (void)enableSubtitleTrackById:(nullable NSString *)subtitleTrackId;
/**
 @note no-op when no subtitle is currently active
 */
- (void)disableActiveSubtitleTrack;
- (void)addSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack NS_SWIFT_NAME(add(subtitleTrack:));
- (void)removeSubtitleTrackById:(NSString *)subtitleTrackId;
- (BOOL)containsSubtitleTrack:(BMPSubtitleTrack *)subtitleTrack NS_SWIFT_NAME(contains(subtitleTrack:));
- (void)clearSubtitleTracks;
- (nullable BMPSubtitleTrack *)forcedSubtitleTrackForLanguage:(NSString *)language;
@end

NS_ASSUME_NONNULL_END
