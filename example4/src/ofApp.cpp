#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofLogNotice("ofApp") << "setup()";
	ofSetCircleResolution(100);

	// Setup GUI
	gui.setup("Tween Example");
	gui.add(valueTweened.set("Progress", 0.0f, 0.0f, 1.0f));

	// Setup tween
	tweenRadius.setFrom(0.0f);
	tweenRadius.setTo(radiusMax);
	tweenRadius.setDuration(2.0f);
	tweenRadius.setEase(OF_EASE_QUAD_OUT);

	// Setup callback to ensure exact final value
	tweenRadius.onCompleteCallback([this]() {
		valueTweened.set(1.0f); // Force exact final value when tween completes
		ofLogNotice("ofApp") << "Tween completed - set to 1.0f";
	});

	// Start the tween
	tweenRadius.start();
}

//--------------------------------------------------------------
void ofApp::update() {
	tweenRadius.update();
	if (tweenRadius.isRunning()) {
		valueTweened.set(tweenRadius.getProgress());
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(50);

	// Draw circle with tweened radius
	ofSetColor(255, 100, 100);
	ofFill();
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, tweenRadius.getValue());

	// Circle max radius outline
	ofSetColor(255, 100);
	ofNoFill();
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, radiusMax);

	// Draw GUI
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	ofLogNotice("ofApp") << "keyPressed() " << char(key);
	if (key == ' ') {
		// Restart tween on spacebar
		tweenRadius.start();
	}
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofLogNotice("ofApp") << "exit()";
}
