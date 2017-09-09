//
//  houseBlackCover.hpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//
#pragma once


#ifndef houseBlackCover_hpp
#define houseBlackCover_hpp

#include "ofMain.h"


class houseBlackCover {
  
    
    struct ImageRatio{
        float cWidth;
        float cHeight;
        
        float xOffSet;
        float yOffSet;
    };

    
    
public:
    
    void setup();
    void update();
    void draw();
    
    
    ofImage houseImage;
    
    float houseScaleRatio;
    
    ImageRatio imageRatio;

    
    
};



#endif /* houseBlackCover_hpp */
