#pragma once

#include "ParticleSystem.h"

typedef enum { DirectionalEmitter, RadialEmitter, SphereEmitter } EmitterType;

//  General purpose Emitter class for emitting sprites
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
    void setLifespan(const float life)   { lifespan = life; }
    void setVelocity(const ofVec3f &vel) { velocity = vel; }
    void setRate(const float r) { rate = r; }
    void setParticleRadius(const float r) { particleRadius = r; }
    void setEmitterType(EmitterType t) { type = t; }
    void setGroupSize(int s) { groupSize = s; }
    void setOneShot(bool s) { oneShot = s; }
    void setPosition(const ofVec3f & pos);
    void update();
    //void setPosition(ofVec3f p);
    void spawn(float time);
    ParticleSystem *sys;
    float rate;         // per sec
    bool oneShot;
    bool fired;
    ofVec3f velocity;
    float lifespan;     // sec
    bool started;
    float lastSpawned;  // ms
    float particleRadius;
    float radius;
    bool visible;
    int groupSize;      // number of particles to spawn in a group
    bool createdSys;
    float random;
	EmitterType type;
    ofVec3f position;
    
    void setImage(ofImage image);
    ofImage image;
    bool haveImage = false;

	};
