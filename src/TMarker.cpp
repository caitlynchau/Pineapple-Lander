#include "TMarker.h"

void TMarker::setPosition(glm::vec3 p) {
	position = p;
}

void TMarker::draw() {
	ofSetColor(color);
	ofDrawSphere(position, 0.3);
}
