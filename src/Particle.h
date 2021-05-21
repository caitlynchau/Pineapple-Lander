#pragma once

#include "ofMain.h"

class Particle {
public:
	Particle();

	ofVec3f position;
	ofVec3f velocity;
	ofVec3f acceleration;
	ofVec3f forces;
	float	damping;
	float   mass;
	float   lifespan;
	float   radius;
	float   birthtime;
	void    integrate();
	void    draw();
	float   age();        // sec
    void setImage(ofImage img);
    bool haveImage = false;
    ofImage image;
	ofColor color;
    float width, height;
};
