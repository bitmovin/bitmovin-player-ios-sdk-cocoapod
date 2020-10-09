//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BitmovinPlayer.h>

@class BMPScteTagInfo;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_ScteTagsParsedEvent)
@interface _BMPScteTagsParsedEvent : BMPPlayerEvent

@property (strong, nonatomic, readonly) NSArray<BMPScteTagInfo *> *scteTags;

/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)initWithScteTags:(NSArray<BMPScteTagInfo *> *)scteTags NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
