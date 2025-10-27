#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	// Circle initial and final values
	float radiusStart = 40.0f;
	float radiusEnd = 120.0f;
	glm::vec2 posStart(ofGetWidth() / 2, ofGetHeight() - radiusEnd - 20);
	glm::vec2 posEnd(ofGetWidth() / 2, radiusEnd + 20);
	ofColor colorStart = ofColor::red;
	ofColor colorEnd = ofColor::blue;

	// Setup tweens
	tweenRadius.setFrom(radiusStart).setTo(radiusEnd).setDuration(2.0f).setEase(getEaseModes()[easeIndex]);
	tweenPosition.setFrom(posStart).setTo(posEnd).setDuration(2.0f).setEase(getEaseModes()[easeIndex]);
	tweenColor.setFrom(colorStart).setTo(colorEnd).setDuration(2.0f).setEase(getEaseModes()[easeIndex]);

	// Start tweens
	tweenRadius.start(radiusStart, radiusEnd, 2.0f, getEaseModes()[easeIndex]);
	tweenPosition.start(posStart, posEnd, 2.0f, getEaseModes()[easeIndex]);
	tweenColor.start(colorStart, colorEnd, 2.0f, getEaseModes()[easeIndex]);
}

//--------------------------------------------------------------
void ofApp::update() {
	tweenRadius.update();
	tweenPosition.update();
	tweenColor.update();
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(30);
	ofSetColor(tweenColor.getValue());
	glm::vec2 pos = tweenPosition.getValue();
	float radius = tweenRadius.getValue();
	ofDrawCircle(pos, radius);

	// Debug info
	ofSetColor(255);
	int y = 30;
	int x = 30;
	int lineSpace = 28;
	int sectionSpace = 18;
	int barW = 120;
	int barH = 24;
	int textOffsetY = barH / 2 + 6;

	ofDrawBitmapString("Easing:", x, y);
	y += lineSpace;
	ofDrawBitmapString(" " + getEaseNames()[easeIndex], x, y);
	y += lineSpace + sectionSpace;
	ofDrawBitmapString("Tween Values:", x, y);
	y += lineSpace;
	ofDrawBitmapString(" Radius: " + ofToString(radius, 2), x, y);
	y += lineSpace;
	ofDrawBitmapString(" Position: (" + ofToString(pos.x, 2) + ", " + ofToString(pos.y, 2) + ")", x, y);
	y += lineSpace;
	ofColor c = tweenColor.getValue();
	ofDrawBitmapString(" Color: (" + ofToString((int)c.r) + ", " + ofToString((int)c.g) + ", " + ofToString((int)c.b) + ", " + ofToString((int)c.a) + ")", x, y);
	y += lineSpace + sectionSpace;
	ofDrawBitmapString("Tween Progress:", x, y);
	y += lineSpace;

	// Radius progress bar
	float pr = tweenRadius.getProgress();
	ofSetColor(255); // white border
	ofNoFill();
	ofDrawRectangle(x, y, barW, barH);
	ofFill();
	ofSetColor(0); // black fill
	ofDrawRectangle(x, y, barW * pr, barH);
	ofSetColor(255);
	ofDrawBitmapString(" Radius: " + ofToString(pr, 2), x + 4, y + textOffsetY);
	y += lineSpace + barH - 10;

	// Position progress bar
	float pp = tweenPosition.getProgress();
	ofSetColor(255);
	ofNoFill();
	ofDrawRectangle(x, y, barW, barH);
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(x, y, barW * pp, barH);
	ofSetColor(255);
	ofDrawBitmapString(" Position: " + ofToString(pp, 2), x + 4, y + textOffsetY);
	y += lineSpace + barH - 10;

	// Color progress bar
	float pc = tweenColor.getProgress();
	ofSetColor(255);
	ofNoFill();
	ofDrawRectangle(x, y, barW, barH);
	ofFill();
	ofSetColor(0);
	ofDrawRectangle(x, y, barW * pc, barH);
	ofSetColor(255);
	ofDrawBitmapString(" Color: " + ofToString(pc, 2), x + 4, y + textOffsetY);
	y += lineSpace + barH - 10 + sectionSpace;
	ofSetColor(255);
	ofDrawBitmapString("Keys:", x, y);
	y += lineSpace;
	ofDrawBitmapString(" [UP/DOWN] Change Easing (while tween runs)", x, y);
	y += lineSpace;
	ofDrawBitmapString(" [SPACE] Restart", x, y);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	// Restart tweens with spacebar
	if (key == ' ') {
		float radiusStart = 40.0f;
		float radiusEnd = 120.0f;
		glm::vec2 posStart(ofGetWidth() / 2, ofGetHeight() - radiusEnd - 20);
		glm::vec2 posEnd(ofGetWidth() / 2, radiusEnd + 20);

		// Chain if retrig from current state values
		float fromRadius = tweenRadius.isRunning() ? tweenRadius.getValue() : radiusStart;
		glm::vec2 fromPos = tweenPosition.isRunning() ? tweenPosition.getValue() : posStart;
		ofColor fromColor = tweenColor.isRunning() ? tweenColor.getValue() : ofColor::red;
		tweenRadius.start(fromRadius, radiusEnd, 2.0f, getEaseModes()[easeIndex]);
		tweenPosition.start(fromPos, posEnd, 2.0f, getEaseModes()[easeIndex]);
		tweenColor.start(fromColor, ofColor::blue, 2.0f, getEaseModes()[easeIndex]);
	}
	// Change easing mode with up/down arrows (do not restart tweens)
	if (key == OF_KEY_UP) {
		easeIndex = (easeIndex + 1) % getEaseModes().size();
		tweenRadius.setEase(getEaseModes()[easeIndex]);
		tweenPosition.setEase(getEaseModes()[easeIndex]);
		tweenColor.setEase(getEaseModes()[easeIndex]);
	}
	if (key == OF_KEY_DOWN) {
		easeIndex = (easeIndex - 1 + getEaseModes().size()) % getEaseModes().size();
		tweenRadius.setEase(getEaseModes()[easeIndex]);
		tweenPosition.setEase(getEaseModes()[easeIndex]);
		tweenColor.setEase(getEaseModes()[easeIndex]);
	}
}
