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
    
    ofBackground(0);
    
    SM.scenes.push_back( new blankScene() );
    SM.scenes.push_back( new logoScene() );
    SM.scenes.push_back( new basicLineDrawing() );
    SM.scenes.push_back( new shaderNoise() );
    SM.scenes.push_back( new shaderVertical() );
    SM.scenes.push_back( new shaderLine() );
    SM.scenes.push_back( new shaderSun() );
    SM.scenes.push_back( new shaderHotShower() );
    SM.scenes.push_back( new shaderCrystal() );
    SM.scenes.push_back( new shaderOil() );
    SM.scenes.push_back( new shaderNoiseBlur() );
    SM.scenes.push_back( new shaderWater() );
    SM.scenes.push_back( new shaderCircleNoise_stage() );
    SM.scenes.push_back( new shaderPlasma() );
    //    SM.scenes.push_back( new shaderStar() );
    SM.scenes.push_back( new shaderWhitehole() );
    SM.scenes.push_back( new shaderJupiter() );
    SM.scenes.push_back( new shaderDiffusion() );
    SM.scenes.push_back( new shaderTest() );
    SM.setup();

    
    SM.setup();
    
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->GM = &GM;
    }

}



//--------------------------------------------------------------
void stageView::update(){
    
    SM.update();
    GM.update();

}



//--------------------------------------------------------------
void stageView::draw(){
    
    SM.draw();
        
}



//--------------------------------------------------------------
void stageView::keyPressed(int key){
    
    if (key == 14){
        SM.nextScene();
    }
    
    if (key == 16){
        SM.previousScene();
    }
    
    if (key == 12){
        SM.loadShader();
    }
    
    SM.glitchOn(key);

}


//--------------------------------------------------------------
void stageView::keyReleased(int key){
    
    SM.glitchOff(key);
    
}



