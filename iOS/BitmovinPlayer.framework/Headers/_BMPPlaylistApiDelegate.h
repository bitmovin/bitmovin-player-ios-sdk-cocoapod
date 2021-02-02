//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol BMPSource;

NS_SWIFT_NAME(_PlaylistApiDelegate)
@protocol _BMPPlaylistApiDelegate <NSObject>
@property (nonatomic, readonly) NSArray<id<BMPSource>> *playlistApi_sources;
- (void)playlistApi_seek:(id<BMPSource>)source time:(NSTimeInterval)time;
@end

NS_ASSUME_NONNULL_END
