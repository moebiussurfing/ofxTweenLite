#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"

/*
//#define USE_OFX_GUI__OFX_TWEEN_LITE_HELPER // -> comment in ofxTweenLiteHelper.h as we are not using ofxGui in this project
*/

//TODO: Must fix: Currently non based ofParams examples seems broken..

class ofApp : public ofBaseApp{
    public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    
    // Tween example variables
    float startX, endX;
    ofxTweenLiteHelper<float> tween;
    std::function<void()> onTweenComplete;
    
    // Background color
    ofColor bgColor;
};
