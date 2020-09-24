//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerEventHandler.h>
#import "_BMPPlayerListenerInternal.h"
@protocol _BMPService;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(_EventEmitter)
@protocol _BMPEventEmitter <BMPPlayerEventHandler, BMPPlayerListener, _BMPPlayerListenerInternal, _BMPService>
@end

NS_ASSUME_NONNULL_END