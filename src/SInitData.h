//
//  SInitData.h
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#import <AudioToolbox/AudioToolbox.h>

#ifndef __SINITDATA_H__
#define __SINITDATA_H__

struct SInitData {
    int soundFileURLCount;
    CFURLRef soundFileURLs[10];
};

#endif // !__SINITDATA_H__
