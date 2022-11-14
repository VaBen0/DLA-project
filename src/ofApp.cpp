#include "ofApp.h"
#include "vector"
#include "cmath"
float walkers[22] = { -999, 350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 900, 900, 700, 650, 800, 800, 770, 740 };
vector <float> cluster = { 500, 500 };
float V = 10;
float h;
int check(int a, int b, int c, float d) {
	return pow(pow(a - c, 2) + pow(b - d, 2), 1 / 2);
}
void ofApp::setup() {

}

//--------------------------------------------------------------
void ofApp::update() {
	int k = 0;
	ofVec2f Ve, walker;
	for (int i = 0; i < 22; i += 2) {
		ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i], walkers[i + 1]);
		dir.normalize();
		Ve = dir * V;
		walker += Ve;
		for (int i = 0; i < cluster.size(); i += 2) {
			if (check(walker[0], cluster[i], walker[1], cluster[i + 1]) < 20) {
				cluster.push_back(walker[0]);
				cluster.push_back(walker[1]);
				walker[0] = -999;
				walker[1] = -999;
			}
		}
		walkers[i] = walker[0];
		walkers[i + 1] = walker[1];

	}
}


//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < 22; i += 2) {
		if (walkers[i] >= 0 and i < 20) {
			ofCircle(walkers[i], walkers[i + 1], 10);
		}
		if (i < cluster.size()) {
			ofCircle(cluster[i], cluster[i + 1], 10);
		}
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