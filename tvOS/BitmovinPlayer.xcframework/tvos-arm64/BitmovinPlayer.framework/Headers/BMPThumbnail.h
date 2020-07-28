//
// Bitmovin Player iOS SDK
// Copyright (C) 2018, Bitmovin GmbH, All Rights Reserved
//
// This source code and its use and distribution, is subject to the terms
// and conditions of the applicable license agreement.
//

#import <Foundation/Foundation.h>
#import <BitmovinPlayer/BMPJsonable.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Represents a VTT thumbnail.
 */
NS_SWIFT_NAME(Thumbnail)
@interface BMPThumbnail : NSObject <BMPJsonable>
/** The start time of the entry */
@property (nonatomic, readonly) NSTimeInterval start;
/** The end time of the entry */
@property (nonatomic, readonly) NSTimeInterval end;
/** The raw cue data of the entry */
@property (nonatomic, readonly, copy) NSString *text;
/** The URL of the spritesheet */
@property (nonatomic, readonly, copy) NSURL *url;
/** The horizontal offset of the thumbnail in its spritesheet */
@property (nonatomic, readonly) NSUInteger x;
/** The vertical offset of the thumbnail in its spritesheet */
@property (nonatomic, readonly) NSUInteger y;
/** The width of the thumbnail */
@property (nonatomic, readonly) NSUInteger width;
/** The height of the thumbnail */
@property (nonatomic, readonly) NSUInteger height;
/// :nodoc:
- (instancetype)init NS_UNAVAILABLE;
/// :nodoc:
+ (instancetype)new NS_UNAVAILABLE;
/**
 Creates a new Thumbnail based on the given spritesheet URL and position in combination with start and end time.
 The offsets x and y represent the position of the thumbnail in the given spritesheet.

 @param start The start time of this thumbnail.
 @param end The end time of this thumbnail.
 @param text The raw cue data of this thumbnail.
 @param url The spritesheet's URL.
 @param x The horizontal offset of this thumbnail in its spritesheet.
 @param y The vertical offset of this thumbnail in its spritesheet.
 @param width The actual width of this thumbnail.
 @param height The actual height of this thumbnail.
 @return A new instance of BMPThumbnail initialized with the given properties.
 */
- (instancetype)initWithStart:(NSTimeInterval)start end:(NSTimeInterval)end text:(NSString *)text url:(NSURL *)url x:(NSUInteger)x y:(NSUInteger)y width:(NSUInteger)width height:(NSUInteger)height NS_DESIGNATED_INITIALIZER;
@end

NS_ASSUME_NONNULL_END
