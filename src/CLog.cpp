//
//  CLog.cpp
//  GGH2013Lib
//
//  Created by Pavel Dlouhy on 1/31/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#include "GGH2013LibConfig.h"


#include "CLog.h"


#include <stdarg.h>
#include <stdio.h>


namespace ggh13lib { namespace dbg {
    
    
    CLog::CLog(char *msg)
    {
        if (msg) {
            fprintf(stderr, "%s", msg);
        }
    }
    
    CLog::~CLog()
    {
        
    }
    
    void CLog::Log(const char *fmt, ...)
    {
#ifndef GGH13LIB_FINAL
        char str[1024];
        va_list args;
        va_start(args, fmt);
        vsprintf(str, fmt, args);
        va_end(args);
#ifdef GGH13LIB_WINDOWS
        OutputDebugString(str);
#elif defined GGH13LIB_IOS
        fprintf(stderr, "%s", str);
#else
        ?
#endif // platform
#endif // GGH13LIB_FINAL
    }
    
    
} } // namespaces
