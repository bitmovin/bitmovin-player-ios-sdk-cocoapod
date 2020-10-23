//
//  NSString+m3u8.h
//  M3U8Kit
//
//  Created by Oneday on 13-1-11.
//  Copyright (c) 2013年 0day. All rights reserved.
//

#import <Foundation/Foundation.h>

@class _M3U8ExtXStreamInfList, M3U8SegmentInfoList;
@interface NSString (m3u8)

- (BOOL)_isExtendedM3Ufile;
- (BOOL)_isMasterPlaylist;
- (BOOL)_isMediaPlaylist;

@end
