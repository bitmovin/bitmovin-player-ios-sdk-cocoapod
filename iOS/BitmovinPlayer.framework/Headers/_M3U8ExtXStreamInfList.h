//
//  _M3U8ExtXStreamInfList.h
//  ILSLoader
//
//  Created by Jin Sun on 13-4-15.
//  Copyright (c) 2013年 iLegendSoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "_M3U8ExtXStreamInf.h"

@interface _M3U8ExtXStreamInfList : NSObject

@property (nonatomic, assign ,readonly) NSUInteger count;

- (void)addExtXStreamInf:(_M3U8ExtXStreamInf *)extStreamInf;
- (_M3U8ExtXStreamInf *)xStreamInfAtIndex:(NSUInteger)index;
- (_M3U8ExtXStreamInf *)firstStreamInf;
- (_M3U8ExtXStreamInf *)lastXStreamInf;

- (void)sortByBandwidthInOrder:(NSComparisonResult)order;

// BITMOVIN CHANGES START
- (NSArray<_M3U8ExtXStreamInf *> *)toArray;
// BITMOVIN CHANGES END

@end
