//
//  shaderSun.hpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//
#pragma once


#ifndef shaderSun_hpp
#define shaderSun_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderSun : public baseScene{
  
    
public:
    
    void setup();
    void update();
    void draw();
    void updateShader();
    
    
    ofShader shaderSun;
        
};



#endif /* shaderSun_hpp */
