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
#include "shaderCircleNoise_stage.hpp"
#include "shaderPlasma.hpp"
//#include "shaderStar.hpp"
#include "shaderWhitehole.hpp"
#include "shaderJupiter.hpp"
#include "shaderDiffusion.hpp"
#include "shaderTest.hpp"


class stageView : public ofBaseApp{
    
public:
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);
    void keyPressed(int key);
    void keyReleased(int key);

    guiManager GM;
    sceneManager SM;
    
};


#endif /* stageView_hpp */
