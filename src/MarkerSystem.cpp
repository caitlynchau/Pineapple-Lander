#include "MarkerSystem.h"

void MarkerSystem::init() {
	markers.push_back(new TMarker(ofVec3f(65, 28, 40)));
	markers.push_back(new TMarker(ofVec3f(63, 28, 40)));
	markers.push_back(new TMarker(ofVec3f(63, 25, 39)));
	markers.push_back(new TMarker(ofVec3f(57, 25, 35)));
	markers.push_back(new TMarker(ofVec3f(55, 24, 30)));
	markers.push_back(new TMarker(ofVec3f(54, 22, 27)));
	markers.push_back(new TMarker(ofVec3f(50, 22, 27)));
	markers.push_back(new TMarker(ofVec3f(50, 22, 23)));
	markers.push_back(new TMarker(ofVec3f(45, 17, 20)));
	markers.push_back(new TMarker(ofVec3f(43, 13, 20)));
	markers.push_back(new TMarker(ofVec3f(42, 12, 14)));
	markers.push_back(new TMarker(ofVec3f(37, 10, 13)));
	markers.push_back(new TMarker(ofVec3f(33, 10, 7)));
	markers.push_back(new TMarker(ofVec3f(27, 8, 6)));
	markers.push_back(new TMarker(ofVec3f(24, 5, 8)));
	markers.push_back(new TMarker(ofVec3f(24, 1, 5)));
	markers.push_back(new TMarker(ofVec3f(23, 0, 1)));
	markers.push_back(new TMarker(ofVec3f(20, -3, -1)));
	markers.push_back(new TMarker(ofVec3f(20, -3, -4)));
	markers.push_back(new TMarker(ofVec3f(17, -4, -6)));
	markers.push_back(new TMarker(ofVec3f(16, -5, -9)));
	markers.push_back(new TMarker(ofVec3f(14, -7, -10)));
	markers.push_back(new TMarker(ofVec3f(9, -9, -13)));
	markers.push_back(new TMarker(ofVec3f(7, -9, -12)));
	markers.push_back(new TMarker(ofVec3f(3, -9, -10)));
	markers.push_back(new TMarker(ofVec3f(-3, -11, -10)));
	markers.push_back(new TMarker(ofVec3f(10, -11, -12)));
}

void MarkerSystem::draw() {
	for (int i = 0; i < markers.size(); i++) {
		markers[i]->draw();
	}
}

