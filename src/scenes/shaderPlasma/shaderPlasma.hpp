//
//  shaderPlasma.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderPlasma_hpp
#define shaderPlasma_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderPlasma : public baseScene{
  
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();

    
};



#endif /* shaderPlasma_hpp */
