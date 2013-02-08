//
//  CSprite.cpp
//  GGH2013Lib-test
//
//  Created by Pavel Dlouhy on 2/7/13.
//  Copyright (c) 2013 Pavel Dlouhy. All rights reserved.
//


#include "GGH2013LibConfig.h"


#include "CSprite.h"


namespace ggh13lib { namespace spr {


    CSprite::CSprite(CSpriteManager *parOwner, int parSlot) : owner(parOwner), slot(parSlot),
        x(0.), y(0.), z(0.), dx(16.), dy(16.), textureID(0), r(1.), g(1.), b(1.), a(1.)
    {
        
    }

    CSprite::~CSprite()
    {
        
    }
    
    int CSprite::GetSlot()
    {
        return slot;
    }
    
    void CSprite::SetPos(float parX, float parY, float parZ)
    {
        x = parX;
        y = parY;
        z = parZ;
    }
    
    void CSprite::SetSize(float parDX, float parDY)
    {
        dx = parDX;
        dy = parDY;
    }
    
    void CSprite::SetX(float parX)
    {
        x = parX;
    }
    
    void CSprite::SetY(float parY)
    {
        y = parY;
    }
    
    void CSprite::SetZ(float parZ)
    {
        z = parZ;
    }
    
    void CSprite::SetDX(float parDX)
    {
        dx = parDX;
    }
    
    void CSprite::SetDY(float parDY)
    {
        dy = parDY;
    }
    
    void CSprite::SetTextureID(int parTextureID)
    {
        textureID = parTextureID;
    }
    
    void CSprite::SetColor(float parR, float parG, float parB, float parA)
    {
        r = parR;
        g = parG;
        b = parB;
        a = parA;
    }
    
    float CSprite::GetX()
    {
        return x;
    }
    
    float CSprite::GetY()
    {
        return y;
    }
    
    float CSprite::GetZ()
    {
        return z;
    }
    
    float CSprite::GetDX()
    {
        return dx;
    }
    
    float CSprite::GetDY()
    {
        return dy;
    }
    
    int CSprite::GetTextureID()
    {
        return textureID;
    }
    
    float CSprite::GetRed()
    {
        return r;
    }
    
    float CSprite::GetGreen()
    {
        return g;
    }

    float CSprite::GetBlue()
    {
        return b;
    }
    
    float CSprite::GetAlpha()
    {
        return a;
    }


} } // namespaces
