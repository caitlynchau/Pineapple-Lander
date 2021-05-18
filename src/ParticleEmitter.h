#pragma once

//#include "TransformObject.h"
#include "ParticleSystem.h"

typedef enum { DirectionalEmitter, RadialEmitter, SphereEmitter } EmitterType;

//  General purpose Emitter class for emitting sprites
//  This works similar to a Particle emitter
//
class ParticleEmitter {
public:
	ParticleEmitter();
	ParticleEmitter(ParticleSystem *s);
	~ParticleEmitter();
	void init();
	void draw();
	void start();
	void stop();
	void setLifespan(const float life) { lifespan = life; }
	void setVelocity(const ofVec3f &vel) { velocity = vel; }
	void setRate(const float r) { rate = r; }
	void setParticleRadius(const float r) { particleRadius = r; }
	void setEmitterType(EmitterType t) { type = t; }
	void update();

	// from TransformObject
	void setPosition(const ofVec3f &);
	ofVec3f position, scale;
	float	rotation;
	bool	bSelected;

	ParticleSystem *sys;
	float rate;         // per sec
	ofVec3f velocity;
	float lifespan;     // sec
	bool started;
	float lastSpawned;  // ms
	float particleRadius;
	float radius;
	bool visible;
	bool createdSys;
	EmitterType type;


};
