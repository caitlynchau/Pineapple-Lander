#pragma once

#include "ofMain.h"
#include "TMarker.h"

class MarkerSystem {
public:
	MarkerSystem() {}
	void init();
	void draw();
	vector<TMarker*> markers;
};
