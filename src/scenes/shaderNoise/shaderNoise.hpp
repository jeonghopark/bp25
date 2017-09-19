//
//  shaderNoise.hpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//
#pragma once


#ifndef shaderNoise_hpp
#define shaderNoise_hpp

#include "ofMain.h"
#include "baseScene.hpp"

//#include "fftInput.hpp"


class shaderNoise : public baseScene{
    
    
public:
    
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();
    
//    fftInput FF;
    
};


#endif /* shaderNoise_hpp */

