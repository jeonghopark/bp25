//
//  shaderJupiter.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderJupiter.hpp"




//--------------------------------------------------------------
void shaderJupiter::setup(){
    
    shaderJupiter.load("", "shader/shaderJupiter.frag");
    
}



//--------------------------------------------------------------
void shaderJupiter::update(){
    
}



//--------------------------------------------------------------
void shaderJupiter::draw(){
    
    shaderJupiter.begin();
    shaderJupiter.setUniform1f("u_time", ofGetElapsedTimef());
    shaderJupiter.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderJupiter.end();
    
    
}


//--------------------------------------------------------------
void shaderJupiter::updateShader(){
    shaderJupiter.load("", "shader/shaderJupiter.frag");
}
