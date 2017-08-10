//
// Created by Mario Graf on 27/04/2017.
// Copyright (c) 2017 Bitmovin Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPPlayerListener.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Handles adding and removing of event listeners.
 */
NS_SWIFT_NAME(EventHandler)
@protocol BMPEventHandler <NSObject>
/**
 * Adds an event listener.
 *
 * @param listener The event listener to be added.
 */
- (void)addPlayerListener:(id<BMPPlayerListener>)listener;

/**
 * Removes an event listener.
 *
 * @param listener The event listener to be removed.
 */
- (void)removePlayerListener:(id<BMPPlayerListener>)listener;
@end

NS_ASSUME_NONNULL_END
