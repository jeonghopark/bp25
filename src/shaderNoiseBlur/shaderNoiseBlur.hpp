//
//  shaderNoiseBlur.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once


#ifndef shaderNoiseBlur_hpp
#define shaderNoiseBlur_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderNoiseBlur : public baseScene{
  
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderNoiseBlur;

    
};

#endif /* shaderNoiseBlur_hpp */
