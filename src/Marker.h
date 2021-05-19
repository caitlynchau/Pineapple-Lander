#pragma once

#include "ofMain.h"

class Marker {
public:
	Marker(); // constructor

	ofVec3f position;
	ofColor color;
	void draw();
	void setPosition(glm::vec3 p);
};