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
        x(0.), y(0.), z(0.)
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


} } // namespaces
