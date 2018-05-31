#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(39);
	ofSetWindowTitle("Insta");

	ofSetColor(239);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int len = 89;

	for (int x = len * 0.5; x <= ofGetWidth() - len * 0.5; x += len + 1) {

		for (int y = len * 0.5; y <= ofGetHeight() - len * 0.5; y += len + 1) {

			ofPushMatrix();
			ofTranslate(x, y);

			int deg_start = ofMap(ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.005), 0, 1, 0, 720);
			int deg_end = deg_start + ofMap(ofNoise(x * 0.01, y * 0.01, ofGetFrameNum() * 0.005), 0, 1, 45, 225);

			ofBeginShape();
			for (int deg = deg_start; deg < deg_end; deg += 1) {

				ofVertex(this->make_rect_point(len, deg));
			}
			ofEndShape(true);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
ofPoint ofApp::make_rect_point(float len, int deg) {

	int half_len = len * 0.5;
	int param = (deg + 45) / 90;
	
	ofPoint point;

	switch (param % 4) {

	case 0:

		return ofPoint(half_len, ofMap((deg + 45) % 90, 0, 89, -half_len, half_len));
	case 1:

		return  ofPoint(ofMap((deg + 45) % 90, 0, 89, half_len, -half_len), half_len);
	case 2:

		return ofPoint(-half_len, ofMap((deg + 45) % 90, 0, 89, half_len, -half_len));
	case 3:

		return ofPoint(ofMap((deg + 45) % 90, 0, 89, -half_len, half_len), -half_len);
	default:

		return ofPoint(0, 0);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}