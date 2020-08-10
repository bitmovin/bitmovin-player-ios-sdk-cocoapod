//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 Defines the alignment of the position property.

 @discussion: A position value of 0 with a position-align of BMPVttPositionAlignLineLeft would mean that the cue box should be displayed on the left,
             a position-align BMPVttPositionAlignLineRight would mean that it should be on the right.
*/
typedef NSString * BMPVttPositionAlign NS_TYPED_ENUM NS_SWIFT_NAME(VttPositionAlign);
static BMPVttPositionAlign const BMPVttPositionAlignLineLeft = @"line-left";
static BMPVttPositionAlign const BMPVttPositionAlignCenter = @"center";
static BMPVttPositionAlign const BMPVttPositionAlignLineRight = @"line-right";
static BMPVttPositionAlign const BMPVttPositionAlignAuto = @"auto";
