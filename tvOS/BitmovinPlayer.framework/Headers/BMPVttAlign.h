//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/// Defines the text alignment in a cue box
typedef NSString * BMPVttAlign NS_TYPED_ENUM NS_SWIFT_NAME(VttAlign);
static BMPVttAlign const BMPVttAlignStart = @"start";
static BMPVttAlign const BMPVttAlignCenter = @"center";
static BMPVttAlign const BMPVttAlignEnd = @"end";
static BMPVttAlign const BMPVttAlignLeft = @"left";
static BMPVttAlign const BMPVttAlignRight = @"right";
