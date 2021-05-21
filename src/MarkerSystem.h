#pragma once

#include "ofMain.h"

class TMarker {
public:
	ofVec3f position;
	ofColor color;
	int index;
	bool hit = false;
	void draw();

	TMarker(ofVec3f p, int index) { // constructor
		this->position = p;
		this->color = ofColor::blue;
		this->index = index;
	}
};


class MarkerSystem {
public:
	MarkerSystem() {}
	void init();
	void draw();
	vector<TMarker*> markers;
};
