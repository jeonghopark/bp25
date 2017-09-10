//
//  houseBlackCover.cpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#include "houseBlackCover.hpp"



//--------------------------------------------------------------
void houseBlackCover::setup(){
    
    houseImage.load("fassade_apotheke_alpha.png");
        
    houseScaleRatio = 0.45;
    
    imageRatio.cWidth = houseImage.getWidth() * houseScaleRatio;
    imageRatio.cHeight = houseImage.getHeight() * houseScaleRatio;
    imageRatio.xOffSet = (ofGetWidth() - imageRatio.cWidth) * 0.5;
    imageRatio.yOffSet = (ofGetHeight() - imageRatio.cHeight) * 0.5;

}



//--------------------------------------------------------------
void houseBlackCover::update(){
    
}



//--------------------------------------------------------------
void houseBlackCover::draw(){

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
