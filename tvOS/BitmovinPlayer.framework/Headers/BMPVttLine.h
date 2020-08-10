//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPVttLineValueType.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMPVttLine : NSObject
/**
 Defines whether the value is not present, set to auto or to an actual numeric value.

 Default: BMPVttLineValueTypeAuto
 */
@property (nonatomic) BMPVttLineValueType type;
/**
 The actual value for the line property.

 @note When type is set to BMPVttLineValueTypeAuto the value should be ignored.
 */
@property (nonatomic) double value;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
