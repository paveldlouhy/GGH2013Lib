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
        
        void Clear();
        
        void SetPos(float parX, float parY, float parZ);
        void SetSize(float parDX, float parDY);
        
        void SetX(float parX);
        void SetY(float parY);
        void SetZ(float parZ);
        void SetDX(float parDX);
        void SetDY(float parDY);
        void SetTextureID(int parTextureID);
        void SetColor(float parR, float parG, float parB, float parA);
        void SetEnabled(bool value);
        void SetRotation(float r);
        float GetX();
        float GetY();
        float GetZ();
        float GetDX();
        float GetDY();
        int GetTextureID();
        float GetRed();
        float GetGreen();
        float GetBlue();
        float GetAlpha();
        bool IsEnabled();
        float GetRotation();
        
        int GetSlot();
        
    private:
        CSpriteManager *owner;
        int slot;
        
        float x, y, z;
        float dx, dy;
        int textureID;
        float r, g, b, a;
        bool enabled;
        float rotation;
    };
    
    
} } // namespaces
