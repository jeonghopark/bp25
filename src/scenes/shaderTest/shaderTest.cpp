//
//  shaderTest.cpp
//  bp_25
//
//  Created by JeongHo Park on 12.09.17.
//

#include "shaderTest.hpp"


//--------------------------------------------------------------
void shaderTest::setup(){
    
    loadShader();

}



//--------------------------------------------------------------
void shaderTest::update(){

    updateName();

}



//--------------------------------------------------------------
void shaderTest::updateShader(){
    
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
    
};



//--------------------------------------------------------------
void shaderTest::draw(){
    
    drawGlitch();
    
}


//--------------------------------------------------------------
void shaderTest::loadShader(){
    shaderFile.open("shader/shaderTest.frag");
    shader.load("shader/shaderTest.vert", shaderFile);
}


//--------------------------------------------------------------
string shaderTest::setName(){
    
    return shaderFile.getBaseName();
    
}

