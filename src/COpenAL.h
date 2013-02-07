//
//  COpenAL.h
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/6/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#import <OpenAL/al.h>
#import <OpenAL/alc.h>
#import <AudioToolbox/AudioToolbox.h>
#include "SInitData.h"


#define NUMBUFFERS  2
#define NUMSOURCES  2


namespace ggh13lib { namespace oal {
    
    class COpenAL {
    public:
        COpenAL();
        ~COpenAL();
        
        void Init(SInitData *initData);
        void Done();
        
        ALuint GetBuffer(int channel);
        ALuint GetSource(int channel);
                
    private:
        ALCdevice* device;
        ALCcontext*	context;

        //buffers
        ALuint buffers[NUMBUFFERS];
        ALuint sources[NUMSOURCES];        
    };
    
} } // namespaces
