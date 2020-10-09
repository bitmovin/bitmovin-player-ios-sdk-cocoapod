//
// Bitmovin Player iOS SDK
// Copyright (C) 2020, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <BitmovinPlayer/BitmovinPlayer.h>

NS_ASSUME_NONNULL_BEGIN
/// Used for internal time updates where we need a higher and not modifiable update rate
NS_SWIFT_NAME(_InternalTimeChangedEvent)
@interface _BMPInternalTimeChangedEvent : BMPTimeChangedEvent

@end

NS_ASSUME_NONNULL_END
