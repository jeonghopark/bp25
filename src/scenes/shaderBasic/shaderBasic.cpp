//
//  shaderBasic.cpp
//  bp 2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#include "shaderBasic.hpp"


//--------------------------------------------------------------
void shaderBasic::setup(){
    
    shader_01.load("", "shader/shader.frag");


}



//--------------------------------------------------------------
void shaderBasic::update(){
    
    
}




//--------------------------------------------------------------
void shaderBasic::draw(){
    
    shader_01.begin();
    shader_01.setUniform1f("u_time", ofGetElapsedTimef());
    shader_01.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    shader_01.end();
    
}




//--------------------------------------------------------------
void shaderBasic::keyPressed(int key){
    shader_01.load("", "shader/shader.frag");
}
