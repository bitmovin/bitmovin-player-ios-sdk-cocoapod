//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPTrack.h>
#import <BitmovinPlayer/BMPSubtitleTrackController.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Describes a subtitle track.
 */
NS_SWIFT_NAME(SubtitleTrack)
@interface BMPSubtitleTrack : BMPTrack
/** The IETF BCP 47 language tag associated with the subtitle track. */
@property (nonatomic, nullable, copy, readonly) NSString *language;
/** The subtitle track controller for this track. */
@property (nonatomic, nonnull, strong, readonly) id<BMPSubtitleTrackController> controller;
/**
 Creates a new subtitle track based on the given URL and provided metadata.

 @param url The URL to the timed file, e.g. WebVTT file.
 @param label The label for this track.
 @param identifier The unique identifier for this track.
 @param isDefaultTrack If set to YES, this track would be considered as default.
 @param language The IETF BCP 47 language tag associated with this track
 @return A new subtitle track initialized with the given subtitle URL and the provided metadata.
 */
- (instancetype)initWithUrl:(nullable NSURL *)url
                      label:(NSString *)label
                 identifier:(NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack
                   language:(nullable NSString *)language NS_DESIGNATED_INITIALIZER;

/// :nodoc:
- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType
                      label:(NSString *)label
                 identifier:(NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
