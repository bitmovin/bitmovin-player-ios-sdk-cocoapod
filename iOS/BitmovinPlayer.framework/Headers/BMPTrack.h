//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPTrackType.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for all available tracks.

 @note This class acts as an abstract class.
 */
NS_SWIFT_NAME(Track)
@interface BMPTrack : NSObject <NSCopying, BMPJsonable>
/** The URL to the timed file, e.g. WebVTT file. */
@property (nonatomic, nullable, copy, readonly) NSURL *url;
/** If set to YES, this track would be considered as default. */
@property (nonatomic, getter=isDefaultTrack, readonly) BOOL defaultTrack;
/** The label for this track. */
@property (nonatomic, copy, readonly) NSString *label;
/** The unique identifier for this track. */
@property (nonatomic, copy, readonly) NSString *identifier;

@property (nonatomic, readonly) BMPTrackType type;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithUrl:(nullable NSURL *)url
                  trackType:(BMPTrackType)trackType
                      label:(NSString *)label
                 identifier:(NSString *)identifier
             isDefaultTrack:(BOOL)isDefaultTrack NS_DESIGNATED_INITIALIZER;
/// :nodoc:
- (void)_updateLabelTo:(NSString *)label;
/// :nodoc:
- (void)_updateDefaultTrackTo:(BOOL)isDefaultTrack;
@end

NS_ASSUME_NONNULL_END
