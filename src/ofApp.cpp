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
    
    svg.load("fassade_apotheke_10x16.svg");
    for (int i = 0; i < svg.getNumPath(); i++){
        ofPath p = svg.getPathAt(i);
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
        for(int j=0;j<(int)lines.size();j++){
            outlines.push_back(lines[j].getResampledBySpacing(1));
        }
    }
    
    
    ofBackground(0);
    
    houseScaleRatio = 0.45;
    
    houseImage.load("fassade_apotheke_10x16.png");
//    houseBlankImage
   
    jsonLoad();
    
    imageRatio.cWidth = houseImage.getWidth() * houseScaleRatio;
    imageRatio.cHeight = houseImage.getHeight() * houseScaleRatio;
    imageRatio.xOffSet = (ofGetWidth() - imageRatio.cWidth) * 0.5;
    imageRatio.yOffSet = (ofGetHeight() - imageRatio.cHeight) * 0.5;
    
    step = 0;
    speedDirect = 0.01;
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    if (!motion) {
        if (step > 0.99) {
            speedDirect = -0.01;
        } else if ( step < 0 ) {
            speedDirect = 0.01;
        }
        
        step = step + speedDirect * motionSpeed;
    } else {
        step = 0;
        speedDirect = 0.01;
    }
    
}



//--------------------------------------------------------------
void ofApp::draw(){
    
    if (houseView) {
        houseImageDraw();
    }

//    basePointsDraw();
    
    ofPushStyle();
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofPushMatrix();
    ofTranslate(imageRatio.xOffSet, imageRatio.yOffSet);
    
    
    drawBaseLine(outlines);
    drawBaseVerticalLine(outlines);
    drawBackBaseLine(outlines);
    drawBackBaseLineRepeat(outlines, 3);
    
    ofPopMatrix();
    ofPopStyle();
    

}



//--------------------------------------------------------------
void ofApp::drawBaseLine(vector<ofPolyline> & outlines){
    
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & _line = outlines[i];
        
        int _num = step * _line.size();
        
        ofBeginShape();
        for (int j = 0; j < _num; j++){
            ofVertex(_line[j] * houseScaleRatio * 0.8);
        }
        ofEndShape();
        
    }
    
}



//--------------------------------------------------------------
void ofApp::drawBaseVerticalLine(vector<ofPolyline> & outlines){
    
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & _line = outlines[i];
        
        int _numLength = _line.size();
        
        ofPushStyle();
        ofSetColor(255, 0, 0, 120);
        
        for ( int j = 0; j < _numLength; j+=(_line.size()/10) ) {
            float _x = _line[j].x * houseScaleRatio * 0.8;
            float _y = _line[j].y * houseScaleRatio * 0.8;
            
            ofDrawLine(_x, _y, 0, _x, _y, -100);
        }
        ofPopStyle();
        
    }
    
}



//--------------------------------------------------------------
void ofApp::drawBackBaseLine(vector<ofPolyline> & outlines){
    
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & _line = outlines[i];
        
        
        int _num = step * _line.size();
        
        ofPushStyle();
        ofSetColor(255, 0, 0, 120);
        ofBeginShape();
        for (int j = 0; j < _num; j++){
            ofVertex(_line[j] * houseScaleRatio * 0.8 + ofVec3f(0, 0, -100));
        }
        ofEndShape();
        ofPopStyle();
        
    }
    
}



//--------------------------------------------------------------
void ofApp::drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum){
    
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & _line = outlines[i];
        
        int _num = step * _line.size();
        
        ofPushStyle();
        ofSetColor(255, 0, 0, 120);
        for (int k=0; k<layerNum; k++) {
            ofBeginShape();
            for (int j = 0; j < _num; j+=10){
                ofVertex(_line[j] * houseScaleRatio * 0.8 + ofVec3f(0, 0, -100 * k));
            }
            ofEndShape();
        }
        ofPopStyle();
        
    }
    
}



//--------------------------------------------------------------
void ofApp::basePointsDraw(){
    
    ofPushStyle();
    
    ofSetColor(0, 255, 0);
    
    for(auto & p : houseObjectPoint) {
        ofDrawEllipse(p, 3, 3);
    }
    
    ofPopStyle();
    
}



//--------------------------------------------------------------
void ofApp::houseImageDraw(){
    
    
    houseImage.draw(imageRatio.xOffSet, imageRatio.yOffSet, imageRatio.cWidth, imageRatio.cHeight);
    
    
}


//--------------------------------------------------------------
void ofApp::jsonLoad(){
    
    houseObjectPoint.clear();
    
    
    ofFile file("jsHouseObjectPoint.json");
    if(file.exists()){
        file >> jsHouseObjectPoint;
        for(auto & point: jsHouseObjectPoint){
            if(!point.empty()){
                for(auto & p: point){
                    float _x = (float)p["x"] * houseScaleRatio;
                    float _y = (float)p["y"] * houseScaleRatio;
                    houseObjectPoint.push_back(ofVec2f(_x + imageRatio.xOffSet, _y + imageRatio.yOffSet));
                }
            }
        }
    }
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    switch(key) {
        case 114: // key : r
            jsonLoad();
            break;
    }
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
