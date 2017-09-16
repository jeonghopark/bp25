//
//  logoScene.cpp
//  bp_25
//
//  Created by JeongHo Park on 16.09.17.
//

#include "logoScene.hpp"


//--------------------------------------------------------------
void logoScene::setup(){
    
    bpLogo_trans.load("bp_logo_04_antialiasing.png");
    
    imgWidth = ofGetWidth() * 0.6;
    imgHeight = ofGetWidth() * 0.6;
    
    loadShader();
    
}



//--------------------------------------------------------------
void logoScene::update(){
    
    updateName();
    
}



//--------------------------------------------------------------
void logoScene::updateShader(){
    
    shaderFbo.begin();
    ofClear(0, 0, 0, 0);
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    shader.setUniformTexture("tex0", bpLogo_trans.getTexture(), 0);
    
    shader.setUniform1f("u_control01", ofGetElapsedTimef());
    shader.setUniform1f("u_control02", ofGetElapsedTimef());
    shader.setUniform1f("u_control03", ofGetElapsedTimef());
    shader.setUniform1f("u_control04", ofGetElapsedTimef());
    shader.setUniform1f("u_control05", ofGetElapsedTimef());
    shader.setUniform1f("u_control06", ofGetElapsedTimef());
    shader.setUniform1f("u_control07", ofGetElapsedTimef());
    shader.setUniform1f("u_control08", ofGetElapsedTimef());
    shader.setUniform1f("u_control09", ofGetElapsedTimef());
    shader.setUniform1f("u_control10", ofGetElapsedTimef());
    
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    float _x = (ofGetWidth() - imgWidth) * 0.5;
    float _y = (ofGetHeight() - imgHeight) * 0.5;
    bpLogo_trans.draw(_x, _y, imgWidth, imgHeight);
    
    shader.end();
    shaderFbo.end();
    
};



//--------------------------------------------------------------
void logoScene::draw(){
    
    drawGlitch();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
//    float _x = (ofGetWidth() - imgWidth) * 0.5;
//    float _y = (ofGetHeight() - imgHeight) * 0.5;
//    bpLogo_trans.draw(_x, _y, imgWidth, imgHeight);
    
    ofDisableBlendMode();
    
}


//--------------------------------------------------------------
void logoScene::loadShader(){
    shaderFile.open("shader/logoScene.frag");
    shader.load("shader/logoScene.vert", shaderFile);
}


//--------------------------------------------------------------
string logoScene::setName(){
    
    return "Logo";
    
}

