//
//  shaderBasic.hpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#ifndef shaderBasic_hpp
#define shaderBasic_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderBasic : public baseScene{
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);

    
    ofImage houseImage;
    ofShader shader_01;
    
    float houseScaleRatio;
    
//    ImageRatio imageRatio;

    
};


#endif /* shaderBasic_hpp */
