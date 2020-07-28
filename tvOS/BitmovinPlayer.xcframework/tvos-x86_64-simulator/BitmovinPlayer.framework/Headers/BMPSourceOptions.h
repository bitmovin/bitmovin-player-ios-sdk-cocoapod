//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPJsonable.h>
#import <BitmovinPlayer/BMPTimelineReferencePoint.h>

NS_ASSUME_NONNULL_BEGIN
NS_SWIFT_NAME(SourceOptions)
@interface BMPSourceOptions : NSObject <NSCopying, BMPJsonable>
/**
 The position where the stream should be started. Number can be positive or negative depending on the used TimelineReferencePoint.
 Invalid numbers will be corrected according to the stream boundaries.
 For VOD this is applied at the time the stream is loaded, for LIVE when the playback starts.

 Default: NAN
 */
@property (nonatomic) NSTimeInterval startOffset;
/**
 Timeline reference point to calculate BMPSourceOptions.startOffset from.

 Default for live: BMPTimelineReferencePointEnd
 Default for VOD: BMPTimelineReferencePointStart
 */
@property (nonatomic) BMPTimelineReferencePoint startOffsetTimelineReference;

- (instancetype)initWithStartOffset:(NSTimeInterval)startOffset
  startOffsetTimelineReferencePoint:(BMPTimelineReferencePoint)startOffsetTimelineReference NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
