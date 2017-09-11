//
//  shaderVertical.cpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#include "shaderVertical.hpp"


//--------------------------------------------------------------
void shaderVertical::setup(){
    
    shaderFile.open("shader/shaderVertical.frag");
    shader.load("shader/shaderVertical.vert", shaderFile);
    
}



//--------------------------------------------------------------
void shaderVertical::update(){
    
    updateName();
    
}



//--------------------------------------------------------------
void shaderVertical::draw(){
    
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    shader.end();


}


//--------------------------------------------------------------
void shaderVertical::updateShader(){

    shaderFile.open("shader/shaderVertical.frag");
    shader.load("shader/shaderVertical.vert", shaderFile);

}


//--------------------------------------------------------------
string shaderVertical::setName(){
    
    return shaderFile.getBaseName();
    
}


