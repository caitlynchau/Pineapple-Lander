#pragma once
//  Kevin M. Smith - CS 134 SJSU

#include "ofMain.h"
#include "Particle.h"


//  Pure Virtual Function Class - must be subclassed to create new forces.
//
class ParticleForce {
public:
    bool applyOnce = false;
    bool applied = false;
	virtual void updateForce(Particle *) = 0;
};

class ParticleSystem {
public:
	void add(const Particle &);
	void addForce(ParticleForce *);
	void remove(int);
	void update();
    void reset();
	int removeNear(const ofVec3f & point, float dist);
	void draw();
	vector<Particle> particles;
	vector<ParticleForce *> forces;
};



// Some convenient built-in forces
//
class GravityParticleForce : public ParticleForce {
	ofVec3f gravity;
public:
	GravityParticleForce(const ofVec3f & gravity);
	void updateForce(Particle *);
	void set(float g) {
		gravity = ofVec3f(0, -g, 0);
	}
};

class TurbulenceParticleForce : public ParticleForce {
	ofVec3f tmin, tmax;
public:
	TurbulenceParticleForce(const ofVec3f & min, const ofVec3f &max);
	void updateForce(Particle *);
	void set(ofVec3f min, ofVec3f max) {
		tmin = min;
		tmax = max;
	}
};
