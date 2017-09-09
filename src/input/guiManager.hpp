//
//  guiManager.hpp
//  bp2.5
//
//  Created by JeongHo Park on 07.09.17.
//
#pragma once

#ifndef guiManager_hpp
#define guiManager_hpp

#include "ofMain.h"
#include "ofxGui.h"


class guiManager{
  
public:
    
    void setup();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);
    
    void setupGui();
    
    
    // GUI
    ofParameterGroup basicLineDrawing;
    ofParameter<bool> motion;
    ofParameter<bool> houseView;
    ofParameter<float> motionSpeed;
    
    ofParameterGroup mainGui;
    ofParameter<string> frameRate;
    
    ofxPanel main;
    ofxPanel panel;

    
    
};


#endif /* guiManager_hpp */
