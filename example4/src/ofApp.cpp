#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofLogNotice("ofApp") << "setup()";
	ofSetCircleResolution(100);

	setupParameters();
	setupGui();
	startup();
}

//--------------------------------------------------------------
void ofApp::setupParameters() {
	ofLogNotice("ofApp") << "setupParameters()";

	// Setup main parameter group
	params.setName("Example4");
	params.add(valueTweened.set("Progress", 0.0f, 0.0f, 1.0f));

	// Setup tween with name
	tweenRadius.setName("Radius");
	tweenRadius.setFrom(0.0f);
	tweenRadius.setTo(radiusMax);
	tweenRadius.setDuration(2.0f);
	tweenRadius.setEase(OF_EASE_QUAD_OUT);

	// Add tween parameters to main group
	params.add(tweenRadius.getParameters());

	// Setup callback to ensure exact final value
	tweenRadius.onCompleteCallback([this]() {
		valueTweened.set(1.0f); // Force exact final value when tween completes
		ofLogNotice("ofApp") << "Tween completed - set to 1.0f";
	});
}

//--------------------------------------------------------------
void ofApp::setupGui() {
	ofLogNotice("ofApp") << "setupGui()";
	gui.setup(params);
}

//--------------------------------------------------------------
void ofApp::startup() {
	ofLogNotice("ofApp") << "startup()";
	
	// Load settings
	tweenRadius.loadSettings();
	
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
	
	// Save settings
	tweenRadius.saveSettings();
}
