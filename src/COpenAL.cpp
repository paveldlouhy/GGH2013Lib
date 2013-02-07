//
//  COpenAL.cpp
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/6/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#include "GGH2013LibConfig.h"


#include "COpenAL.h"


#include "CLog.h"
#include <assert.h>


//additional info: http://benbritten.com/2008/11/06/openal-sound-on-the-iphone/
//hint: afconvert -f caff -d LEI16@44100 TCP02_10tunnels_121203.mp3 TCP02_10tunnels_121203.caf


namespace ggh13lib { namespace oal {
    
    
    COpenAL::COpenAL()
    {
        device = NULL;
        context = NULL;

        for (int i = 0; i < NUMBUFFERS; i++) {
            buffers[i] = 0;
        }
        for (int i = 0; i < NUMSOURCES; i++) {
            sources[i] = 0;
        }
    }
    
    COpenAL::~COpenAL()
    {
        
    }
        
    void COpenAL::Init(SInitData *initData)
    {
        ALenum			error;
        
        // Create a new OpenAL Device
        // Pass NULL to specify the system’s default output device
        device = alcOpenDevice(NULL);
        if (device != NULL)
        {
            // Create a new OpenAL Context
            // The new context will render to the OpenAL Device just created
            context = alcCreateContext(device, 0);
            if (context != NULL)
            {
                // Make the new context the Current OpenAL Context
                alcMakeContextCurrent(context);
                
                // Create some OpenAL Buffer Objects
                alGenBuffers(NUMBUFFERS, buffers);
                if((error = alGetError()) != AL_NO_ERROR) {
                    dbg::CLog log(0);
                    log.Log((char *)"Error Generating Buffers: %x\n", error);
                    //exit(1);
                }
                
                // Create some OpenAL Source Objects
                alGenSources(NUMSOURCES, sources);
                if(alGetError() != AL_NO_ERROR)
                {
                    dbg::CLog log(0);
                    log.Log((char *)"Error generating sources! %x\n", error);
                    //exit(1);
                }
            }
        }
        // clear any errors
        alGetError();        
    }
    
    void COpenAL::Done()
    {
        // Delete the Sources
        alDeleteSources(NUMSOURCES, sources);
        // Delete the Buffers
        alDeleteBuffers(NUMBUFFERS, buffers);
        
        //Release context
        alcDestroyContext(context);
        //Close device
        alcCloseDevice(device);
    }

    ALuint COpenAL::GetBuffer(int channel)
    {
        assert(channel < NUMBUFFERS);
        return buffers[channel];
    }
    
    ALuint COpenAL::GetSource(int channel)
    {
        assert(channel < NUMSOURCES);
        return sources[channel];
    }
    
    
} } // namespaces
