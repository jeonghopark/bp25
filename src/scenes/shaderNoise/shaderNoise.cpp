//
//  shaderNoise.cpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#include "shaderNoise.hpp"


//--------------------------------------------------------------
void shaderNoise::setup(){
    
    loadShader();
    
}



//--------------------------------------------------------------
void shaderNoise::update(){
    
    updateName();
    
}




//--------------------------------------------------------------
void shaderNoise::updateShader(){
    
    shaderFbo.begin();
    ofClear(0, 0, 0, 0);
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    shader.setUniform1f("u_control01", ofGetElapsedTimef());
    shader.setUniform1f("u_control02", ofGetElapsedTimef());
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
    
    
}


//--------------------------------------------------------------
void shaderNoise::draw(){
    
    drawGlitch();
    
}


//--------------------------------------------------------------
void shaderNoise::loadShader(){
    
    shaderFile.open("shader/shaderNoise.frag");
    shader.load("shader/shaderNoise.vert", "shader/shaderNoise.frag");
    
}


//--------------------------------------------------------------
string shaderNoise::setName(){
    
    return shaderFile.getBaseName();
    
}

