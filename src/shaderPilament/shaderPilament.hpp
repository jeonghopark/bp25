//
//  shaderPilament.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#ifndef shaderPilament_hpp
#define shaderPilament_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class shaderPilament : public baseScene{
  
    void setup();
    void update();
    void draw();
    void updateShader();
    
    ofShader shaderPilament;

    
};



#endif /* shaderPilament_hpp */
