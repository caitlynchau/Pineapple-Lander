
#include "ship.h"

// Forces classes - move into separate file later on
GravityForce::GravityForce(const ofVec3f &g) {
	this->g = g;
}

void GravityForce::updateForce(Ship* s, float t) {
    s->forces.y += t;
}
ThrustForce::ThrustForce(float magnitude) {
	this->magnitude = magnitude;
}

void ThrustForce::updateForce(Ship* s, float t) {
	s->forces.x += s->axis.x * t;
    s->forces.y += s->axis.y * t;
	s->forces.z += s->axis.z * t;
}
TurbulenceForce::TurbulenceForce(const ofVec3f &min, const ofVec3f &max) {
	tmin = min;
	tmax = max;
}

void TurbulenceForce::updateForce(Ship* s, float t) {
	//
	// We are going to add a little "noise" to a particles
	// forces to achieve a more natual look to the motion
	//
	// force
    s->forces.x += ofRandom(tmin.x, tmax.x);
    s->forces.y += ofRandom(tmin.y, tmax.y);
    s->forces.z += ofRandom(tmin.z, tmax.z);
}

void Ship::integrate() {
	//pos += (velocity*dt);
	glm::vec3 current = model.getPosition();
	current += (velocity * dt);
	model.setPosition(current.x, current.y, current.z);
	
	rotation += (angularVelocity * dt);

	// update acceleration with accumulated paritcles forces
	// (a = 1/m * f)
	//
	ofVec3f accel = acceleration;    // start with any acceleration already on the particle
	accel += (forces * (1.0 / mass));
	//cout << "accel: " << accel << endl;
	velocity += accel * dt;

	//add damping
	velocity *= 0.99;
	angularVelocity *= 0.8;

	forces = ofVec3f(0, 0, 0);
}

void Ship::setup() {
    //load sprite
    if(bubble.load("bubbleSprite.png"))
        cout << "exhaust sprite loaded" << endl;
    else {ofLogFatalError("can't load bubble sprite");}
	// set up exhaust
	exhaust.sys->addForce(new GravityParticleForce(ofVec3f(0, -10, 0)));
	exhaust.sys->addForce(new TurbulenceParticleForce(ofVec3f(-2, -1, -3), ofVec3f(1, 2, 5)));
    exhaust.velocity = ofVec3f(0,-20,0);
    exhaust.setEmitterType(DirectionalEmitter);
    //exhaust.setImage(bubble);
	exhaust.start();

	// move to starting point
	this->position = ofVec3f(65, 28, 40);
	this->model.setPosition(65, 28, 40);
}


void Ship::update() {
    if(thrustersOn)
        exhaust.update();
	exhaust.setPosition(model.getPosition());
    exhaust.velocity = ofVec3f(0,-20,0);
	model.setRotation(model.getNumRotations(), rotation, 0, 1, 0);
}

void Ship::draw() {
	// draw ship's exhaust
    if(thrustersOn)
        exhaust.draw();
}

void Ship::setPosition(const ofVec3f & p) {
	this->position = p;
	this->model.setPosition(p.x, p.y, p.z);
}
