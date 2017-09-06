#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setupGui(){
    parameters.setName("parameters");
    parameters.add(houseView.set("House View", false));
    parameters.add(motion.set("Motion", false));
    parameters.add(motionSpeed.set("Motion Speed", 1, 0.3, 5));
    gui.setup(parameters);
    ofSetBackgroundColor(0);
}


//--------------------------------------------------------------
void ofApp::drawGui(ofEventArgs & args){
    gui.draw();
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    SM.scenes.push_back( new basicLineDrawing() );
    SM.setup();
    
}



//--------------------------------------------------------------
void ofApp::update(){
    
    SM.update();
    
}




//--------------------------------------------------------------
void ofApp::draw(){
    
    SM.draw();
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
