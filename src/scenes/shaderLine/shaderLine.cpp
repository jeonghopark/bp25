//
//  shaderLine.cpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//

#include "shaderLine.hpp"


//--------------------------------------------------------------
void shaderLine::setup(){

    loadShader();


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

    houseImage.load("fassade_apotheke_alpha.png");

	imageRatio.cWidth = houseImage.getWidth() * houseScaleRatio;
	imageRatio.cHeight = houseImage.getHeight() * houseScaleRatio;
	imageRatio.xOffSet = (ofGetWidth() - imageRatio.cWidth) * 0.5;
	imageRatio.yOffSet = (ofGetHeight() - imageRatio.cHeight) * 0.5;

	step = 1;
	speedDirect = 0.01;

}



//--------------------------------------------------------------
void shaderLine::update(){

	if (GM->motion) {
		if (step > 0.99) {
			speedDirect = -0.01;
		} else if ( step < 0 ) {
			speedDirect = 0.01;
		}

//        step = step + speedDirect *;
	} else {
		step = 0;
		speedDirect = 0.01;
	}

    updateName();
    
}



//--------------------------------------------------------------
void shaderLine::updateShader(){
    
    shaderFbo.begin();
    ofClear(0, 0, 0, 0);
    shader.begin();
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
    
    shader.setUniform1f("u_control01", ofGetElapsedTimef());
    shader.setUniform1f("u_control02", ofGetElapsedTimef());
    shader.setUniform1f("u_control03", ofGetElapsedTimef());
    shader.setUniform1f("u_control04", ofGetElapsedTimef());
    shader.setUniform1f("u_control05", ofGetElapsedTimef());
    shader.setUniform1f("u_control06", ofGetElapsedTimef());
    shader.setUniform1f("u_control07", ofGetElapsedTimef());
    shader.setUniform1f("u_control08", ofGetElapsedTimef());
    shader.setUniform1f("u_control09", ofGetElapsedTimef());
    shader.setUniform1f("u_control10", ofGetElapsedTimef());
    
    //    ofDrawRectangle(0,0,ofGetWidth(), ofGetHeight());
    
    drawLineInShader();
    
    shader.end();
    shaderFbo.end();
    
};



//--------------------------------------------------------------
void shaderLine::draw(){

    drawGlitch();
    
}


//--------------------------------------------------------------
void shaderLine::drawLineInShader(){
    
    ofPushMatrix();
    ofTranslate(imageRatio.xOffSet, imageRatio.yOffSet);
    
    ofNoFill();
    drawBaseLine(outlines);
    drawBaseVerticalLine(outlines);
    drawBackBaseLine(outlines);
    drawBackBaseLineRepeat(outlines, 3);
    
    ofPopMatrix();
    
}



//--------------------------------------------------------------
void shaderLine::drawBaseLine(vector<ofPolyline> & outlines){

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
void shaderLine::drawBaseVerticalLine(vector<ofPolyline> & outlines){

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
void shaderLine::drawBackBaseLine(vector<ofPolyline> & outlines){

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
void shaderLine::drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum){

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
string shaderLine::setName(){
    
    return shaderFile.getBaseName();
    
}


//--------------------------------------------------------------
void shaderLine::loadShader(){
    shaderFile.open("shader/shaderLine.frag");
    shader.load("shader/shaderLine.vert", shaderFile);
}



