//
//  shaderShape.hpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//
#pragma once


#ifndef shaderShape_hpp
#define shaderShape_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderShape : public baseScene{
  
    
public:
    
    void setup();
    void update();
    void draw();
    void updateShader();
    
    
    ofShader shaderNoise;
        
};



#endif /* shaderShape_hpp */
