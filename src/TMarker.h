#pragma once

#include "ofMain.h"

class TMarker {
public:
	ofVec3f position;
	ofColor color;
	bool hit = false;
	void draw();
	void setPosition(glm::vec3 p); // can prob delete this lol

	TMarker(ofVec3f p) { // constructor
		position = p;
		color = ofColor::hotPink;
	}
};
