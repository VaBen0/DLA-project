#include "ofApp.h"
#include "vector"
#include "cmath"
vector <ofVec2f> walkers;
vector <ofVec2f> cluster;
float V = 10;
int num, R=5;

void ofApp::setup() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		ofVec2f add(ofRandom(10, ofGetScreenWidth()), ofRandom(10, ofGetScreenWidth()));
		walkers.push_back(add);
	}
	for (int i = 0; i < 1; i++) {
		ofVec2f add(ofRandom(200, 600), ofRandom(200, 600));
		cluster.push_back(add);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	ofVec2f Ve, walker;
	for (int i = 0; i < walkers.size(); i++) {
		ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i]);
		dir.normalize();
		Ve = dir * V;
		walker += Ve;
		if (walker[0] < -5) walker[0] = 1024;
		if (walker[0] > 1029) walker[0] = 0;
		if (walker[1] < -5) walker[1] = 900;
		if (walker[1] > 905) walker[1] = 0;
		walkers[i] = walker;
		int sz = cluster.size();
		for (int j = 0; j < sz; j++) {
			if (walkers[i].distance(cluster[j]) < 2 * R) {
				cluster.push_back(walkers[i]);
				walkers.erase(walkers.begin() + i);
				break;
			}
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < walkers.size(); i++) {
		ofSetColor(255, 255, 255);
		ofVec2f coords(walkers[i]);
		ofCircle(coords[0], coords[1], R);
	}
	for (int i = 0; i < cluster.size(); i++) {
		ofSetColor(0, 0, 255);
		ofVec2f coords(cluster[i]);
		ofCircle(coords[0], coords[1], R);
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
