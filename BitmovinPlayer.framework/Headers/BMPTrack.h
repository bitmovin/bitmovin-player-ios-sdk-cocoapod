//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPTrackType.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Track)
@interface BMPTrack : NSObject
@property (nonatomic, nullable, strong) NSURL *url;
@property (nonatomic, getter=isDefaultTrack) BOOL defaultTrack;
@property (nonatomic, nullable, strong) NSString *label;
@property (nonatomic, nullable, strong) NSString *identifier;
@property (nonatomic) BMPTrackType type;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)initWithTrackType:(BMPTrackType)trackType;

- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType;

- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType
                      label:(nullable NSString *)label
                 identifier:(nullable NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
