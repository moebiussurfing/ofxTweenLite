#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"

class ofApp : public ofBaseApp{
public:
 void setup();
 void update();
 void draw();

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

 // Tween example variables
 float startX, endX;
 ofxTweenLiteHelper<float> tween;
 std::function<void()> onTweenComplete;
 
 // Ease mode selector
 int currentEaseIdx;

 // Background color
 ofColor bgColor;
};
