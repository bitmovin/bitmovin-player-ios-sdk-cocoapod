//
// Bitmovin Player iOS SDK
// Copyright (C) 2017, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPConfiguration.h>
#import <BitmovinPlayer/BMPUserInterfaceType.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Contains configuration values which can be used to alter the visual presentation and behaviour of the player UI.
 */
NS_SWIFT_NAME(StyleConfiguration)
@interface BMPStyleConfiguration : BMPConfiguration
/**
 * Sets if the the UI should be enabled or not. Default value is YES.
 */
@property (nonatomic, getter=isUiEnabled) BOOL uiEnabled;
/**
 * Set which user interface type should be used. Default value is BMPUserInterfaceTypeBitmovin on iOS and
 * BMPUserInterfaceTypeSystem on tvOS. This setting only applies if BMPStyleConfiguration#uiEnabled is set to YES.
 */
@property (nonatomic) BMPUserInterfaceType userInterfaceType;
/**
 * Set the CSS file that will be used for the UI. The default CSS file will be completely replaced by the CSS file
 * set with this property.
 */
@property (nonatomic, copy) NSURL *playerUiCss;
/**
 * Set a CSS file which contains supplemental styles for the player UI. These styles will be added to the default CSS
 * file or the CSS file set with BMPStyleConfiguration#playerUiCss.
 */
@property (nonatomic, copy, nullable) NSURL *supplementalPlayerUiCss;
/**
 * Sets the JS file that will be used for the UI. The default JS file will be completely replaced by the JS file
 * set with this property.
 */
@property (nonatomic, copy) NSURL *playerUiJs;
@end

NS_ASSUME_NONNULL_END
