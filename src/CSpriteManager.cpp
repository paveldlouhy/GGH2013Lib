//
//  CSpriteManager.cpp
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#include "GGH2013LibConfig.h"


#include "CSpriteManager.h"
#include "CSprite.h"


#include <assert.h>


namespace ggh13lib { namespace spr {


    CSpriteManager::CSpriteManager()
    {
        spriteCount = 0;
        for (int i = 0; i < NUMSPRITESLOTS; i++) {
            spriteSlots[i] = 0;
        }
    }

    CSpriteManager::~CSpriteManager()
    {
        
    }
    
    CSprite *CSpriteManager::CreateSprite(int slot)
    {
        assert(slot > 0);
        assert(slot <= NUMSPRITESLOTS);
        spriteCount = slot;
        spriteSlots[slot] = new CSprite(this, slot);
        return spriteSlots[slot];
    }
    
    void CSpriteManager::DestroySprite(CSprite *spr)
    {
        if (spr) {
            int slot = spr->GetSlot();
            assert(slot > 0);
            assert(slot <= NUMSPRITESLOTS);
            assert(spriteSlots[slot]);
            delete spriteSlots[slot];
        }
    }
    
    int CSpriteManager::GetSpriteCount()
    {
        return spriteCount;
    }
    
    CSprite *CSpriteManager::GetSprite(int slot)
    {
        assert(slot > 0);
        assert(slot <= NUMSPRITESLOTS);
        return spriteSlots[slot];
    }


} } // namespaces