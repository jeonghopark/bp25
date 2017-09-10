//
//  shaderSun.cpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#include "shaderSun.hpp"


//--------------------------------------------------------------
void shaderSun::setup(){
    
    shaderSun.load("", "shader/shaderSun.frag");
        
}



//--------------------------------------------------------------
void shaderSun::update(){
    
    
}




//--------------------------------------------------------------
void shaderSun::draw(){
    
    shaderSun.begin();
    shaderSun.setUniform1f("u_time", ofGetElapsedTimef());
    shaderSun.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    shaderSun.end();
    
}




//--------------------------------------------------------------
void shaderSun::updateShader(){
    shaderSun.load("", "shader/shaderSun.frag");
}
