//
//  shaderBasic.cpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#include "shaderBasic.hpp"


//--------------------------------------------------------------
void shaderBasic::setup(){
    
    shaderNoise.load("", "shader/shaderNoise.frag");


}



//--------------------------------------------------------------
void shaderBasic::update(){
    
    
}




//--------------------------------------------------------------
void shaderBasic::draw(){
    
    shaderNoise.begin();
    shaderNoise.setUniform1f("u_time", ofGetElapsedTimef());
    shaderNoise.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderNoise.end();
    
}




//--------------------------------------------------------------
void shaderBasic::updateShader(){
    shaderNoise.load("", "shader/shaderNoise.frag");
}
