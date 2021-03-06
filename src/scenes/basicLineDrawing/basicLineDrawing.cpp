//
//  basicLineDrawing.cpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//

#include "basicLineDrawing.hpp"


//--------------------------------------------------------------
void basicLineDrawing::setup(){
    
    svg.load("fassade_apotheke_10x16.svg");
    for (int i = 0; i < svg.getNumPath(); i++){
        ofPath p = svg.getPathAt(i);
        p.setPolyWindingMode(OF_POLY_WINDING_ODD);
        vector<ofPolyline>& lines = const_cast<vector<ofPolyline>&>(p.getOutline());
        for(int j=0;j<(int)lines.size();j++){
            outlines.push_back(lines[j].getResampledBySpacing(1));
        }
    }
    
    houseScaleRatio = 0.45;
    
    houseImage.load("fassade_apotheke_10x16.png");
    //    houseBlankImage
    
    //    jsonLoad();
    
    imageRatio.cWidth = houseImage.getWidth() * houseScaleRatio;
    imageRatio.cHeight = houseImage.getHeight() * houseScaleRatio;
    imageRatio.xOffSet = (ofGetWidth() - imageRatio.cWidth) * 0.5;
    imageRatio.yOffSet = (ofGetHeight() - imageRatio.cHeight) * 0.5;
    
    step = 0;
    speedDirect = 0.01;
    
}


//--------------------------------------------------------------
void basicLineDrawing::update(){
    
    updateName();

    if (GM->motion) {
        if (step > 0.99) {
            speedDirect = -0.01;
        } else if ( step < 0 ) {
            speedDirect = 0.01;
        }
        
        step = step + speedDirect * GM->motionSpeed;
    } else {
        step = 0;
        speedDirect = 0.01;
    }
    
    
}


//--------------------------------------------------------------
void basicLineDrawing::draw(){
    
    ofPushStyle();
    ofNoFill();
    ofSetColor(255, 0, 0);
    ofPushMatrix();
    ofTranslate(imageRatio.xOffSet, imageRatio.yOffSet);
    
    
    drawBaseLine(outlines);
    drawBaseVerticalLine(outlines);
    drawBackBaseLine(outlines);
    drawBackBaseLineRepeat(outlines, 1);
    
    ofPopMatrix();
    ofPopStyle();
    
    
}



//--------------------------------------------------------------
void basicLineDrawing::drawBaseLine(vector<ofPolyline> & outlines){
    
    ofPushStyle();
    ofSetColor(255, 0, 0, 255);
    for (int i = 0; i < (int)outlines.size(); i++){
        ofPolyline & _line = outlines[i];
        
        int _num = step * _line.size();
        
        ofBeginShape();
        for (int j = 0; j < _num; j++){
            ofVertex(_line[j] * houseScaleRatio * 0.8);
        }
        ofEndShape();
    }
    ofPopStyle();

}



//--------------------------------------------------------------
void basicLineDrawing::drawBaseVerticalLine(vector<ofPolyline> & outlines){
    
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
void basicLineDrawing::drawBackBaseLine(vector<ofPolyline> & outlines){
    
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
void basicLineDrawing::drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum){
    
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
string basicLineDrawing::setName(){
    
    return "basicLineDrawing";
    
}


