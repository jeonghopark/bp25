//
//  shaderStar.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderStar_hpp
#define shaderStar_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderStar : public baseScene{
  
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();

    
};


#endif /* shaderStar_hpp */
