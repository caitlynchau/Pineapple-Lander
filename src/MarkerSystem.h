#pragma once

#include "ofMain.h"

class TMarker {
public:
	ofVec3f position;
	ofColor color;
	int boxSize;
	bool hit = false;
	void draw();

	TMarker(ofVec3f p) { // constructor
		this->position = p;
		this->color = ofColor::blue;
		this->boxSize = 2;
	}
};


class MarkerSystem {
public:
	MarkerSystem() {}
	void init();
	void draw();
	vector<TMarker*> markers;
};
