//
//  stageView.cpp
//  bp_25
//
//  Created by JeongHo Park on 09.09.17.
//

#include "stageView.hpp"


//--------------------------------------------------------------
void stageView::setupGui(){
    GM.setup();
}


//--------------------------------------------------------------
void stageView::drawGui(ofEventArgs & args){
//    GM.draw();
}



//--------------------------------------------------------------
void stageView::setup(){
    
    ofBackground(120, 0, 0);
    
    _testMoving_ = 0;
    
}



//--------------------------------------------------------------
void stageView::update(){
    
    _testMoving_ += 5;
    
}



//--------------------------------------------------------------
void stageView::draw(){
    
    ofSetColor(255);
    ofDrawRectangle( sin(ofDegToRad(_testMoving_)) * 200 + ofGetWidth() * 0.5, ofGetHeight() * 0.5, 20, 20);
    
}
