//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

/// :nodoc:
@interface AVMediaSelectionOption (BitmovinPlayer)
@property (nonatomic, copy, readonly) NSString *_bmp_displayName;
@property (nonatomic, readonly) BOOL _bmp_isForced;
@property (nonatomic, readonly, nullable) NSString *_bmp_identifier;
@end

NS_ASSUME_NONNULL_END
