#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	tracker.setup(vr::EVRApplicationType::VRApplication_Background);
	//ofSetBackgroundColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){
	tracker.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofDrawCircle(ofGetWidth() / 2, (ofGetHeight() / 2) -100, 50);
	ofPoint screenPos;
	screenPos.x = ofMap(tracker.trackerPos.z, 3, -3, 0, ofGetWidth());
	screenPos.y = ofMap(tracker.trackerPos.y, 3, -3, 0, ofGetHeight());
	ofDrawCircle(screenPos.x,screenPos.y, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
