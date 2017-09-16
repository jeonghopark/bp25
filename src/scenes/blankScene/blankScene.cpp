//
//  blankScene.cpp
//  bp_25
//
//  Created by JeongHo Park on 10.09.17.
//

#include "blankScene.hpp"


//--------------------------------------------------------------
void blankScene::setup(){
    
    bpLogo.load("BP_Logo_Profilbild2.png");
    
    imgWidth = ofGetWidth() * 0.4;
    imgHeight = ofGetWidth() * 0.4;

}



//--------------------------------------------------------------
void blankScene::update(){
    updateName();
}



//--------------------------------------------------------------
void blankScene::draw(){
    
    float _x = (ofGetWidth() - imgWidth) * 0.5;
    float _y = (ofGetHeight() - imgHeight) * 0.5;
    bpLogo.draw(_x, _y, imgWidth, imgHeight);
    
}


//--------------------------------------------------------------
string blankScene::setName(){
    
    return "Binary Patina";
    
}


