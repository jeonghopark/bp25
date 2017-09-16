//
//  shaderLine.hpp
//  bp_25
//
//  Created by JeongHo Park on 08.09.17.
//
#pragma once


#ifndef shaderLine_hpp
#define shaderLine_hpp

#include "ofMain.h"
#include "baseScene.hpp"

#include "ofxSvg.h"

class shaderLine : public baseScene{

    struct ImageRatio{
        float cWidth;
        float cHeight;
        
        float xOffSet;
        float yOffSet;
    };


public:

	void setup();
	void update();
	void draw();
    void loadShader();
    void updateShader();

    ofxSVG svg;
    float step;
    float speedDirect;
    vector<ofPolyline> outlines;
    
    void drawLineInShader();
    
    void drawBaseLine(vector<ofPolyline> & outlines);
    void drawBaseVerticalLine(vector<ofPolyline> & outlines);
    void drawBackBaseLine(vector<ofPolyline> & outlines);
    void drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum = 1);

    
    float houseScaleRatio;

    ofImage houseImage;
    ImageRatio imageRatio;
    
    string setName();
	
};

#endif /* shaderLine_hpp */
