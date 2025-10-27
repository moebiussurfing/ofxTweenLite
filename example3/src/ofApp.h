#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);

	// Tweens for advanced example
	ofxTweenLiteHelper<float> tweenRadius;
	ofxTweenLiteHelper<glm::vec2> tweenPosition;
	ofxTweenLiteHelper<ofColor> tweenColor;

	// Easing selector
	int easeIndex = 10; // Default: CubicInOut
	static const std::vector<ofEaseFunction>& getEaseModes() {
		return ofxTweenLiteHelper<float>::getAllEaseModes();
	}
	static const std::vector<std::string>& getEaseNames() {
		return ofxTweenLiteHelper<float>::getAllEaseNames();
	}
};
