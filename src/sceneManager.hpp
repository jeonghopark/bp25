//
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
    
    
    vector < baseScene * > scenes;
    int currentScene;
    
    
};


#endif /* sceneManager_hpp */
