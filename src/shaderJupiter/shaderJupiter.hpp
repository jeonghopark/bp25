//
//  shaderJupiter.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderJupiter_hpp
#define shaderJupiter_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderJupiter : public baseScene{
  
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderJupiter;

    
};
#endif /* shaderJupiter_hpp */
