//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BMPOfflineTrack.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(OfflineTextTrack)
@interface BMPOfflineTextTrack : BMPOfflineTrack
@property (nonatomic, copy, readonly) NSString *label;
@property (nonatomic, copy, readonly, nullable) NSString *language;
@property (nonatomic, readonly) BOOL isForced;
@property (nonatomic, readonly) BOOL isDefault;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
