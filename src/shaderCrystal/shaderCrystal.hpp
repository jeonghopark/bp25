//
//  shaderCrystal.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderCrystal_hpp
#define shaderCrystal_hpp

#include "ofMain.h"
#include "baseScene.hpp"



class shaderCrystal : public baseScene{
    
    void setup();
    void update();
    void draw();
    void updateShader();
  
    ofShader shaderCrystal;
    
};


#endif /* shaderCrystal_hpp */
