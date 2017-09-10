//
//  shaderWhitehole.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderWhitehole.hpp"




//--------------------------------------------------------------
void shaderWhitehole::setup(){
    
    shaderWhitehole.load("", "shader/shaderWhitehole.frag");
    
}



//--------------------------------------------------------------
void shaderWhitehole::update(){
    
}



//--------------------------------------------------------------
void shaderWhitehole::draw(){
    
    shaderWhitehole.begin();
    shaderWhitehole.setUniform1f("u_time", ofGetElapsedTimef());
    shaderWhitehole.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shaderWhitehole.end();
    
    
}


//--------------------------------------------------------------
void shaderWhitehole::updateShader(){
    shaderWhitehole.load("", "shader/shaderWhitehole.frag");
}
