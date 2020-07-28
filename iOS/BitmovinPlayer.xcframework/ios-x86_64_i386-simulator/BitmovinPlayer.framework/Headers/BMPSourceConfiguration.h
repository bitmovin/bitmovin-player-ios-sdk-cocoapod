//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlaybackType.h>
#import <BitmovinPlayer/BMPSourceItem.h>
#import <BitmovinPlayer/BMPConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Contains configuration values regarding the media which should be played by the player.
 */
NS_SWIFT_NAME(SourceConfiguration)
@interface BMPSourceConfiguration : BMPConfiguration
/** The playback type of the source configuration. Possible values are defined in BMPPlaybackType.h. */
@property (nonatomic) BMPPlaybackType playbackType;
/** Indicates whether to repeat all sources after being played. */
@property (nonatomic) BOOL repeatAll;
/** The first source item to be played. */
@property (nonatomic, strong, nullable, readonly) BMPSourceItem *firstSourceItem;
/**
 Adds a new source item based on the provided URL string.

 @param urlString The URL to a DASH, HLS or Progressive MP4 source which is used to create a new source item to be added.
 @return YES if the source item was added correctly, NO otherwise.
 */
- (BOOL)addSourceItemWithString:(NSString *)urlString error:(NSError **)error NS_SWIFT_NAME(addSourceItem(urlString:));
/**
 Adds a new source item based on the provided URL.

 @param url The URL to a DASH, HLS or Progressive MP4 source which is used to create a new SourceItem to be added.
 @return YES if the source item was added correctly, NO otherwise.
 */
- (BOOL)addSourceItemWithUrl:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(addSourceItem(url:));
/**
 Adds a new source item.

 @param sourceItem The source item to be added.
 */
- (void)addSourceItem:(BMPSourceItem *)sourceItem NS_SWIFT_NAME(addSourceItem(item:));
@end

NS_ASSUME_NONNULL_END
