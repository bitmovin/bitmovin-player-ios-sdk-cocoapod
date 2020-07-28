//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPTrackType.h>
#import <BitmovinPlayer/BMPTrack.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Describes a thumbnail track.
 */
NS_SWIFT_NAME(ThumbnailTrack)
@interface BMPThumbnailTrack : BMPTrack

/**
 Creates a new thumbnail track based on the given URL and provided metadata.

 @param url The URL to the timed file, i.e. WebVTT file.
 @param label The label for this track.
 @param identifier The unique identifier for this track.
 @param isDefaultTrack If set to YES, this track would be considered as default.
 @return A new BMPThumbnailTrack initialized with the given thumbnail URL and the provided metadata.
 */
- (instancetype)initWithUrl:(NSURL *)url
                      label:(NSString *)label
                 identifier:(NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_DESIGNATED_INITIALIZER;
/// :nodoc:
- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType
                      label:(NSString *)label
                 identifier:(NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
