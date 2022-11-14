#include "ofApp.h"
#include "vector"
#include "cmath"
float walkers[22] = { -999, 350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 900, 900, 700, 650, 800, 800, 770, 740 };
vector <float> cluster = { 500, 500 };
float V = 10;
float h;
int check(ofVec2f a) {
	for (int i = 0; i < cluster.size(); i+=2) {
		if (pow(pow(cluster[i]- a[0], 2) + pow(cluster[i + 1] - a[1], 2), 1 / 2) < 20) {
			cluster.push_back(a[0]);
			cluster.push_back(a[1]);
			a[0] = -999;
			a[1] = -999;
		}
	return a[0], a[1];
	}
	
}
void ofApp::setup() {

}

//--------------------------------------------------------------
void ofApp::update() {
	int k = 0;
	ofVec2f Ve, walker;
	for (int i = 0; i < 22; i += 2) {
		if (walkers[i] >= 0) {
			ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i], walkers[i + 1]);
			dir.normalize();
			Ve = dir * V;
			walker += Ve;
			walkers[i] = walker[0];
			walkers[i + 1] = walker[1];
			walker[0], walker[1] = check(walker);
			walkers[i] = walker[0];
			walkers[i + 1] = walker[1];
		}
	}
}


//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 22; i += 2) {
		if(walkers[i] >= 0 and i<20) {
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