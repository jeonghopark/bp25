//
//  shaderPlasma.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderPlasma.hpp"




//--------------------------------------------------------------
void shaderPlasma::setup(){
    
    shaderPlasma.load("", "shader/shaderPlasma.frag");
    
}



//--------------------------------------------------------------
void shaderPlasma::update(){
    
}



//--------------------------------------------------------------
void shaderPlasma::draw(){
    
    shaderPlasma.begin();
    shaderPlasma.setUniform1f("u_time", ofGetElapsedTimef());
    shaderPlasma.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderPlasma.end();
    
    
}


//--------------------------------------------------------------
void shaderPlasma::updateShader(){
    shaderPlasma.load("", "shader/shaderPlasma.frag");
}
