//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPVttVertical.h>
#import <BitmovinPlayer/BMPVttLineAlign.h>
#import <BitmovinPlayer/BMPVttPositionAlign.h>
#import <BitmovinPlayer/BMPVttAlign.h>
#import <BitmovinPlayer/BMPVttLine.h>
#import <BitmovinPlayer/BMPVttPosition.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(VttProperties)
@interface BMPVttProperties : NSObject
/**
 Returns the writing direction

 @note: BMPVttVerticalUnset means the writing direction should be horizontal

 Default: BMPVttVerticalUnset
 */
@property (nonatomic, readonly) BMPVttVertical vertical;
/**
 Returns the vertical position of the cue box
 */
@property (nonatomic, readonly) BMPVttLine *line;
/**
 Returns the alignment of the line property.

 @discussion: See BMPVttLineAlign for more information
 */
@property (nonatomic, readonly) BMPVttLineAlign lineAlign;
/**
 Returns whether the line attribute should be interpreted as absolute line number or as relative position
 */
@property (nonatomic, readonly) BOOL snapToLines;
/**
 Returns the size of the cue box relative to the video dimensions

 Default: 100

 @note: If the writing direction is horizontal, then the size percentages are relative to the width of the video, otherwise to the height of the video
 */
@property (nonatomic, readonly) double size;
/**
 Returns the text alignment inside the cue box
 */
@property (nonatomic, readonly) BMPVttAlign align;
/**
 Returns the horizontal position of the cue box
 */
@property (nonatomic, readonly) BMPVttPosition *position;
/**
 Returns the alignment of the line property.

 Default: BMPVttPositionAlignAuto

 @discussion: See BMPVttPositionAlign for more information
 */
@property (nonatomic, readonly) BMPVttPositionAlign positionAlign;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
