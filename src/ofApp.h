#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxSvg.h"

class ofApp : public ofBaseApp{
    
    struct ImageRatio{
        float cWidth;
        float cHeight;
        
        float xOffSet;
        float yOffSet;
    };

public:
    void setup();
    void setupGui();
    void update();
    void draw();
    void drawGui(ofEventArgs & args);
    
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofJson jsHouseObjectPoint;
    void jsonLoad();
    
    vector<ofVec2f> houseObjectPoint;
    
    ofImage houseImage;
    ofImage houseBlankImage;
    
    void houseImageDraw();
    float houseScaleRatio;
    
    void basePointsDraw();
    
    void drawBaseLine(vector<ofPolyline> & outlines);
    void drawBaseVerticalLine(vector<ofPolyline> & outlines);
    void drawBackBaseLine(vector<ofPolyline> & outlines);
    void drawBackBaseLineRepeat(vector<ofPolyline> & outlines, int layerNum = 1);
    
    ImageRatio imageRatio;
    
    ofxSVG svg;
    float step;
    float speedDirect;
    vector<ofPolyline> outlines;
    
    // GUI
    ofParameterGroup parameters;
    ofParameter<bool> motion;
    ofParameter<bool> houseView;
    ofParameter<float> motionSpeed;
    ofxPanel gui;
    

    
};

