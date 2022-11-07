#include "ofApp.h"
#include "vector"
#include "cmath"
float walkers[20] = {350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 200, 900, 700, 650, 800, 800, 770, 200};
float resist[20] = {350, 120, 200, 300, 700, 900, 500, 400, 210, 110, 800, 600, 900, 900, 700, 650, 800, 800, 770, 740};
ofVec2f cl(512, 512);
float V = 10;
vector <float> cluster = {500, 500};
int clus(int x1, int y1, int x2, int y2) {
	int range;
	range = pow(pow(x2 - x1, 2) + (y2 - y1, 2), 1 / 2);
	return range;
}
void ofApp::setup(){
	
}
void ofApp::update(){
	ofVec2f Ve, walker;
	for (int i = 0; i < 20; i+=2) {
		if (walkers[i] >= 0) {
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
			for (int i = 0; i < cluster.size(); i += 2) {
				if (clus(walker[0], walker[1], cluster[i], cluster[i + 1] < 20)) {
					cluster.push_back(walker[0]);
					cluster.push_back(walker[1]);
					walker[0] = -900;
					walker[1] = -900;
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < 20; i += 2) {
		if (walkers[i] >= 0) {
			ofSetColor(250, 250, 250);
			ofCircle(walkers[i], walkers[i + 1], 10);
		}
	}
	for (int i = 0; i < cluster.size(); i += 2) {
		ofSetColor(250, 250, 250);
		ofCircle(cluster[i], cluster[i + 1], 10);
	}
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
