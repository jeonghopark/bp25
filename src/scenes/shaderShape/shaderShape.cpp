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
    
    houseImage.load("fassade_apotheke_alpha.png");
    
    
    houseScaleRatio = 0.45;
    
    imageRatio.cWidth = houseImage.getWidth() * houseScaleRatio;
    imageRatio.cHeight = houseImage.getHeight() * houseScaleRatio;
    imageRatio.xOffSet = (ofGetWidth() - imageRatio.cWidth) * 0.5;
    imageRatio.yOffSet = (ofGetHeight() - imageRatio.cHeight) * 0.5;
    
    
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
    
    
    
    ofPushStyle();
    ofPushMatrix();
    
    ofSetColor(0);
    ofDrawRectangle(0, 0, ofGetWidth(), imageRatio.yOffSet);
    ofDrawRectangle(0, imageRatio.yOffSet + imageRatio.cHeight, ofGetWidth(), imageRatio.yOffSet);
    ofDrawRectangle(0, 0, imageRatio.xOffSet, ofGetHeight());
    ofDrawRectangle(imageRatio.xOffSet + imageRatio.cWidth, 0, ofGetWidth()-imageRatio.xOffSet, ofGetHeight());
    
    ofSetColor(255);
    houseImage.draw(imageRatio.xOffSet, imageRatio.yOffSet, imageRatio.cWidth, imageRatio.cHeight);
    
    ofPopMatrix();
    ofPopStyle();
    
}




//--------------------------------------------------------------
void shaderShape::keyPressed(int key){
    shader_01.load("", "shader/shader.frag");
}
