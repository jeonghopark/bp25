//
//  shaderWhitehole.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderWhitehole_hpp
#define shaderWhitehole_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderWhitehole : public baseScene{
  
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderWhitehole;

    
};

#endif /* shaderWhitehole_hpp */
