//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import "_BMPService.h"
#import <BitmovinPlayer/BMPAudioTrack.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_AudioService)
@protocol _BMPAudioService <_BMPService>
@property (nonatomic, readonly) NSArray<BMPAudioTrack *> *availableAudio;
@property (nonatomic, readonly, nullable) BMPAudioTrack *audio;

- (void)setAudioWithIdentifier:(NSString *)audioTrackID;
@end

NS_ASSUME_NONNULL_END
