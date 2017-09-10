//
//  shaderCrystal.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderCrystal.hpp"


//--------------------------------------------------------------
void shaderCrystal::setup(){
    
    shaderCrystal.load("", "shader/shaderCrystal.frag");
    
}



//--------------------------------------------------------------
void shaderCrystal::update(){
    
}



//--------------------------------------------------------------
void shaderCrystal::draw(){
    
    shaderCrystal.begin();
    shaderCrystal.setUniform1f("u_time", ofGetElapsedTimef());
    shaderCrystal.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderCrystal.end();
    
    
}


//--------------------------------------------------------------
void shaderCrystal::updateShader(){
    shaderCrystal.load("", "shader/shaderCrystal.frag");
}
