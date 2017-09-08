#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"


//========================================================================
int main( ){
//    ofSetupOpenGL(540, 864, OF_WINDOW);            // <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

    ofGLFWWindowSettings settings;
    
    settings.width = 550;       // 625  / 550
    settings.height = 880;      // 1000 / 880
    settings.setPosition(ofVec2f(0, 0));
    settings.decorated = false;
    settings.windowMode = OF_WINDOW;
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 300;
    settings.height = 700;
    settings.setPosition(ofVec2f(0,0));
    settings.setPosition(ofVec2f(600, 0));
    settings.decorated = true;
    settings.windowMode = OF_WINDOW;
    settings.resizable = true;
    // uncomment next line to share main's OpenGL resources with gui
    //settings.shareContextWith = mainWindow;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
//    guiWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->GM.setupGui();
    ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawGui);

    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();

}


