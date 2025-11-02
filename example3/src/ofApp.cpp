#include "ofApp.h"
#include "ofxTweenLite.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(30);
	
	// Configure start / end positions based on current window size
	posStart = glm::vec2(100, ofGetHeight() / 2.0f);
	posEnd = glm::vec2(ofGetWidth() - 100, ofGetHeight() / 2.0f - 100);

	// Setup all tweens (unique name for json settings filename will be auto generated)
	tweenRadius.setup();
	tweenPosition.setup();
	tweenColor.setup();

	// Radius tween: from small to large
	tweenRadius.setFrom(20.0f)
		.setTo(80.0f)
		.setDuration(2.0f)
		.setChainFromCurrentValue(false);
	
	// Position tween: from left to right
	tweenPosition.setFrom(posStart)
		.setTo(posEnd)
		.setDuration(2.0f)
		.setChainFromCurrentValue(false);
	
	// Color tween: from red to blue
	tweenColor.setFrom(ofColor(255,100,100))
		.setTo(ofColor(100,150,255))
		.setDuration(2.0f)
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
	int h =20;
	int y =40;
	ofDrawBitmapString("Press SPACE to restart tweens", 20, y);
	ofDrawBitmapString("Up/Down: change ease mode", 20, y=y+h);
	ofDrawBitmapString("Ease: " + tweenRadius.getCurrentEaseName(), 20, y=y+h);
	
	// Draw progress bar
	float hh= 20;
	float yy=ofGetHeight()-h;
	ofSetColor(255, tweenRadius.isRunning()?220: 40);
	ofFill();
	ofDrawRectangle(0, yy ,tweenPosition.getProgress()*ofGetWidth(), yy);
	ofNoFill();
	ofDrawRectangle(0, yy ,ofGetWidth(), yy);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == OF_KEY_UP){
		tweenRadius.nextEaseType();
		tweenPosition.nextEaseType();
		tweenColor.nextEaseType();
	} 
	else if(key == OF_KEY_DOWN){
		tweenRadius.previousEaseType();
		tweenPosition.previousEaseType();
		tweenColor.previousEaseType();
	} 
	else if (key == ' '){
		// Restart tweens; start() semantics: if stopped -> start from initialFrom; if running -> honor chain flag
		tweenRadius.start();
		tweenPosition.start();
		tweenColor.start();
	}
}

//--------------------------------------------------------------
void ofApp::exit(){
	// Exit tweens to save json settings
	tweenRadius.exit();
	tweenPosition.exit();
	tweenColor.exit();
}
