//
//  shaderTest.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderHotShower.hpp"


//--------------------------------------------------------------
void shaderHotShower::setup(){
    
    shaderHotShower.load("", "shader/shaderHotShower.frag");
    
}



//--------------------------------------------------------------
void shaderHotShower::update(){
    
}



//--------------------------------------------------------------
void shaderHotShower::draw(){
    
    shaderHotShower.begin();
    shaderHotShower.setUniform1f("u_time", ofGetElapsedTimef());
    shaderHotShower.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderHotShower.end();
    
    
}


//--------------------------------------------------------------
void shaderHotShower::updateShader(){
    shaderHotShower.load("", "shader/shaderHotShower.frag");
}


