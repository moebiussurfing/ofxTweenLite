#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"

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
