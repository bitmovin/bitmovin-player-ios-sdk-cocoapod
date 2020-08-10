//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 Defines the alignment of the line property.

 @discussion: A line value of 0 with a line-align of BMPVttLineAlignStart would mean that the cue box should be displayed on top,
             a line-align BMPVttLineAlignEnd would mean that it should be on the bottom.
 */
typedef NSString * BMPVttLineAlign NS_TYPED_ENUM NS_SWIFT_NAME(VttLineAlign);
static BMPVttLineAlign const BMPVttLineAlignStart = @"start";
static BMPVttLineAlign const BMPVttLineAlignCenter = @"center";
static BMPVttLineAlign const BMPVttLineAlignEnd = @"end";
