#include "ofApp.h"
#include "vector"
#include "cmath"
vector <float> walkers;
vector <float> cluster = { 500, 500 };
float V = 10;
int num;
int check(float x1, float y1, float x2, float y2) {
	return pow(pow(x1 - x2, 2) + pow(y1 - y2, 2), 1. / 2);
}
void ofApp::setup() {
	cin >> num;
	for (int i = 0; i < num; i++) {
		walkers.push_back(ofRandom(10, 1000));
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	ofVec2f Ve, walker;
	int l = -20;
	int schet1 = 0;
	for (int i = 0; i < walkers.size(); i += 2) {
		int schet1 = 0;
		ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i], walkers[i + 1]);
		dir.normalize();
		Ve = dir * V;
		walker += Ve;
		if (walker[0] < -5) walker[0] = 1024;
		if (walker[0] > 1024) walker[0] = 0;
		if (walker[1] < -5) walker[1] = 768;
		if (walker[1] > 768) walker[1] = 0;
		walkers[i] = walker[0];
		walkers[i + 1] = walker[1];
		int h = 0;
		int sz = cluster.size();
		for (int j = 0; j < sz; j += 2) {
			if (check(walkers[i], walkers[i + 1], cluster[j], cluster[j + 1]) < 20 && i+2< walkers.size()) {
				cluster.push_back(walkers[i]);
				cluster.push_back(walkers[i + 1]);
				h += 1;
				break;
			}
		}
		if (h != 0 && i + 2 < walkers.size()) {
			walkers.erase(walkers.begin() + i);
			walkers.erase(walkers.begin() + i + 1);
		}
		
	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < walkers.size(); i += 2) {
		if(i+2< walkers.size()){
			ofSetColor(255, 255, 255);
			ofCircle(walkers[i], walkers[i + 1], 10);
		}
	}
	for (int i = 0; i < cluster.size(); i += 2) {
		ofSetColor(0, 0, 255);
		ofCircle(cluster[i], cluster[i + 1], 10);
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
