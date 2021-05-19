#include "Marker.h"

Marker::Marker() {
	color = ofColor::hotPink;
}

void Marker::setPosition(glm::vec3 p) {
	position = p;
}

void Marker::draw() {
	ofDrawSphere(position, 2);
}