//
//  shaderSun.cpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#include "shaderSun.hpp"


//--------------------------------------------------------------
void shaderSun::setup(){
    
    shaderNoise.load("", "shader/shaderSun.frag");
        
}



//--------------------------------------------------------------
void shaderSun::update(){
    
    
}




//--------------------------------------------------------------
void shaderSun::draw(){
    
    shaderNoise.begin();
    shaderNoise.setUniform1f("u_time", ofGetElapsedTimef());
    shaderNoise.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    shaderNoise.end();
    
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(255, 0, 0);
    ofDrawRectangle(ofGetWidth() * 0.5, 0, ofGetWidth() * 0.5, ofGetHeight());

    ofPopMatrix();
    ofPopStyle();

    
}




//--------------------------------------------------------------
void shaderSun::updateShader(){
    shaderNoise.load("", "shader/shaderSun.frag");
}
