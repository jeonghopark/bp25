//
//  shaderOil.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderOil_hpp
#define shaderOil_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderOil : public baseScene{
  
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();

    
};





#endif /* shaderOil_hpp */
