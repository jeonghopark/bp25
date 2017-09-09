//
//  basicLineDrawing.hpp
//  bp2.5
//
//  Created by JeongHo Park on 06.09.17.
//
#pragma once

#ifndef basicLineDrawing_hpp
#define basicLineDrawing_hpp

#include "ofMain.h"
#include "baseScene.hpp"

#include "ofxSvg.h"



class basicLineDrawing : public baseScene{
    
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
    
    ofxSVG svg;
    float step;
    float speedDirect;
    vector<ofPolyline> outlines;
    
    void drawBaseLine(vector<ofPolyline> & outlines);
    void drawBaseVerticalLine(vector<ofPolyline> & outlines);
    void drawBackBaseLine(vector<ofPolyline> & outlines);
    void drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum = 1);

    
    float houseScaleRatio;

    ofImage houseImage;
    ImageRatio imageRatio;

    
};


#endif /* basicLineDrawing_hpp */
