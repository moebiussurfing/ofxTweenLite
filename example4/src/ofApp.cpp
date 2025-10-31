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

	valueParamTweened.set("TweenValue", 0.0f, 0.0f, radiusMax);

	// Setup main parameter group
	params.setName("Example4");
	params.add(valueParamTweened);

	tweenRadius.setupLinkParameter(valueParamTweened);

	//--

	// Add tween parameters to main group (two valid approaches)
	params.add(tweenRadius.getParameters());
	// params.add(tweenRadius.params_);

	// Setup user callback for custom behavior (e.g., state machine, workflow)
	tweenRadius.onUserCompleteCallback([this]() {
		ofLogNotice("ofApp") << "User callback: Tween completed! Value: " << tweenRadius.getValue();
		// You can add custom behavior here, change states, trigger other tweens, etc.
	});
}

//--------------------------------------------------------------
void ofApp::setupGui() {
	ofLogNotice("ofApp") << "setupGui()";
	gui.setup(params);

	// Refresh GUI to minimize Advanced parameters group
	tweenRadius.refreshGui(gui);
}

//--------------------------------------------------------------
void ofApp::startup() {
	ofLogNotice("ofApp") << "startup()";
	
	// Start the tween
	tweenRadius.start();
}

//--------------------------------------------------------------
void ofApp::update() {
	tweenRadius.update();
	if (tweenRadius.isRunning()) {
		valueParamTweened.set(tweenRadius.getValue());
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(50);

	// Draw circle with tweened radius
	ofSetColor(255, 100, 100);
	ofFill();
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, valueParamTweened.get());

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
	
	// To save settings
	tweenRadius.exit();
}
