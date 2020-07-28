//
// Bitmovin Player iOS SDK
// Copyright (C) 2019, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>

/**
 Identifier for various attributes which are supported in `BMPSourceItem#metadata` dictionary
 */

/**
 Identifier for an artwork which will be visible in the iOS system setting 'Review Downloaded Videos'.
 The type of the value must be `NSData`.
 */
FOUNDATION_EXPORT NSString *const BMPMetadataIdentifierArtwork NS_SWIFT_NAME(MetadataIdentifierArtwork);
/**
 Identifier for navigation markers on tvOS which will be passed to `AVPlayerItem.navigationMarkerGroups`.
 The type of the value must be `NSArray<AVNavigationMarkersGroup>`.
 */
FOUNDATION_EXPORT NSString *const BMPMetadataIdentifierNavigationMarker NS_SWIFT_NAME(MetadataIdentifierNavigationMarker);

