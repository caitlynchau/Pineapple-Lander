#pragma once

#include "ofMain.h"
#include "TMarker.h"

class MarkerSystem {
public:
	MarkerSystem() {
		
	}
	void add(const TMarker &);
	void draw();
	vector<TMarker> markers;
};
