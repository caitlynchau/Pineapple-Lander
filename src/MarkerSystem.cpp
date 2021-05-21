#include "MarkerSystem.h"

void TMarker::draw() {
	ofSetColor(color);
	ofNoFill();
	ofDrawRectangle(position, 1, 1);
}

void MarkerSystem::init() {
	int i = 0;
	markers.push_back(new TMarker(ofVec3f(65, 28, 40), i++));
	markers.push_back(new TMarker(ofVec3f(63, 28, 40), i++));
	markers.push_back(new TMarker(ofVec3f(63, 25, 39), i++));
	markers.push_back(new TMarker(ofVec3f(57, 25, 35), i++));
	markers.push_back(new TMarker(ofVec3f(55, 24, 30), i++));
	markers.push_back(new TMarker(ofVec3f(54, 22, 27), i++));
	markers.push_back(new TMarker(ofVec3f(50, 22, 27), i++));
	markers.push_back(new TMarker(ofVec3f(50, 22, 23), i++));
	markers.push_back(new TMarker(ofVec3f(45, 17, 20), i++));
	markers.push_back(new TMarker(ofVec3f(43, 13, 20), i++));
	markers.push_back(new TMarker(ofVec3f(42, 12, 14), i++));
	markers.push_back(new TMarker(ofVec3f(37, 10, 13), i++));
	markers.push_back(new TMarker(ofVec3f(33, 10, 7), i++));
	markers.push_back(new TMarker(ofVec3f(27, 8, 6), i++));
	markers.push_back(new TMarker(ofVec3f(24, 5, 8), i++));
	markers.push_back(new TMarker(ofVec3f(24, 1, 5), i++));
	markers.push_back(new TMarker(ofVec3f(23, 0, 1), i++));
	markers.push_back(new TMarker(ofVec3f(20, -3, -1), i++));
	markers.push_back(new TMarker(ofVec3f(20, -3, -4), i++));
	markers.push_back(new TMarker(ofVec3f(17, -4, -6), i++));
	markers.push_back(new TMarker(ofVec3f(16, -5, -9), i++));
	markers.push_back(new TMarker(ofVec3f(14, -7, -10), i++));
	markers.push_back(new TMarker(ofVec3f(9, -9, -13), i++));
	markers.push_back(new TMarker(ofVec3f(7, -9, -12), i++));
	markers.push_back(new TMarker(ofVec3f(3, -9, -10), i++));
	markers.push_back(new TMarker(ofVec3f(-3, -11, -10), i++));
	markers.push_back(new TMarker(ofVec3f(10, -11, -12), i++));

	cout << "total markers = " << i << endl;

}

void MarkerSystem::draw() {
	for (int i = 0; i < markers.size(); i++) {
		markers[i]->draw();
	}
}

