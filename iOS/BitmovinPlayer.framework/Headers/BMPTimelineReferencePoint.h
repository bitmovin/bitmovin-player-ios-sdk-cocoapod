//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Timeline reference point to calculate SourceConfigOptions.startOffset from.
 Default for live: TimelineReferencePoint.End Default for VOD: TimelineReferencePoint.Start.
 */
NS_SWIFT_NAME(TimelineReferencePoint)
typedef NS_ENUM(NSInteger, BMPTimelineReferencePoint) {
    /**
     Indicates a not provided reference point.
     We will detect the reference point regarding the type of the stream (VOD or Live).
     */
    BMPTimelineReferencePointAuto = 0,
    /**
     Relative offset will be calculated from the beginning of the stream or DVR window.
     */
    BMPTimelineReferencePointStart,
    /**
     Relative offset will be calculated from the end of the stream or the live edge in case of a live stream with DVR window.
     */
    BMPTimelineReferencePointEnd
};

NS_ASSUME_NONNULL_END
