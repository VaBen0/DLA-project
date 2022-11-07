#include "ofApp.h"
#include "vector"
#include "cmath"
float walkers[20] = { 350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 900, 900, 700, 650, 800, 800, 770, 740 };
float resist[20] = { 350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 900, 900, 700, 650, 800, 800, 770, 740 };
ofVec2f cl(512, 512);
vector <ofVec2f> cluster;
float V = 10;
void ofApp::setup() {

}

//--------------------------------------------------------------
void ofApp::update() {
	cluster.push_back(cl);
	ofVec2f Ve, walker;
	for (int i = 0; i < 20; i += 2) {
		ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i], walkers[i + 1]);
		dir.normalize();
		Ve = dir * V;
		walker += Ve;
		if (walker[0] < 100 or walker[1] < 0 or walker[0]>1024 or walker[1]>1024) {
			walker[0] = resist[i];
			walker[1] = resist[i + 1];
		}
		walkers[i] = walker[0];
		walkers[i + 1] = walker[1];
	}

}

//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < 20; i += 2) {
		ofCircle(walkers[i], walkers[i + 1], 10);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}