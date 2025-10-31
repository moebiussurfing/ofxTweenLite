#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	startX = 100;
	endX = 700;

	// Initial background color
	bgColor = ofColor::white;

	// External lambda callback
	onTweenComplete = [this]() {
		ofLog() << "Tween finished!";
		bgColor = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	};

	// Start tween with selected ease mode and external callback
	tween.setFrom(startX).setTo(endX).setDuration(2.0f).onCompleteCallback(onTweenComplete);
	
	//TODO: Must fix: Allow parameter setup and settings handling
	// tween.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
	tween.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofClear(bgColor);

	// Tween ball
	ofSetColor(0);
	ofDrawCircle(tween.getValue(), ofGetHeight() / 2, 40);

	// Points start/end
	ofSetColor(128, 200);
	ofDrawCircle(startX, ofGetHeight() / 2, 4);
	ofDrawCircle(endX, ofGetHeight() / 2, 4);
	ofDrawLine(startX, ofGetHeight() / 2, tween.getValue(), ofGetHeight() / 2);
	
	// Ball center
	ofSetColor(255, 200);
	ofDrawCircle(tween.getValue(), ofGetHeight() / 2, 2);

	// Draw progress bar
	float barWidth = endX-startX;
	float barHeight = 25;
	float barX = startX;
	float barY = ofGetHeight() - 80;
	float progress = tween.getProgress();

	ofSetColor(200);
	ofDrawRectangle(barX, barY, barWidth, barHeight);
	ofSetColor(0);
	ofDrawRectangle(barX, barY, barWidth * progress, barHeight);
	ofSetColor(0);
	ofDrawBitmapStringHighlight("Progress: " + ofToString((int)(progress * 100)) + "%", barX + barWidth + 10, barY + barHeight / 2 + 5);

	// Draw instructions and ease mode
	ofSetColor(0);
	ofDrawBitmapStringHighlight("Press SPACE to restart animation", 20, 30);
	ofDrawBitmapStringHighlight("Use LEFT/RIGHT arrows to change ease mode", 20, 50);
	ofDrawBitmapStringHighlight("Current ease mode: " + tween.getCurrentEaseName(), 20, 70);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

	if (key == ' ') {
		tween.start();
	}
	if (key == OF_KEY_LEFT) {
		tween.previousEaseType();
		tween.start();
	}
	if (key == OF_KEY_RIGHT) {
		tween.nextEaseType();
		tween.start();
	}
}

//--------------------------------------------------------------
void ofApp::exit() {
	tween.exit();
}
