//
//  CSprite.h
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


namespace ggh13lib { namespace spr {
    
    class CSpriteManager;
    
    class CSprite {
    public:
        CSprite(CSpriteManager *parOwner, int parSlot);
        ~CSprite();
        
        void SetPos(float parX, float parY, float parZ);
        
        void SetX(float parX);
        void SetY(float parY);
        void SetZ(float parZ);
        float GetX();
        float GetY();
        float GetZ();
        
        int GetSlot();
        
    private:
        CSpriteManager *owner;
        int slot;
        
        float x, y, z;
    };
    
    
} } // namespaces
