//  Original ofZach
//  sceneManager.hpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//
#pragma once


#ifndef sceneManager_hpp
#define sceneManager_hpp

#include "ofMain.h"
#include "baseScene.hpp"


class sceneManager {
  
    
public:
    
    void setup();
    void update();
    void draw();
    
    void nextScene();
    void previousScene();
    
    void loadShader();

    
    vector < baseScene * > scenes;
    int currentScene;
    
    void glitchOn(int key);
    void glitchOff(int key);

    
};


#endif /* sceneManager_hpp */
