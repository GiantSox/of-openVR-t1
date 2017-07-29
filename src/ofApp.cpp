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
	ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 2, 50);
	ofPoint screenPos;
	screenPos.x = ofGetHeight() - (((tracker.trackerPos.z + 10) * 100) - 500);
	screenPos.y = ofGetHeight() - (((tracker.trackerPos.y + 10) * 100) - 500);
	//cout << screenPos << endl;
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
