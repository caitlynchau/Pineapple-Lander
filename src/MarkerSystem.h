#pragma once

#include "ofMain.h"
#include "Marker.h"

class MarkerSystem {
public:
	MarkerSystem() {
		
	}
	void add(const Marker &);
	void draw();
	vector<Marker> markers;
};