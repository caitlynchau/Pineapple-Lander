#include "MarkerSystem.h"

void MarkerSystem::add(const TMarker &m) {
	markers.push_back(m);
}

void MarkerSystem::draw() {
	ofDrawSphere(ofVec3f(65, 28, 40), 0.3);
	ofDrawSphere(ofVec3f(63, 28, 40), 0.3);
	ofDrawSphere(ofVec3f(63, 25, 39), 0.3);
	ofDrawSphere(ofVec3f(57, 25, 35), 0.3);
	ofDrawSphere(ofVec3f(55, 24, 30), 0.3);
	ofDrawSphere(ofVec3f(54, 22, 27), 0.3);
	ofDrawSphere(ofVec3f(50, 22, 27), 0.3);
	ofDrawSphere(ofVec3f(50, 22, 23), 0.3);
	ofDrawSphere(ofVec3f(45, 17, 20), 0.3);
	ofDrawSphere(ofVec3f(43, 13, 20), 0.3);
	ofDrawSphere(ofVec3f(42, 12, 14), 0.3);
	ofDrawSphere(ofVec3f(37, 10, 13), 0.3);
	ofDrawSphere(ofVec3f(33, 10, 7), 0.3);
	ofDrawSphere(ofVec3f(27, 8, 6), 0.3);
	ofDrawSphere(ofVec3f(24, 5, 8), 0.3);
	ofDrawSphere(ofVec3f(24, 1, 5), 0.3);
	ofDrawSphere(ofVec3f(23, 0, 1), 0.3);
	ofDrawSphere(ofVec3f(20, -3, -1), 0.3);
	ofDrawSphere(ofVec3f(20, -3, -4), 0.3);
	ofDrawSphere(ofVec3f(17, -4, -6), 0.3);
	ofDrawSphere(ofVec3f(16, -5, -9), 0.3);
	ofDrawSphere(ofVec3f(14, -7, -10), 0.3);
	ofDrawSphere(ofVec3f(9, -9, -13), 0.3);
	ofDrawSphere(ofVec3f(7, -9, -12), 0.3);
	ofDrawSphere(ofVec3f(3, -9, -10), 0.3);
	ofDrawSphere(ofVec3f(-3, -11, -10), 0.3);
	ofDrawSphere(ofVec3f(10, -11, -12), 0.3);
}

