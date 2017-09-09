//
//  shaderVertical.cpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#include "shaderVertical.hpp"


//--------------------------------------------------------------
void shaderVertical::setup(){
    
    shaderVertical.load("", "shader/shaderVertical.frag");
    
}



//--------------------------------------------------------------
void shaderVertical::update(){
    
}



//--------------------------------------------------------------
void shaderVertical::draw(){
    
    shaderVertical.begin();
    shaderVertical.setUniform1f("u_time", ofGetElapsedTimef());
    shaderVertical.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    shaderVertical.end();


}


//--------------------------------------------------------------
void shaderVertical::updateShader(){
    shaderVertical.load("", "shader/shaderVertical.frag");
}
