//
//  CSound.cpp
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#include "GGH2013LibConfig.h"


#include "CSound.h"


#include "MyOpenALSupport.h"


#include "COpenAL.h"


#include "CLog.h"


//additional info: http://benbritten.com/2008/11/06/openal-sound-on-the-iphone/
//hint: afconvert -f caff -d LEI16@44100 TCP02_10tunnels_121203.mp3 TCP02_10tunnels_121203.caf


#define kDefaultDistance 25.0


namespace ggh13lib { namespace oal {


    CSound::CSound(COpenAL *parOwner, int parChannel, CFURLRef fileURL) : owner(parOwner), channel(parChannel)
    {
        buffer = 0;
        data = NULL;
        source = 0;
        isPlaying = false;
        isLooping = false;
        volume = 1.0f;
        sourcePos.x = 0.;
        sourcePos.y = -70.;
        
        buffer = owner->GetBuffer(channel);
        source = owner->GetSource(channel);
        InitBuffer(fileURL);
        InitSource();
    }
    
    CSound::~CSound()
    {
        
    }
    
    void CSound::Play()
    {
        ALenum error;
        
        dbg::CLog log((char *)"Start!\n");
        // Begin playing our source file
        alSourcePlay(source);
        if((error = alGetError()) != AL_NO_ERROR) {
            dbg::CLog log(0);
            log.Log((char *)"error starting source: %x\n", error);
        } else {
            // Mark our state as playing (the view looks at this)
            isPlaying = true;
        }
    }
    
    void CSound::Stop()
    {
        ALenum error;
        
        dbg::CLog log((char *)"Stop!\n");
        // Begin playing our source file
        alSourceStop(source);
        if((error = alGetError()) != AL_NO_ERROR) {
            dbg::CLog log(0);
            log.Log((char *)"error stopping source: %x\n", error);
        } else {
            // Mark our state as playing (the view looks at this)
            isPlaying = false;
        }
    }
    
    void CSound::SetLooping(bool looping)
    {
        ALenum error;
        
        dbg::CLog log((char *)"Start!\n");
        // Begin playing our source file
        if (looping) {
            alSourcei(source, AL_LOOPING, AL_TRUE);
            isLooping = true;
        } else {
            alSourcei(source, AL_LOOPING, AL_FALSE);
            isLooping = false;
        }
        if((error = alGetError()) != AL_NO_ERROR) {
            dbg::CLog log(0);
            log.Log((char *)"error looping on source: %x\n", error);
        }
    }
    
    void CSound::SetVolume(float parVolume)
    {
        ALenum error;

        alSourcef(source, AL_GAIN, parVolume);
        volume = parVolume;
        
        if((error = alGetError()) != AL_NO_ERROR) {
            dbg::CLog log(0);
            log.Log((char *)"error set volume on source: %x\n", error);
        }
    }
    
    bool CSound::IsPlaying()
    {
        return isPlaying;
    }
    
    float CSound::GetVolume()
    {
        return volume;
    }
    
    void CSound::InitBuffer(CFURLRef fileURL)
    {
        ALenum  error = AL_NO_ERROR;
        ALenum  format;
        ALsizei size;
        ALsizei freq;
        
        if (fileURL)
        {
            data = MyGetOpenALAudioData(fileURL, &size, &format, &freq);
            
            if((error = alGetError()) != AL_NO_ERROR) {
                dbg::CLog log(0);
                log.Log((char *)"error loading sound: %x\n", error);
                //@#@ exit(1);
            }
            
            // use the static buffer data API
            alBufferDataStaticProc(buffer, format, data, size, freq);
            
            if((error = alGetError()) != AL_NO_ERROR) {
                dbg::CLog log(0);
                log.Log((char *)"error attaching audio to buffer: %x\n", error);
            }
        }
        else
            dbg::CLog log((char *)"Could not find file!\n");
    }
    
    
    void CSound::InitSource()
    {
        ALenum error = AL_NO_ERROR;
        alGetError(); // Clear the error
        
        // Turn Looping ON
        //alSourcei(source, AL_LOOPING, AL_TRUE);
        
        // Set Source Position
        float sourcePosAL[] = {sourcePos.x, kDefaultDistance, sourcePos.y};
        alSourcefv(source, AL_POSITION, sourcePosAL);
        
        // Set Source Reference Distance
        alSourcef(source, AL_REFERENCE_DISTANCE, 50.0f);
        
        // attach OpenAL Buffer to OpenAL Source
        alSourcei(source, AL_BUFFER, buffer);
        
        if((error = alGetError()) != AL_NO_ERROR) {
            dbg::CLog log(0);
            log.Log((char *)"Error attaching buffer to source: %x\n", error);
            //@#@ exit(1);
        }
    }
    

} } // namespaces
