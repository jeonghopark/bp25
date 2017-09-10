//
//  shaderStar.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderStar.hpp"



//--------------------------------------------------------------
void shaderStar::setup(){
    
    shaderStar.load("", "shader/shaderStar.frag");
    
}



//--------------------------------------------------------------
void shaderStar::update(){
    
}



//--------------------------------------------------------------
void shaderStar::draw(){
    
    shaderStar.begin();
    shaderStar.setUniform1f("u_time", ofGetElapsedTimef());
    shaderStar.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderStar.end();
    
    
}


//--------------------------------------------------------------
void shaderStar::updateShader(){
    shaderStar.load("", "shader/shaderStar.frag");
}
