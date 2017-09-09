//
//  shaderBasic.hpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//
#pragma once


#ifndef shaderBasic_hpp
#define shaderBasic_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderBasic : public baseScene{
    
    
public:
    
    void setup();
    void update();
    void draw();
    void updateShader();

    
    ofShader shaderNoise;
    
    
};


#endif /* shaderBasic_hpp */
