//
//  shaderShape.cpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#include "shaderShape.hpp"


//--------------------------------------------------------------
void shaderShape::setup(){
    
    shader_01.load("", "shader/shader.frag");
        
}



//--------------------------------------------------------------
void shaderShape::update(){
    
    
}




//--------------------------------------------------------------
void shaderShape::draw(){
    
    shader_01.begin();
    shader_01.setUniform1f("u_time", ofGetElapsedTimef());
    shader_01.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    ofRect(0,0,ofGetWidth(), ofGetHeight());
    
    shader_01.end();
    
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(255, 0, 0);
    ofRect(ofGetWidth() * 0.5, 0, ofGetWidth() * 0.5, ofGetHeight());

    ofPopMatrix();
    ofPopStyle();

    
}




//--------------------------------------------------------------
void shaderShape::keyPressed(int key){
    shader_01.load("", "shader/shader.frag");
}
