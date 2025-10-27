#pragma once

#include "ofMain.h"
#include "ofxTweenLite.h"

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

		// Tween demo variables
		float startX;
		float endX;
		float currentX;
		float progress;
		float duration;
		float startTime;
		int easeMode; // index for current ease mode

		// Helper for ease mode name
		std::string getEaseModeName(int mode);
};
