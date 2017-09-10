//
//  shaderNoiseBlur.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderNoiseBlur.hpp"


//--------------------------------------------------------------
void shaderNoiseBlur::setup(){
    
    shaderNoiseBlur.load("", "shader/shaderNoiseBlur.frag");
    
}



//--------------------------------------------------------------
void shaderNoiseBlur::update(){
    
}



//--------------------------------------------------------------
void shaderNoiseBlur::draw(){
    
    shaderNoiseBlur.begin();
    shaderNoiseBlur.setUniform1f("u_time", ofGetElapsedTimef());
    shaderNoiseBlur.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderNoiseBlur.end();
    
    
}


//--------------------------------------------------------------
void shaderNoiseBlur::updateShader(){
    shaderNoiseBlur.load("", "shader/shaderNoiseBlur.frag");
}
