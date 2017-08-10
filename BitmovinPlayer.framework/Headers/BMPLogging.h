//
// Created by Mario Graf on 29/06/2017.
// Copyright (c) 2017 Bitmovin Inc. All rights reserved.
//

#ifdef DEBUG
#define BMPLog( s, ... ) NSLog( @"<%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] )
#else
#define BMPLog( s, ... )
#endif
