//
//  shaderPilament.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderPilament.hpp"


//--------------------------------------------------------------
void shaderPilament::setup(){
    
    shaderPilament.load("", "shader/shaderPilament.frag");
    
}



//--------------------------------------------------------------
void shaderPilament::update(){
    
}



//--------------------------------------------------------------
void shaderPilament::draw(){
    
    shaderPilament.begin();
    shaderPilament.setUniform1f("u_time", ofGetElapsedTimef());
    shaderPilament.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderPilament.end();
    
    
}


//--------------------------------------------------------------
void shaderPilament::updateShader(){
    shaderPilament.load("", "shader/shaderPilament.frag");
}
