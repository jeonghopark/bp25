//
//  logoScene.hpp
//  bp_25
//
//  Created by JeongHo Park on 16.09.17.
//

#ifndef logoScene_hpp
#define logoScene_hpp


#include "ofMain.h"
#include "baseScene.hpp"

class logoScene : public baseScene{
    
    public:
    
    void setup();
    void update();
    void draw();
    
    void loadShader();
    void updateShader();
    
    string setName();
    
    ofImage bpLogo_trans;
    float imgWidth, imgHeight;

    
};


#endif /* logoScene_hpp */
