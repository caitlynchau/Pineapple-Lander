#include "Particle.h"


Particle::Particle() {

	// initialize particle with some reasonable values first;
	//
	velocity.set(0, 0, 0);
	acceleration.set(0, 0, 0);
	position.set(0, 0, 0);
	forces.set(0, 0, 0);
	lifespan = 5;
	birthtime = 0;
	radius = .1;
	damping = .99;
	mass = 1;
	color = ofColor::white;
}

void Particle::draw() {
    if (haveImage) {
        //cout << "in image" << endl;
        image.resize(7, 7);
        width = 7;
        height = 7;
        image.draw(-image.getWidth() / 2.0 + position.x, -image.getHeight() / 2.0 + position.y);
    }
    else {
        //cout << "in draw" << endl;
        ofSetColor(color);
        //ofDrawSphere(position, radius);
        ofDrawSphere(ofVec3f(ofRandom(position.x - 2, position.x + 2), ofRandom(position.y - 2, position.y + 2), position.z), radius);
    }
}
void Particle::setImage(ofImage img) {
    image = img;
    haveImage = true;
    width = image.getWidth();
    height = image.getHeight();
}

void Particle::integrate() {


	// interval for this step
	float dt = 1.0 / ofGetFrameRate();

	// update position based on velocity
	position += (velocity * dt);

	// update acceleration with accumulated paritcles forces
	// remember :  (f = ma) OR (a = 1/m * f)
	ofVec3f accel = acceleration;    // start with any acceleration already on the particle
	accel += (forces * (1.0 / mass));
	velocity += accel * dt;

	// add a little damping for good measure
	velocity *= damping;

	// clear forces on particle (they get re-added each step)
	forces.set(0, 0, 0);
}

//  return age in seconds
//
float Particle::age() {
	return (ofGetElapsedTimeMillis() - birthtime) / 1000.0;
}
