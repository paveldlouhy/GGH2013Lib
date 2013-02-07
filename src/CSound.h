//
//  CSound.h
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#import <OpenAL/al.h>
#import <AudioToolbox/AudioToolbox.h>


namespace ggh13lib { namespace oal {
    
    class COpenAL;
    
    struct MyPoint {
        float x;
        float y;
    };
    
    class CSound {
    public://methods
        CSound(COpenAL *parOwner, int parChannel, CFURLRef fileURL);
        ~CSound();
        
        void Play();
        void SetLooping(bool looping);
        
    private://methods
        void InitBuffer(CFURLRef fileURL);
        void InitSource();

    private://data
        COpenAL *owner;
        int channel;
        
        ALuint buffer;
        void* data;
        ALuint source;
        bool isPlaying;
        bool isLooping;
        
        MyPoint sourcePos;
    };

} } // namespaces
