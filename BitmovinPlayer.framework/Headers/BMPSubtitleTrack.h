//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPTrack.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SubtitleTrack)
@interface BMPSubtitleTrack : BMPTrack <BMPJsonable>
@property (nonatomic, nullable, strong) NSString *language;
- (instancetype)initWithTrackType:(BMPTrackType)trackType NS_UNAVAILABLE;

- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType NS_UNAVAILABLE;

- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType
                      label:(nullable NSString *)label
                 identifier:(nullable NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_UNAVAILABLE;


- (instancetype)init;
- (instancetype)initWithUrl:(nullable NSURL *)url;

- (instancetype)initWithUrl:(nullable NSURL *)url
                      label:(nullable NSString *)label
                 identifier:(nullable NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack
                   language:(nullable NSString *)language NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
