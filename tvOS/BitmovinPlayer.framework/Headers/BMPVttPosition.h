//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPVttPositionValueType.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMPVttPosition : NSObject
/**
 Defines whether the value is not present, set to auto or to an actual numeric value.

 Default: BMPVttPositionValueTypeAuto
*/
@property (nonatomic) BMPVttPositionValueType type;
/**
 The actual value for the position property.

 @note When type is set to BMPVttPositionValueTypeAuto the value should be ignored.
*/
@property (nonatomic) double value;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
