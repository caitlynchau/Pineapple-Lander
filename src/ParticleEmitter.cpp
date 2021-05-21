
#include "ParticleEmitter.h"

ParticleEmitter::ParticleEmitter() {
	sys = new ParticleSystem();
	createdSys = true;
	position = ofVec3f(0, 0, 0);
//	scale = ofVec3f(1, 1, 1);
//	rotation = 0;
	init();
}

ParticleEmitter::ParticleEmitter(ParticleSystem *s) {
	if (s == NULL)
	{
		cout << "fatal error: null particle system passed to ParticleEmitter()" << endl;
		ofExit();
	}
	sys = s;
	createdSys = false;
	init();
}

ParticleEmitter::~ParticleEmitter() {

	// deallocate particle system if emitter created one internally
	//
	if (createdSys) delete sys;
}

void ParticleEmitter::init() {
	rate = 5;
	velocity = ofVec3f(0, 20, 0);
	lifespan = 2;
	started = false;
    oneShot = false;
    fired = false;
	lastSpawned = 0;
	radius = 1;
	particleRadius = .2;
	visible = true;
    groupSize = 1;
	type = RadialEmitter;
    haveImage = false;
}


void ParticleEmitter::draw() {
	if (visible) {
		switch (type) {
		case DirectionalEmitter:
			//ofDrawSphere(position, radius / 10);  // just draw a small sphere for point emitters
			break;
		case SphereEmitter:
		case RadialEmitter:
			//ofDrawSphere(ofVec3f(ofRandom(position.x-2, position.x+2), ofRandom(position.y-2, position.y+2), position.z), radius/10);
			//ofDrawSphere(position, radius / 10);  // just draw a small sphere as a placeholder
			break;
		default:
			break;
		}
	}
	sys->draw();
}

void ParticleEmitter::setPosition(const ofVec3f & pos) {
	position = pos;
}

void ParticleEmitter::start() {
	started = true;
	lastSpawned = ofGetElapsedTimeMillis();
}

void ParticleEmitter::stop() {
	started = false;
    fired = false;
}
void ParticleEmitter::update() {
    
    float time = ofGetElapsedTimeMillis();
    
        if (oneShot && started) {
            if (!fired) {
                //cout << "inside update" << endl;
                // spawn a new particle(s)
                //
                for (int i = 0; i < groupSize; i++)
                    spawn(time);
    
                lastSpawned = time;
            }
            fired = true;
            stop();
        }
    
        else if (((time - lastSpawned) > (1000.0 / rate)) && started) {
    
            // spawn a new particle(s)
            //
            for (int i= 0; i < groupSize; i++)
                spawn(time);
        
            lastSpawned = time;
        }
    
    sys->update();
//	if (!started) return;
//
//	float time = ofGetElapsedTimeMillis();
//
//	if ((time - lastSpawned) > (1000.0 / rate)) {
//
//		// spawn a new particle
//		//
//		Particle particle;
//
//		// set initial velocity and position
//		// based on emitter type
//		//
//		switch (type) {
//		case RadialEmitter:
//			//		break;
//		case SphereEmitter:
//			//		break;
//		case DirectionalEmitter:
//			particle.velocity = velocity;
//			particle.position.set(position);
//			break;
//		}
//
//		// other particle attributes
//		//
//		particle.lifespan = lifespan;
//		particle.birthtime = time;
//		particle.radius = particleRadius;
//
//		// add to system
//		//
//		sys->add(particle);
//		lastSpawned = time;
//	}
//	sys->update();
}
void ParticleEmitter::spawn(float time) {

    Particle particle;
    // set initial velocity and position
    // based on emitter type
    //
    switch (type) {
    case RadialEmitter:
    {
        //cout << "radial case" << endl;
        ofVec3f dir = ofVec3f(ofRandom(-10, 10), ofRandom(-10, 10), ofRandom(-10, 10));
        float speed = velocity.length();
        particle.velocity = dir.getNormalized() * speed;
        particle.position.set(position);
    }
    break;
    case SphereEmitter:
        break;
    case DirectionalEmitter:
        particle.velocity = velocity;
        particle.position.set(position);
        break;
    }
    particle.lifespan = lifespan;
    particle.birthtime = time;
    particle.radius = particleRadius;
    if(haveImage)
        particle.setImage(image);
            
    sys->add(particle);
}

void ParticleEmitter::setImage(ofImage img) {
    image = img;
    haveImage = true;
}

