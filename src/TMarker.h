#pragma once

#include "ofMain.h"

class TMarker {
public:
	TMarker(); // constructor

	ofVec3f position;
	ofColor color;
	void draw();
	void setPosition(glm::vec3 p);
};
