//
//  CLog.h
//  GGH2013Lib
//
//  Created by Pavel Dlouhy on 1/31/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


namespace ggh13lib { namespace dbg {
    
    
    class CLog {
    public:
        CLog(char *msg);
        ~CLog();
        
        void Log(const char *fmt, ...);
    
    private:
        
    };
    
    
} } // namespaces
