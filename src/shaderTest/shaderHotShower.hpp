//
//  shaderTest.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//
#pragma once

#ifndef shaderHotShower_hpp
#define shaderHotShower_hpp


#include "ofMain.h"
#include "baseScene.hpp"


class shaderHotShower : public baseScene {

public:
    
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderHotShower;
    
};




#endif /* shaderHotShower_hpp */
