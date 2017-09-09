//
//  stageView.hpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#pragma once


#ifndef stageView_hpp
#define stageView_hpp

#include "ofMain.h"

#include "sceneManager.hpp"
#include "guiManager.hpp"
#include "baseScene.hpp"


class stageView : public ofBaseApp{
    
public:
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);

    guiManager GM;
    
    float _testMoving_;
    
};


#endif /* stageView_hpp */
