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

	valueParam.set("ValueParam", 0.0f, 0.0f, radiusMax);
	
	// Tweener setup with linked parameter
	tweener.setupParameter(valueParam);
	
	// Force overwrite settings can be done here if needed
	// tweener.setFrom(0.0f).setTo(radiusMax).setDuration(2.0f).setEase(OF_EASE_QUAD_IN_OUT);

	//--

	// Setup main parameter group
	params.setName("Example4");
	params.add(valueParam);
	
	// Add tween parameters to main group for GUI
	params.add(tweener.getParameters());

	//--

	// Setup user callback for custom behavior (e.g., state machine, workflow)
	tweener.onUserCompleteCallback([this]() {
		ofLogNotice("ofApp") << "User callback: Tween completed! Value: " << tweener.getValue();
		// You can add custom behavior here, change states, trigger other tweens, etc.
	});
}

//--------------------------------------------------------------
void ofApp::setupGui() {
	ofLogNotice("ofApp") << "setupGui()";
	gui.setup(params);

	// Refresh GUI to minimize Advanced parameters group
	tweener.refreshGui(gui);
}

//--------------------------------------------------------------
void ofApp::startup() {
	ofLogNotice("ofApp") << "startup()";
	
	// Start the tween
	tweener.start();
}

//--------------------------------------------------------------
void ofApp::update() {
	tweener.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(50);

	// Draw circle with tweened radius
	ofSetColor(255, 100, 100);
	ofFill();
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, valueParam.get());

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
		tweener.start();
	}
}

//--------------------------------------------------------------
void ofApp::exit() {
	ofLogNotice("ofApp") << "exit()";
	
	// To save settings
	tweener.exit();
}
