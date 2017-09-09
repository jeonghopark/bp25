//
//  subView.hpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#pragma once


#ifndef subView_hpp
#define subView_hpp

#include "ofMain.h"

#include "sceneManager.hpp"
#include "guiManager.hpp"
#include "baseScene.hpp"


class subView : public ofBaseApp{
    
public:
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);

    guiManager GM;
    
};


#endif /* subView_hpp */
