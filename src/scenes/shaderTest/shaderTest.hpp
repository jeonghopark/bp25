//
//  shaderTest.hpp
//  bp_25
//
//  Created by JeongHo Park on 12.09.17.
//

#ifndef shaderTest_hpp
#define shaderTest_hpp

#include "ofMain.h"
#include "baseScene.hpp"

class shaderTest : public baseScene{
    
public:
    
    void setup();
    void update();
    void draw();

    void loadShader();
    void updateShader();
    
    string setName();
  
    
};


#endif /* shaderTest_hpp */
