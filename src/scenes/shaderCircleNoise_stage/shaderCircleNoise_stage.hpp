//
//  shaderCircleNoise_stage.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once


#ifndef shaderCircleNoise_stage_hpp
#define shaderCircleNoise_stage_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderCircleNoise_stage : public baseScene{
  
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();

    
};




#endif /* shaderCircleNoise_stage_hpp */
