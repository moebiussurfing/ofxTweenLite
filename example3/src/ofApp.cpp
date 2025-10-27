#include "ofApp.h"
#include "ofxTweenLite.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(30);

	// Configure start / end positions based on current window size
	posStart = glm::vec2(100, ofGetHeight() / 2.0f);
	posEnd = glm::vec2(ofGetWidth() - 100, ofGetHeight() / 2.0f - 100);

	// Radius tween: from small to large
	tweenRadius.setFrom(20.0f)
			   .setTo(80.0f)
			   .setDuration(2.0f)
			   .setEase(getEaseModes()[easeIndex])
			   .setChainFromCurrentValue(false);

	// Position tween: from left to right
	tweenPosition.setFrom(posStart)
				 .setTo(posEnd)
				 .setDuration(2.0f)
				 .setEase(getEaseModes()[easeIndex])
				 .setChainFromCurrentValue(false);

	// Color tween: from red to blue
	tweenColor.setFrom(ofColor(255,100,100))
			  .setTo(ofColor(100,150,255))
			  .setDuration(2.0f)
			  .setEase(getEaseModes()[easeIndex])
			  .setChainFromCurrentValue(false);

	// Start all tweens
	tweenRadius.start();
	tweenPosition.start();
	tweenColor.start();
}

//--------------------------------------------------------------
void ofApp::update(){
	// Update tweens
	tweenRadius.update();
	tweenPosition.update();
	tweenColor.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(30);

	// Get values
	float radius = tweenRadius.getValue();
	glm::vec2 pos = tweenPosition.getValue();
	ofColor col = tweenColor.getValue();

	ofSetColor(col);
	ofFill();
	ofDrawCircle(pos.x, pos.y, radius);
	
	// Start to end line
	ofSetColor(128, 128);
	ofDrawCircle(posStart, 4);
	ofDrawCircle(posEnd, 4);
	ofDrawLine(posStart, posEnd);

	// UI text
	ofSetColor(255);
	ofDrawBitmapString("Press 'c' to toggle chain mode (applies to all tweens)", 20, 20);
	ofDrawBitmapString("Press SPACE to restart tweens", 20, 40);
	ofDrawBitmapString("Up/Down: change ease mode", 20, 60);
	ofDrawBitmapString("Current Ease: " + getEaseNames()[easeIndex], 20, 80);
	ofDrawBitmapString("Chain mode: " + std::string(tweenRadius.getChainFromCurrentValue() ? "ON" : "OFF"), 20, 100);
	
	// Draw progress bar
	float h= 20;
	float y=ofGetHeight()-h;
	ofSetColor(255, 100);
	ofFill();
	ofDrawRectangle(0, y ,tweenPosition.getProgress()*ofGetWidth(), y);
	ofNoFill();
	ofDrawRectangle(0, y ,ofGetWidth(), y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == OF_KEY_UP){
		easeIndex++;
		if(easeIndex >= (int)getEaseModes().size()) easeIndex = 0;
		// update ease for all tweens and restart
		tweenRadius.setEase(getEaseModes()[easeIndex]);
		tweenPosition.setEase(getEaseModes()[easeIndex]);
		tweenColor.setEase(getEaseModes()[easeIndex]);
		// Restart from initial starts
		tweenRadius.start();
		tweenPosition.start();
		tweenColor.start();
	} else if(key == OF_KEY_DOWN){
		easeIndex--;
		if(easeIndex < 0) easeIndex = (int)getEaseModes().size() - 1;
		tweenRadius.setEase(getEaseModes()[easeIndex]);
		tweenPosition.setEase(getEaseModes()[easeIndex]);
		tweenColor.setEase(getEaseModes()[easeIndex]);
		tweenRadius.start();
		tweenPosition.start();
		tweenColor.start();
	} else if (key == 'c' || key == 'C'){
		bool newChainMode = !tweenRadius.getChainFromCurrentValue();
		tweenRadius.setChainFromCurrentValue(newChainMode);
		tweenPosition.setChainFromCurrentValue(newChainMode);
		tweenColor.setChainFromCurrentValue(newChainMode);
	} else if (key == ' '){
		// Restart tweens; start() semantics: if stopped -> start from initialFrom; if running -> honor chain flag
		tweenRadius.start();
		tweenPosition.start();
		tweenColor.start();
	}
}
