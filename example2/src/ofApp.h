#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"

class ofApp : public ofBaseApp{
public:
 void setup();
 void update();
 void draw();

 void keyPressed(int key);

 // Tween example variables
 float startX, endX;
 ofxTweenLiteHelper<float> tween;
 std::function<void()> onTweenComplete;
 
 // Ease mode selector
 int currentEaseIdx;

 // Background color
 ofColor bgColor;
};
