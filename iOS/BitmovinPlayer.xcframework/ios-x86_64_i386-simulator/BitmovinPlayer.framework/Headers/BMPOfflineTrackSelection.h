//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPOfflineTrack.h>
#import <BitmovinPlayer/BMPOfflineTextTrack.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(OfflineTrackSelection)
@interface BMPOfflineTrackSelection : NSObject
@property (strong, nonatomic, readonly) NSArray<BMPOfflineTextTrack *> *textTracks;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
