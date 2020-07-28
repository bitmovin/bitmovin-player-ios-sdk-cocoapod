//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPOfflineTrackAction.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(OfflineTrack)
@interface BMPOfflineTrack : NSObject
@property (nonatomic) BMPOfflineTrackAction action;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
