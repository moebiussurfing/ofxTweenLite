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

	// Init here the tween helper as float type
	ofxTweenLiteHelper<float> tweener; 
	
	ofParameter<float> valueParam;

	float radiusMax = 200;

	ofParameterGroup params;
	ofxPanel gui;
};
