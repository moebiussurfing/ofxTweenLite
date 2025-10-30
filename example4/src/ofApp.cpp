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
	params.add(valueParamTweened.set("Tween Progress", 0.0f, 0.0f, 1.0f));

	// Setup tween with name
	tweenRadius.setName("Radius"); // Will load settings from settings_radius.json

	// Setup JSON settings loaded above can be forced and overwritten here
	// tweenRadius.setFrom(0.0f);
	// tweenRadius.setTo(radiusMax);
	// tweenRadius.setDuration(2.0f);
	// tweenRadius.setEase(OF_EASE_QUAD_OUT);

	// Add tween parameters to main group (two valid approaches)
	params.add(tweenRadius.getParameters());
	// params.add(tweenRadius.params_());

	//TODO: this should be handled correctly inside ofxTweenLiteHelper!
	// // Setup callback to ensure exact final value
	// tweenRadius.onCompleteCallback([this]() {
	// 	valueParamTweened.set(1.0f); // Force exact final value when tween completes
	// 	ofLogNotice("ofApp") << "Tween completed - set to 1.0f. tweenRadius value: " << tweenRadius.getValue();
	// });
}

//--------------------------------------------------------------
void ofApp::setupGui() {
	ofLogNotice("ofApp") << "setupGui()";
	gui.setup(params);

	// Refresh GUI to minimize collapse ui folder for advanced params
	//TODO: this should be handled correctly inside ofxTweenLiteHelper!
	// create void refreshGui(ofxPanel & gui)
	// so can be called here tweenRadius.refreshGui(gui);
	auto &g=gui.getGroup(tweenRadius.params.getName());
	g.getGroup(tweenRadius.paramsAdvanced_.getName()).minimize();
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
		valueParamTweened.set(tweenRadius.getProgress());
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
	
	// To save settings
	tweenRadius.exit();
}
