//
//  shaderCircleNoise.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderCircleNoise.hpp"





//--------------------------------------------------------------
void shaderCircleNoise::setup(){
    
    shaderCircleNoise.load("", "shader/shaderCircleNoise.frag");
    
}



//--------------------------------------------------------------
void shaderCircleNoise::update(){
    
}



//--------------------------------------------------------------
void shaderCircleNoise::draw(){
    
    shaderCircleNoise.begin();
    shaderCircleNoise.setUniform1f("u_time", ofGetElapsedTimef());
    shaderCircleNoise.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderCircleNoise.end();
    
    
}


//--------------------------------------------------------------
void shaderCircleNoise::updateShader(){
    shaderCircleNoise.load("", "shader/shaderCircleNoise.frag");
}
