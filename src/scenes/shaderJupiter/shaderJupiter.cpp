//
//  shaderJupiter.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "shaderJupiter.hpp"




//--------------------------------------------------------------
void shaderJupiter::setup(){
    
    loadShader();
    
}



//--------------------------------------------------------------
void shaderJupiter::update(){
    updateName();
}



//--------------------------------------------------------------
void shaderJupiter::updateShader(){
    
    shaderFbo.begin();
    ofClear(0, 0, 0, 0);
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    shader.setUniform1f("u_control01", ofGetElapsedTimef());
    shader.setUniform1f("u_control02", fft1);
    shader.setUniform1f("u_control03", ofGetElapsedTimef());
    shader.setUniform1f("u_control04", ofGetElapsedTimef());
    shader.setUniform1f("u_control05", ofGetElapsedTimef());
    shader.setUniform1f("u_control06", ofGetElapsedTimef());
    shader.setUniform1f("u_control07", ofGetElapsedTimef());
    shader.setUniform1f("u_control08", ofGetElapsedTimef());
    shader.setUniform1f("u_control09", ofGetElapsedTimef());
    shader.setUniform1f("u_control10", ofGetElapsedTimef());
    
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    shader.end();
    shaderFbo.end();
    
};


//--------------------------------------------------------------
void shaderJupiter::draw(){
    
    drawGlitch();
        
}


//--------------------------------------------------------------
void shaderJupiter::loadShader(){
    shaderFile.open("shader/shaderJupiter.frag");
    shader.load("shader/shaderJupiter.vert", shaderFile);
}


//--------------------------------------------------------------
string shaderJupiter::setName(){
    
    return shaderFile.getBaseName();
    
}

