//
//  shaderVertical.hpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//
#pragma once

#ifndef shaderVertical_hpp
#define shaderVertical_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderVertical : public baseScene{
  
public:
    
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();
    
};


#endif /* shaderVertical_hpp */
