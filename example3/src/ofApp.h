#pragma once

#include "ofMain.h"

#include "ofxTweenLiteHelper.h"

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
