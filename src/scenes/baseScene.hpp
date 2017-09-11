//  Original ofZach
//  baseScene.hpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//
#pragma once

#ifndef baseScene_hpp
#define baseScene_hpp

#include "ofMain.h"
#include "guiManager.hpp"

class baseScene {
  
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void updateShader(){};
    virtual string setName(){ return "0"; };

    guiManager * GM;
    
    void updateName() { GM->sceneName = setName(); };
    
    ofShader shader;
    ofFile shaderFile;


};


#endif /* baseScene_hpp */
