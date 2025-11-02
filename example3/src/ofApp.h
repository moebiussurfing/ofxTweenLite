#pragma once

#include "ofMain.h"

#include "ofxTweenLiteHelper.h"

/*
//#define USE_OFX_GUI__OFX_TWEEN_LITE_HELPER // -> comment in ofxTweenLiteHelper.h as we are not using ofxGui in this project
*/

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);

	// Tweens for advanced example
	ofxTweenLiteHelper<float> tweenRadius;
	ofxTweenLiteHelper<glm::vec2> tweenPosition;
	ofxTweenLiteHelper<ofColor> tweenColor;
	
	glm::vec2 posStart;
	glm::vec2 posEnd;
};
