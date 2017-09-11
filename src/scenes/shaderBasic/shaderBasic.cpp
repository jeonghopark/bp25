//
//  shaderBasic.cpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#include "shaderBasic.hpp"


//--------------------------------------------------------------
void shaderBasic::setup(){
    
    shaderFile.open("shader/shaderNoise.frag");
    shader.load("shader/shaderNoise.vert", "shader/shaderNoise.frag");

}



//--------------------------------------------------------------
void shaderBasic::update(){
    
    updateName();
    
}




//--------------------------------------------------------------
void shaderBasic::draw(){
    
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shader.end();
    
}




//--------------------------------------------------------------
void shaderBasic::updateShader(){

    shaderFile.open("shader/shaderNoise.frag");
    shader.load("shader/shaderNoise.vert", "shader/shaderNoise.frag");

}


//--------------------------------------------------------------
string shaderBasic::setName(){

    return shaderFile.getBaseName();

}
