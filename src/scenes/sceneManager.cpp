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
        scene->setupGlitch();
    }
    
    currentScene = 0;
    
    FF.setup();
}


//--------------------------------------------------------------
void sceneManager::update(){
    
    scenes[currentScene]->update();
    scenes[currentScene]->updateShader();
    
    FF.draw();
    
    float _sum = 0;
    for (int i=0; i<3; i++) {
        _sum += FF.drawBins[i] / 3.0;
    }
    
    scenes[currentScene]->fft1 = _sum;
    cout << _sum << endl;
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


//--------------------------------------------------------------
void sceneManager::previousScene(){
    
    currentScene--;
    
    if (currentScene < 0) {
        currentScene = scenes.size() - 1;
    }
    
}


//--------------------------------------------------------------
void sceneManager::loadShader(){
    
    scenes[currentScene]->loadShader();
    
}


//--------------------------------------------------------------
void sceneManager::glitchOn(int key){
    
    scenes[currentScene]->glitchOn(key);
    
}



//--------------------------------------------------------------
void sceneManager::glitchOff(int key){
    
    scenes[currentScene]->glitchOff(key);
    
}

