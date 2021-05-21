#include "MarkerSystem.h"

void TMarker::draw() {
	ofSetColor(color);
	ofNoFill();
	ofDrawRectangle(position, boxSize, boxSize);
}

void MarkerSystem::init() {
	TMarker * landingPoint = new TMarker(ofVec3f(64, 0, 13));
	landingPoint->boxSize = 4;
	landingPoint->color = ofColor::green;
	markers.push_back(landingPoint);

	markers.push_back(new TMarker(ofVec3f(60,	5,	10)));
	markers.push_back(new TMarker(ofVec3f(61,	7,	5)));
	markers.push_back(new TMarker(ofVec3f(57,	7, -2)));
	markers.push_back(new TMarker(ofVec3f(50,	10, -5)));
	markers.push_back(new TMarker(ofVec3f(45,	13, -10)));
	markers.push_back(new TMarker(ofVec3f(38, 	14, -16)));
	markers.push_back(new TMarker(ofVec3f(33, 	15, -23)));
	markers.push_back(new TMarker(ofVec3f(28, 	18, -25)));
	markers.push_back(new TMarker(ofVec3f(20,	18, -25)));
	markers.push_back(new TMarker(ofVec3f(8,	23, -19)));
	markers.push_back(new TMarker(ofVec3f(14,	21, -23)));
	markers.push_back(new TMarker(ofVec3f(4,	25, -13)));
	markers.push_back(new TMarker(ofVec3f(5,	23, -7)));
	markers.push_back(new TMarker(ofVec3f(3,	19, -3)));
	markers.push_back(new TMarker(ofVec3f(3,	14,	4)));
	markers.push_back(new TMarker(ofVec3f(1,	11,	10)));
	markers.push_back(new TMarker(ofVec3f(-1,	13,	19)));
	markers.push_back(new TMarker(ofVec3f(-2,	11,	26)));
	markers.push_back(new TMarker(ofVec3f(-4,	15,	34)));
	markers.push_back(new TMarker(ofVec3f(-10,	17,	44)));
	markers.push_back(new TMarker(ofVec3f(-18,	21,	46)));
	markers.push_back(new TMarker(ofVec3f(-26,	23,	40)));
	markers.push_back(new TMarker(ofVec3f(-33,	27,	35)));
	markers.push_back(new TMarker(ofVec3f(-42,	23,	25)));
	markers.push_back(new TMarker(ofVec3f(-95,	0, -34)));
	markers.push_back(new TMarker(ofVec3f(-80,	1, -30)));
	markers.push_back(new TMarker(ofVec3f(-73,	5, -30)));
	markers.push_back(new TMarker(ofVec3f(-60,	6, -30)));
	markers.push_back(new TMarker(ofVec3f(-54,	10, -30)));
	markers.push_back(new TMarker(ofVec3f(-53,	13, -23)));
	markers.push_back(new TMarker(ofVec3f(-53,	13, -18)));
	markers.push_back(new TMarker(ofVec3f(-53,	13, -11)));
	markers.push_back(new TMarker(ofVec3f(-55,	16, -3)));
	markers.push_back(new TMarker(ofVec3f(-52,	18,	4)));
	markers.push_back(new TMarker(ofVec3f(-48,	20,	19)));
	markers.push_back(new TMarker(ofVec3f(-38,	25,	33)));
}

void MarkerSystem::draw() {
	for (int i = 0; i < markers.size(); i++) {
		if (i == 0) {
			ofSetColor(markers[i]->color);
			ofDrawSphere(markers[i]->position, 3);
		}
		markers[i]->draw();
	}
}

