//
//  shaderDiffusion.hpp
//  bp_25
//
//  Created by JeongHo Park on 12.09.17.
//

#ifndef shaderDiffusion_hpp
#define shaderDiffusion_hpp

#include "ofMain.h"
#include "baseScene.hpp"

class shaderDiffusion : public baseScene {
  
public:
    
    void setup();
    void update();
    void draw();
    void loadShader();
    void updateShader();
    
    string setName();    
    
};

#endif /* shaderDiffusion_hpp */
