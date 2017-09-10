//
//  blankScene.hpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#ifndef blankScene_hpp
#define blankScene_hpp

#include "ofMain.h"
#include "baseScene.hpp"

class blankScene : public baseScene {
    
    void setup();
    void update();
    void draw();
    
    
    ofImage bpLogo;
    
    float imgWidth, imgHeight;
    
};




#endif /* blankScene_hpp */
