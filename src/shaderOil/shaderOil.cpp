//
//  shaderOil.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderOil.hpp"


//--------------------------------------------------------------
void shaderOil::setup(){
    
    shaderOil.load("", "shader/shaderOil.frag");
    
}



//--------------------------------------------------------------
void shaderOil::update(){
    
}



//--------------------------------------------------------------
void shaderOil::draw(){
    
    shaderOil.begin();
    shaderOil.setUniform1f("u_time", ofGetElapsedTimef());
    shaderOil.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderOil.end();
    
    
}


//--------------------------------------------------------------
void shaderOil::updateShader(){
    shaderOil.load("", "shader/shaderOil.frag");
}
