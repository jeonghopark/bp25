#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setupGui(){
    GM.setup();
}


//--------------------------------------------------------------
void ofApp::drawGui(ofEventArgs & args){
    GM.draw();
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    SM.scenes.push_back( new basicLineDrawing() );
    SM.scenes.push_back( new shaderBasic() );
    SM.scenes.push_back( new shaderVertical() );
    SM.scenes.push_back( new shaderLine() );
    SM.scenes.push_back( new shaderSun() );
    SM.scenes.push_back( new shaderHotShower() );
    SM.scenes.push_back( new shaderCrystal() );
    SM.scenes.push_back( new shaderOil() );
    SM.scenes.push_back( new shaderPilament() );
    SM.scenes.push_back( new shaderNoiseBlur() );
    SM.scenes.push_back( new shaderWater() );
    SM.scenes.push_back( new shaderCircleNoise() );
    SM.scenes.push_back( new shaderPlasma() );
    SM.scenes.push_back( new shaderStar() );
    SM.scenes.push_back( new shaderWhitehole() );
    SM.scenes.push_back( new shaderJupiter() );
    SM.setup();
    
    for (int i = 0; i < SM.scenes.size(); i++){
        SM.scenes[i]->GM = &GM;
    }

    HouseBlackCover.setup();
}



//--------------------------------------------------------------
void ofApp::update(){
    
    SM.update();
    GM.update();
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    
    SM.draw();
    
    HouseBlackCover.draw();
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == OF_KEY_RIGHT){
        SM.nextScene();
    }

    if (key == OF_KEY_LEFT){
        SM.previousScene();
    }

    if (key == OF_KEY_UP){
        SM.updateShader();
    }

}




//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
