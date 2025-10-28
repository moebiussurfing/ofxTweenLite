#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofsetics::setBackgroundColor(100);
	
	tweenRadius.setFrom(20.0f)
		.setTo(80.0f)
		.setDuration(2.0f)
		.setEase(OF_EASE_CUBIC_INOUT)
		.setChainFromCurrentValue(false);
	
	tweenRadius.start();
	
}

//--------------------------------------------------------------
void ofApp::update(){
	tweenRadius.update();
	
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
	ofDrawCircle(pos.x, pos.y, 80);
	ofDrawCircle(pos.x, pos.y, 4);
	
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	tweenRadius.start();
}
