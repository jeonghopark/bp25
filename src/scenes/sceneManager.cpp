//
//  sceneManager.cpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//

#include "sceneManager.hpp"

//--------------------------------------------------------------
void sceneManager::setup(){
    
    for(auto scene: scenes) {
        scene->setup();
    }
    
    currentScene = 0;
}


//--------------------------------------------------------------
void sceneManager::update(){
    
    scenes[currentScene]->update();
        
}



//--------------------------------------------------------------
void sceneManager::draw(){
    
    scenes[currentScene]->draw();
    
}



//--------------------------------------------------------------
void sceneManager::nextScene(){
    
    currentScene++;
    currentScene %= scenes.size();
    
}




