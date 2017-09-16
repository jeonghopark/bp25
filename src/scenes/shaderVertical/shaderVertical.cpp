//
//  shaderVertical.cpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#include "shaderVertical.hpp"


//--------------------------------------------------------------
void shaderVertical::setup(){
    
    loadShader();
    
}



//--------------------------------------------------------------
void shaderVertical::update(){
    
    updateName();
    
}


//--------------------------------------------------------------
void shaderVertical::updateShader(){
    
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
void shaderVertical::draw(){
    
    drawGlitch();


}


//--------------------------------------------------------------
void shaderVertical::loadShader(){

    shaderFile.open("shader/shaderVertical.frag");
    shader.load("shader/shaderVertical.vert", shaderFile);

}


//--------------------------------------------------------------
string shaderVertical::setName(){
    
    return shaderFile.getBaseName();
    
}


