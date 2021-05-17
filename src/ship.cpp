
#include "ship.h"

// Forces classes - move into separate file later on
GravityForce::GravityForce(const ofVec3f &g) {
	this->g = g;
}

void GravityForce::updateForce(ofVec3f &forces, float t) {
	forces += g;
}
ThrustForce::ThrustForce(float magnitude) {
	this->magnitude = magnitude;
}

void ThrustForce::updateForce(ofVec3f &forces, float t) {
	forces.y += t;
}
TurbulenceForce::TurbulenceForce(const ofVec3f &min, const ofVec3f &max) {
	tmin = min;
	tmax = max;
}

void TurbulenceForce::updateForce(ofVec3f &forces, float t) {
	//
	// We are going to add a little "noise" to a particles
	// forces to achieve a more natual look to the motion
	//
	// force
	forces.x += ofRandom(tmin.x, tmax.x);
	forces.y += ofRandom(tmin.y, tmax.y);
	forces.z += ofRandom(tmin.z, tmax.z);
}






void Ship::integrate() {
	//pos += (velocity*dt);
	glm::vec3 current = model.getPosition();
	current += (velocity*dt);
	model.setPosition(current.x, current.y, current.z);
	// 1D angular motion using omega (angular velocity)
	//
	//rotation += (angularVelocity*dt);

	// update acceleration with accumulated paritcles forces
	// (a = 1/m * f)
	//
	ofVec3f accel = acceleration;    // start with any acceleration already on the particle
	accel += (forces * (1.0 / mass));
	//cout << "accel: " << accel << endl;
	velocity += accel * dt;

	//add damping
	velocity *= 0.9;
	cout << velocity << endl;
	angularVelocity *= 0.99;

	forces = ofVec3f(0, 0, 0);
}

void Ship::setup() {
	//Initialize forces
	g = new GravityForce(ofVec3f(0, -3.72, 0));
	tf = new ThrustForce(10.0);
	turb = new TurbulenceForce(ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10));
}


void Ship::update() {
	//g->updateForce(forces, 1.62);
	//tf->updateForce(forces, 5);
}