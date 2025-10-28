#include "ofApp.h"
#include "ofxTweenLite.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // Set up tween demo
    startX =100;            // Start position (left)
    endX = ofGetWidth() -100;  // End position (right)
    currentX = startX;
    duration =2.0f;         // Animation duration in seconds
    startTime = ofGetElapsedTimef();
    progress =0.0f;
    easeMode = OF_EASE_CUBIC_OUT; // Start with cubic out
}

//--------------------------------------------------------------
void ofApp::update(){
    // Calculate progress (0 to1)
    float elapsed = ofGetElapsedTimef() - startTime;
    progress = ofClamp(elapsed / duration,0.0f,1.0f);

    // Tween the X position using the selected ease mode
    currentX = ofxTweenLite::tween(startX, endX, progress, static_cast<ofEaseFunction>(easeMode));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(30);
    ofSetColor(255,100,100);
    ofDrawCircle(currentX, ofGetHeight()/2,40);

    // Draw progress bar
    ofSetColor(200);
    ofDrawRectangle(100, ofGetHeight()/2 +60, (endX-startX)*progress,10);

    // Draw info
    ofSetColor(255);
    ofDrawBitmapString("Tween progress: " + ofToString(progress,2),100, ofGetHeight()/2 +90);
    ofDrawBitmapString("Press any key to restart animation",100, ofGetHeight()/2 +110);
    ofDrawBitmapString("Up/Down: Change Ease Mode",100, ofGetHeight()/2 +130);
    ofDrawBitmapString("Ease Mode: " + getEaseModeName(easeMode),100, ofGetHeight()/2 +150);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_UP){
        easeMode++;
        if(easeMode > OF_EASE_SINE_INOUT) easeMode =0;
        startTime = ofGetElapsedTimef(); // restart animation
    }else if(key == OF_KEY_DOWN){
        easeMode--;
        if(easeMode <0) easeMode = OF_EASE_SINE_INOUT;
        startTime = ofGetElapsedTimef(); // restart animation
    }else{
        // Restart animation
        startTime = ofGetElapsedTimef();
    }
}

//--------------------------------------------------------------
std::string ofApp::getEaseModeName(int mode){
    switch(mode){
        case OF_EASE_BACK_IN: return "Back In";
        case OF_EASE_BACK_OUT: return "Back Out";
        case OF_EASE_BACK_INOUT: return "Back InOut";
        case OF_EASE_BOUNCE_IN: return "Bounce In";
        case OF_EASE_BOUNCE_OUT: return "Bounce Out";
        case OF_EASE_BOUNCE_INOUT: return "Bounce InOut";
        case OF_EASE_CIRC_IN: return "Circ In";
        case OF_EASE_CIRC_OUT: return "Circ Out";
        case OF_EASE_CIRC_INOUT: return "Circ InOut";
        case OF_EASE_CUBIC_IN: return "Cubic In";
        case OF_EASE_CUBIC_OUT: return "Cubic Out";
        case OF_EASE_CUBIC_INOUT: return "Cubic InOut";
        case OF_EASE_ELASTIC_IN: return "Elastic In";
        case OF_EASE_ELASTIC_OUT: return "Elastic Out";
        case OF_EASE_ELASTIC_INOUT: return "Elastic InOut";
        case OF_EASE_EXPO_IN: return "Expo In";
        case OF_EASE_EXPO_OUT: return "Expo Out";
        case OF_EASE_EXPO_INOUT: return "Expo InOut";
        case OF_EASE_LINEAR_IN: return "Linear In";
        case OF_EASE_LINEAR_OUT: return "Linear Out";
        case OF_EASE_LINEAR_INOUT: return "Linear InOut";
        case OF_EASE_QUAD_IN: return "Quad In";
        case OF_EASE_QUAD_OUT: return "Quad Out";
        case OF_EASE_QUAD_INOUT: return "Quad InOut";
        case OF_EASE_QUART_IN: return "Quart In";
        case OF_EASE_QUART_OUT: return "Quart Out";
        case OF_EASE_QUART_INOUT: return "Quart InOut";
        case OF_EASE_QUINT_IN: return "Quint In";
        case OF_EASE_QUINT_OUT: return "Quint Out";
        case OF_EASE_QUINT_INOUT: return "Quint InOut";
        case OF_EASE_SINE_IN: return "Sine In";
        case OF_EASE_SINE_OUT: return "Sine Out";
        case OF_EASE_SINE_INOUT: return "Sine InOut";
        default: return "Unknown";
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
