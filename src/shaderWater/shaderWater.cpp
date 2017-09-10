//
//  shaderWater.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderWater.hpp"



//--------------------------------------------------------------
void shaderWater::setup(){
    
    shaderWater.load("", "shader/shaderWater.frag");
    
}



//--------------------------------------------------------------
void shaderWater::update(){
    
}



//--------------------------------------------------------------
void shaderWater::draw(){
    
    shaderWater.begin();
    shaderWater.setUniform1f("u_time", ofGetElapsedTimef());
    shaderWater.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderWater.end();
    
    
}


//--------------------------------------------------------------
void shaderWater::updateShader(){
    shaderWater.load("", "shader/shaderWater.frag");
}
