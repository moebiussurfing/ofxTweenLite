#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		
		ofParameterGroup parametersDrawing{"Drawing"};
		ofParameter<float> inPoint{"In",0,0,1};
		ofParameter<float> outPoint{"Out",1,0,1};

		void startTweenIn();
		void startTweenOut();

		// Tween helpers
		ofxTweenLiteHelper<float> inPoint;
		ofxTweenLiteHelper<float> outPoint;
	};
