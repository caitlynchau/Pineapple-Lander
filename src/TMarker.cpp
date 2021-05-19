#include "TMarker.h"

TMarker::TMarker() {
	color = ofColor::hotPink;
}

void TMarker::setPosition(glm::vec3 p) {
	position = p;
}

void TMarker::draw() {
	ofDrawSphere(position, 2);
}
