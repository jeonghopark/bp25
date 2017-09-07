#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "sceneManager.hpp"
#include "guiManager.hpp"
#include "baseScene.hpp"

#include "basicLineDrawing.hpp"


class ofApp : public ofBaseApp{
    
    
public:
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    vector<ofVec2f> houseObjectPoint;
    
    
    
//    // GUI
//    ofParameterGroup parameters;
//    ofParameter<bool> motion;
//    ofParameter<bool> houseView;
//    ofParameter<float> motionSpeed;
//    ofxPanel gui;
    
    
    guiManager GM;
    sceneManager SM;
    
    
};

