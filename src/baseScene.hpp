//
//  baseScene.hpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//
#pragma once

#ifndef baseScene_hpp
#define baseScene_hpp

#include "ofMain.h"


class baseScene {
  
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    
};


#endif /* baseScene_hpp */
