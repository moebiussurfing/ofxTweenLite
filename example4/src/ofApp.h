#pragma once
#include "ofMain.h"
#include "ofxGui.h"
#include "ofxTweenLiteHelper.h"

class ofApp : public ofBaseApp {

public:
	void setup() override;
	void update() override;
	void draw() override;
	void exit() override;
	void keyPressed(int key) override;

private:
	void setupParameters();
	void setupGui();
	void startup();

	ofxTweenLiteHelper<float> tweener; // Init here the tween helper float type

	float radiusMax = 200;

	ofParameter<float> valueParam;
	ofParameterGroup params;
	ofxPanel gui;
};
