//  Original ofZach
//  baseScene.hpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//
#pragma once

#ifndef baseScene_hpp
#define baseScene_hpp

#include "ofMain.h"
#include "ofxPostGlitch.h"

#include "guiManager.hpp"

class baseScene {
  
public:
    
    virtual void setup(){};
    virtual void update(){};
    virtual void draw(){};
    
    virtual void loadShader(){};
    virtual void updateShader(){};

    virtual string setName(){ return "0"; };

    guiManager * GM;
    
    void updateName() { GM->sceneName = setName(); };
    
    ofShader shader;
    ofFile shaderFile;
    ofFbo            shaderFbo;
    ofxPostGlitch    shaderGlitch;
    
    
    //--------------------------------------------------------------
    void setupGlitch(){
        shaderFbo.allocate(550, 880);
        shaderGlitch.setup(&shaderFbo);
    };
    
    
    //--------------------------------------------------------------
    void drawGlitch(){
        
        //        ofSetColor(255);
        shaderGlitch.generateFx();
        //        ofSetColor(255);
        shaderFbo.draw(0, 0);
        
    }
    
    
    //--------------------------------------------------------------
    void glitchOn(int key){
        if (key == '1') shaderGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , true);
        if (key == '2') shaderGlitch.setFx(OFXPOSTGLITCH_GLOW            , true);
        if (key == '3') shaderGlitch.setFx(OFXPOSTGLITCH_SHAKER            , true);
        if (key == '4') shaderGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , true);
        if (key == '5') shaderGlitch.setFx(OFXPOSTGLITCH_TWIST            , true);
        if (key == '6') shaderGlitch.setFx(OFXPOSTGLITCH_OUTLINE        , true);
        if (key == '7') shaderGlitch.setFx(OFXPOSTGLITCH_NOISE            , true);
        if (key == '8') shaderGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , true);
        if (key == '9') shaderGlitch.setFx(OFXPOSTGLITCH_SWELL            , true);
        if (key == '0') shaderGlitch.setFx(OFXPOSTGLITCH_INVERT            , true);
        
        if (key == 'q') shaderGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, true);
        if (key == 'w') shaderGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , true);
        if (key == 'e') shaderGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , true);
        if (key == 'r') shaderGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , true);
        if (key == 't') shaderGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , true);
        if (key == 'z') shaderGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , true);
        if (key == 'u') shaderGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , true);
        
        if (key == 'l') shaderGlitch.loadShader();
    };
    
    //--------------------------------------------------------------
    void glitchOff(int key){
        if (key == '1') shaderGlitch.setFx(OFXPOSTGLITCH_CONVERGENCE    , false);
        if (key == '2') shaderGlitch.setFx(OFXPOSTGLITCH_GLOW            , false);
        if (key == '3') shaderGlitch.setFx(OFXPOSTGLITCH_SHAKER            , false);
        if (key == '4') shaderGlitch.setFx(OFXPOSTGLITCH_CUTSLIDER        , false);
        if (key == '5') shaderGlitch.setFx(OFXPOSTGLITCH_TWIST            , false);
        if (key == '6') shaderGlitch.setFx(OFXPOSTGLITCH_OUTLINE        , false);
        if (key == '7') shaderGlitch.setFx(OFXPOSTGLITCH_NOISE            , false);
        if (key == '8') shaderGlitch.setFx(OFXPOSTGLITCH_SLITSCAN        , false);
        if (key == '9') shaderGlitch.setFx(OFXPOSTGLITCH_SWELL            , false);
        if (key == '0') shaderGlitch.setFx(OFXPOSTGLITCH_INVERT            , false);
        
        if (key == 'q') shaderGlitch.setFx(OFXPOSTGLITCH_CR_HIGHCONTRAST, false);
        if (key == 'w') shaderGlitch.setFx(OFXPOSTGLITCH_CR_BLUERAISE    , false);
        if (key == 'e') shaderGlitch.setFx(OFXPOSTGLITCH_CR_REDRAISE    , false);
        if (key == 'r') shaderGlitch.setFx(OFXPOSTGLITCH_CR_GREENRAISE    , false);
        if (key == 't') shaderGlitch.setFx(OFXPOSTGLITCH_CR_BLUEINVERT    , false);
        if (key == 'z') shaderGlitch.setFx(OFXPOSTGLITCH_CR_REDINVERT    , false);
        if (key == 'u') shaderGlitch.setFx(OFXPOSTGLITCH_CR_GREENINVERT    , false);
    };
    
    
};


#endif /* baseScene_hpp */
