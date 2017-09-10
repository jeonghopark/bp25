//
//  shaderWater.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderWater_hpp
#define shaderWater_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderWater : public baseScene{
  
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderWater;

    
};



#endif /* shaderWater_hpp */
