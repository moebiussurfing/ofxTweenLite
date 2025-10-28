#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetCircleResolution(100);
	
	tweenRadius.setFrom(20.0f)
		.setTo(radiusMax)
		.setDuration(2.0f)
		.setEase(OF_EASE_CUBIC_INOUT)
		.setChainFromCurrentValue(false);
	
	tweenRadius.start();
	
	gui.setup();
	gui.add(inPoint.set("In Point", 0.0f, 0.0f, 1.0f));
	
}

//--------------------------------------------------------------
void ofApp::update(){
	tweenRadius.update();
	if(tweenRadius.isRunning()){
		inPoint.set(tweenRadius.getProgress());
//		inPoint.set(tweenRadius.getValue());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	float radius = tweenRadius.getValue();
	glm::vec2 pos = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
	ofSetColor(255);
	ofFill();
	ofDrawCircle(pos.x, pos.y, radius);
	ofSetColor(255,50);
	ofNoFill();
	ofDrawCircle(pos.x, pos.y, radiusMax);
	ofDrawCircle(pos.x, pos.y, 4);
	
	gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	tweenRadius.start();
}
