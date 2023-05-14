#include "ofApp.h"
#include "vector"
#include "cmath"

vector <ofVec2f> walkers;
vector <ofVec2f> cluster;

float V = 15;
float speed_of_wind_x = 6, speed_of_wind_y = 6;
float num, R = 1, w, h, schet = 0, R_circl = 150, Red = 149, Green = -37, Blue = 83;

string direction;
ofVec2f wind;

void ofApp::setup() {
	cout << "Enter the number of particlessss: ";
	cin >> num;

	cout << "Choose the wind direction (N, S, W, E, NW, NE, SW, SE or none): ";
	cin >> direction;

	if (direction == "N") {
		speed_of_wind_x = 0;
	}
	else if (direction == "S") {
		speed_of_wind_x = 0;
		speed_of_wind_y *= -1;
	}
	else if (direction == "E") {
		speed_of_wind_y = 0;
	}
	else if (direction == "W") {
		speed_of_wind_y = 0;
		speed_of_wind_x *= -1;
	}
	else if (direction == "NE") {
		speed_of_wind_x *= -1;
	}
	else if (direction == "SE") {
		speed_of_wind_y *= -1;
		speed_of_wind_x *= -1;
	}
	else if (direction == "SW") {
		speed_of_wind_y *= -1;
	}
	else if (direction == "none") {
		speed_of_wind_y *= 0;
		speed_of_wind_x *= 0;
	}

	ofVec2f speed(speed_of_wind_x, speed_of_wind_y);

	wind += speed;
	w = ofGetWidth();
	h = ofGetHeight();

	for (int i = 0; i < num; i++) {
		ofVec2f add(ofRandom(10, ofGetScreenWidth()), ofRandom(10, ofGetScreenWidth()));
		walkers.push_back(add);
	}

	ofVec2f addi(h / 2, w / 2);
	cluster.push_back(addi);

}

void ofApp::update() {
	ofVec2f Ve, walker;

	for (int i = 0; i < walkers.size(); i++) {
		ofVec2f dir(ofRandomf(), ofRandomf()), walker(walkers[i]);
		dir.normalize();
		Ve = (dir * V) + wind;
		walkers[i] += Ve;

		if (walkers[i][0] < -5) walkers[i][0] = w;
		if (walkers[i][0] > w) walkers[i][0] = 0;
		if (walkers[i][1] < -5) walkers[i][1] = h;
		if (walkers[i][1] > h) walkers[i][1] = 0;

		int sz = cluster.size();

		for (int j = 0; j < sz; j++) {
			if(j == 0){
				if (walkers[i].distance(cluster[0]) < R_circl + R && walkers[i].distance(cluster[0]) > R_circl - R) {
					cluster.push_back(walkers[i]);
					walkers.erase(walkers.begin() + i);
					break;
				}
			}
			else if (walkers[i].distance(cluster[j]) < 2 * R) {
				cluster.push_back(walkers[i]);
				walkers.erase(walkers.begin() + i);
				break;
			}
		}
	}
	cout << walkers.size() << " ";
}


//--------------------------------------------------------------
void ofApp::draw() {
	for (int i = 0; i < cluster.size(); i++) {
		if (i == 0) {
			ofSetColor(255, 255, 255);
			ofNoFill();
			ofDrawCircle(h / 2, w / 2, R_circl);
		}
		ofFill();
		int dist = cluster[i].distance(cluster[0]);
		ofSetColor(Red + dist, Green + dist, Blue + dist);
		ofDrawCircle(cluster[i][0], cluster[i][1], R);
	}
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}