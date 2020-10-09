//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BitmovinPlayer.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_VariantPlaylistLoadedEvent)
@interface _BMPVariantPlaylistLoadedEvent : BMPPlayerEvent

/**
 * Raw representation of the variant playlist.
 */
@property (strong, nonatomic, readonly) NSData *data;
/**
 * URL for which the load request has been made.
 */
@property (strong, nonatomic, readonly) NSURL *url;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithData:(NSData *)data requestURL:(NSURL *)url NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
