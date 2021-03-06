#pragma once

#include "ofMain.h"

#include "sceneManager.hpp"
#include "guiManager.hpp"
#include "MidiInput.hpp"
#include "baseScene.hpp"

#include "houseBlackCover.hpp"

#include "blankScene.hpp"
#include "logoScene.hpp"
#include "basicLineDrawing.hpp"
#include "shaderNoise.hpp"
#include "shaderVertical.hpp"
#include "shaderLine.hpp"
#include "shaderSun.hpp"
#include "shaderHotShower.hpp"
#include "shaderCrystal.hpp"
#include "shaderOil.hpp"
#include "shaderNoiseBlur.hpp"
#include "shaderWater.hpp"
#include "shaderCircleNoise.hpp"
#include "shaderPlasma.hpp"
//#include "shaderStar.hpp"
#include "shaderWhitehole.hpp"
#include "shaderJupiter.hpp"
#include "shaderDiffusion.hpp"
#include "shaderTest.hpp"


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
    
    guiManager GM;
    MidiInput MM;
    sceneManager SM;
    
    
    houseBlackCover HouseBlackCover;
    
//    ofImage bpLogo_trans;
//    float imgWidth, imgHeight;

    
};

