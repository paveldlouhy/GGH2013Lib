//
//  CSpriteManager.h
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#define NUMSPRITESLOTS  8192


namespace ggh13lib { namespace spr {
    
    class CSprite;
    
    class CSpriteManager {
    public:
        CSpriteManager();
        ~CSpriteManager();

        CSprite *CreateSprite(int slot);
        void DestroySprite(CSprite *spr);
        
        int GetSpriteCount();
        CSprite *GetSprite(int slot);
        
    private:
        int spriteCount;
        CSprite *spriteSlots[NUMSPRITESLOTS];
    
    };

    
} } // namespaces