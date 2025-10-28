#pragma once

#include "ofMain.h"
#include "ofxTweenLiteHelper.h"
class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
	ofxTweenLiteHelper<float> tweenRadius;
		
};
