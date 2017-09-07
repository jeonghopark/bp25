//
//  guiManager.cpp
//  bp2.5
//
//  Created by JeongHo Park on 07.09.17.
//

#include "guiManager.hpp"

void guiManager::setupGui(){
    
    mainGui.setName("Main");
    mainGui.add(frameRate.set("FPS", ""));
    main.setup();
    main.setPosition(10, 10);
    main.add(mainGui);
    
    basicLineDrawing.setName("basicLineDrawing");
    basicLineDrawing.add(houseView.set("House View", false));
    basicLineDrawing.add(motion.set("Motion", true));
    basicLineDrawing.add(motionSpeed.set("Motion Speed", 1, 0.3, 5));
    panel.setup();
    panel.setPosition(10, 100);
    panel.add(basicLineDrawing);
    
    ofSetBackgroundColor(120);

}



//--------------------------------------------------------------
void guiManager::setup(){
    
    
    
}


//--------------------------------------------------------------
void guiManager::update(){
    
    frameRate = ofToString(ofGetFrameRate(), 2);
    
}



//--------------------------------------------------------------
void guiManager::draw(){
    
    main.draw();
    panel.draw();

}


//--------------------------------------------------------------
void guiManager::drawGui(ofEventArgs & args){
}


