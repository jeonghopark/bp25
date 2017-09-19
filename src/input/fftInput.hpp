//  ofxfft
//  fftInput.hpp
//  bp_25
//
//  Created by JeongHo Park on 18.09.17.
//

#pragma once

#ifndef fftInput_hpp
#define fftInput_hpp

#include "ofMain.h"
#include "ofxFft.h"

class fftInput : public ofBaseApp {
public:
    void setup();
    void plot(vector<float>& buffer, float scale, float offset);
    //    void audioReceived(float* input, int bufferSize, int nChannels);
    void draw();
    
    void audioIn( ofSoundBuffer& buffer );
    void audioOut( ofSoundBuffer& buffer );
    ofMutex audioMutex;
    ofSoundBuffer buffer;
    
    ofSoundStream soundStream;

    int plotHeight, bufferSize;
    
    ofxFft* fft;
    
    ofMutex soundMutex;
    vector<float> drawBins, middleBins, audioBins;
};

#endif /* fftInput_hpp */
