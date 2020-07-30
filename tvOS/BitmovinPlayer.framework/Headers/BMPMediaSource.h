//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPMediaSourceType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Base class for all media sources.

 @note This class acts as an abstract class.
 */
NS_SWIFT_NAME(MediaSource)
@interface BMPMediaSource : NSObject <NSCopying>

/** The media source type. Possible values are defined in BMPMediaSourceType.h. */
@property (nonatomic) BMPMediaSourceType type;
/** The URL of the media source. */
@property (nonatomic, nonnull, strong) NSURL *url;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/// :nodoc:
- (instancetype)initWithType:(BMPMediaSourceType)mediaSourceType url:(NSURL *)url NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
