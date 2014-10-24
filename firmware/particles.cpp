/*
Arduino library to simulate particle emission with an RGB LED strip.
Copyright (C) Stumpware
MIT license
*/

#include "particles.h"
#include <stdlib.h>

#define MAX_COLOR 255

/*****************************************************************************/

ParticleEmitter::ParticleEmitter(int n) {
    numPixels = n;
    numParticles = MAX_PARTICLES;
    maxVelocity = float(numParticles / 5000.0);
    stripPosition = ((rand() * 70) + 15) / 100.0;  // 0.0 - 1.0
    
    for (int i=0; i < MAX_PARTICLES; i++) {
        particles[i] = newParticle();
    }
}

particle ParticleEmitter::newParticle() {
    particle p;
    
    int direction = ((rand() * 2) == 0 ? 1 : -1);
    int maxColor = MAX_COLOR * (1.0 - ((rand() * 50) / 100));

    p.velocity = (((rand() * 99) + 1) / 100.0) * direction;
    
    if (direction > 0) {
        p.redColor = rand() * maxColor;
        p.greenColor = rand() * (maxColor * 0.25);
        p.blueColor = rand() * (maxColor*0.75);
    }
    else {
        p.redColor = rand() * maxColor;
        p.greenColor = rand() * (maxColor*0.25);
        p.blueColor = rand() * (maxColor*0.75);
    }
    
    p.startStripPosition = stripPosition;
    p.currentStripPosition = p.startStripPosition;
    p.dimmed = 0;

    return p;
}

void ParticleEmitter::begin(void) {
}

particle ParticleEmitter::updateParticle(int i) {
    particle *p = &particles[i];
    
    p->currentStripPosition = p->currentStripPosition +
                              (maxVelocity * p->velocity);  

    p->dimmed = (rand() * 3 == 0 ? 1 : 0);
    
    if (0) {
        if (p->currentStripPosition < 0.0)
            p->currentStripPosition = 1.0;
        else if (p->currentStripPosition > 1.0)
            p->currentStripPosition = 0.0;
    }
    else {
        if (p->currentStripPosition < -1.0 || p->currentStripPosition > 2.0)
            *p = newParticle();
    }

    return *p;
}





