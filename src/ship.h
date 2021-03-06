#pragma once
#include "ofMain.h"
#include "ParticleEmitter.h"
#include "Particle.h"
#include "ofxAssimpModelLoader.h"

class Ship {
public:
	// constructor
	Ship(ofxAssimpModelLoader m) {
		model = m;
	}

	// Fuel
	float timeLeft = 120000; // 120000 
    bool thrustersOn = false;

	//Physics variables
	ofVec3f velocity = ofVec3f(0, 0, 0);
	ofVec3f acceleration;
	ofVec3f forces = ofVec3f(0, 0, 0);
	ofVec3f axis = ofVec3f(0, 0, 0);
	float dt = 1.0 / 60.0;
	float angularVelocity = 0;
	float mass = 1.0;
	float damping = 0.99;
	bool rotate;
	float rotation = 0.0;
	

	// Particle emitter for "fuel exhaust"
	ParticleEmitter exhaust;
    ofImage bubble;

	ofxAssimpModelLoader model;

	glm::vec3 heading() {
		glm::vec3 initialHeading = glm::vec3(0, -1, 0);
		glm::mat4 Mrot = glm::rotate(glm::mat4(1.0), glm::radians(rotation), glm::vec3(0, 0, 1));
		glm::vec3 h = Mrot * glm::vec4(initialHeading, 1);
		//head = glm::normalize(h);
		return glm::normalize(h);
	}

	// from TransformObject I think we can delete this
	void setPosition(const ofVec3f &);
	ofVec3f position, scale;
	//float	rotation;
	bool	bSelected;


	// function prototypes
	void update();
	void setup();
	void draw();
	void integrate();
};



// move these into a separate file later lol
class Force {
protected:
public:
    bool applyOnce = false;
    bool applied = false;
    virtual void updateForce(Ship* s, float t) = 0;
};

class GravityForce : public Force {
public:
    ofVec3f g;
public:
    GravityForce(const ofVec3f &g);
    void updateForce(Ship* s, float t);
};

class ThrustForce : public Force {
    float magnitude;
public:
    ThrustForce(float magnitude);
    void updateForce(Ship* s, float t);
};

class TurbulenceForce : public Force {
    ofVec3f tmin, tmax;
public:
    TurbulenceForce(const ofVec3f & min, const ofVec3f &max);
    void updateForce(Ship* s, float t);
};

class ImpulseForce : public Force {
public:
    ImpulseForce() {
        applyOnce = true;
        applied = true;
        force = ofVec3f(0, 0, 0);
    }
    void apply(const ofVec3f f) {
        applied = false;
        force = f;
    }
    void updateForce(Ship *particle, float t) {
        particle->forces += force;
    }

    ofVec3f force;
};
