//
//  shaderShape.hpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#ifndef shaderShape_hpp
#define shaderShape_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderShape : public baseScene{
  
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
    void keyPressed(int key);
    
    
    ofImage houseImage;
    ofShader shader_01;
    
    float houseScaleRatio;
    
    ImageRatio imageRatio;
    
    
};



#endif /* shaderShape_hpp */
