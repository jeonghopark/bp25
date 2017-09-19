//
//  fftInput.cpp
//  bp_25
//
//  Created by JeongHo Park on 18.09.17.
//

#include "fftInput.hpp"


//--------------------------------------------------------------
void fftInput::setup() {
    ofSetVerticalSync(true);
    
    plotHeight = 128;
    bufferSize = 512;
    
    fft = ofxFft::create(bufferSize, OF_FFT_WINDOW_HAMMING);
    // To use FFTW, try:
    //fft = ofxFft::create(bufferSize, OF_FFT_WINDOW_HAMMING, OF_FFT_FFTW);
    
    drawBins.resize(fft->getBinSize());
    middleBins.resize(fft->getBinSize());
    audioBins.resize(fft->getBinSize());
    
//    soundStream.printDeviceList();
    ofSoundStreamSettings settings;
    
    auto devices = soundStream.getMatchingDevices("OSX Core Audio");
    if(!devices.empty()){
        settings.setInDevice(devices[2]);
        settings.setOutDevice(devices[1]);
    }
    
    settings.setInListener(this);
    settings.setOutListener(this);
    settings.sampleRate = 44100;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 2;
    settings.bufferSize = bufferSize;
    soundStream.setup(settings);
    
    
    
    ofBackground(0, 0, 0);
}



//--------------------------------------------------------------
void fftInput::draw() {
//    ofSetColor(255);
//    ofPushMatrix();
//    ofTranslate(16, 16);
    
    soundMutex.lock();
    drawBins = middleBins;
    soundMutex.unlock();
    
//    ofDrawBitmapString("Frequency Domain", 0, 0);
//    plot(drawBins, -plotHeight, plotHeight / 2);
//    ofPopMatrix();
//    string msg = ofToString((int) ofGetFrameRate()) + " fps";
//    ofDrawBitmapString(msg, ofGetWidth() - 80, ofGetHeight() - 20);
}



//--------------------------------------------------------------
void fftInput::plot(vector<float>& buffer, float scale, float offset) {
    ofNoFill();
    int n = buffer.size();
    ofDrawRectangle(0, 0, n, plotHeight);
    glPushMatrix();
    glTranslatef(0, plotHeight / 2 + offset, 0);
    ofBeginShape();
    for (int i = 0; i < n; i++) {
        ofVertex(i, sqrt(buffer[i]) * scale);
    }
    ofEndShape();
    glPopMatrix();
}


//--------------------------------------------------------------
void fftInput::audioIn(ofSoundBuffer & buffer){
    ofScopedLock lock(audioMutex);
    this->buffer = buffer;
    
    float maxValue = 0;
    for(int i = 0; i < bufferSize; i++) {
        if(abs(buffer[i]) > maxValue) {
            maxValue = abs(buffer[i]);
        }
    }
    for(int i = 0; i < bufferSize; i++) {
        buffer[i] /= maxValue;
    }
    
    fft->setSignal(&buffer[0]);
    
    float* curFft = fft->getAmplitude();
    memcpy(&audioBins[0], curFft, sizeof(float) * fft->getBinSize());
    
    maxValue = 0;
    for(int i = 0; i < fft->getBinSize(); i++) {
        if(abs(audioBins[i]) > maxValue) {
            maxValue = abs(audioBins[i]);
        }
    }
    for(int i = 0; i < fft->getBinSize(); i++) {
        audioBins[i] /= maxValue;
    }
    
    soundMutex.lock();
    middleBins = audioBins;
    soundMutex.unlock();
}


//--------------------------------------------------------------
void fftInput::audioOut( ofSoundBuffer& buffer ){
    ofScopedLock lock(audioMutex);
    this->buffer.copyTo(buffer);
}

