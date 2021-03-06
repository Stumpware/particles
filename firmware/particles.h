#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define MAX_PARTICLES 33

typedef struct {
  float x;
  float y; 
  float z;
} Coord3D;

typedef struct {
    Coord3D velocity;
    uint8_t redColor;
    uint8_t greenColor;
    uint8_t blueColor;
    bool dimmed;
    Coord3D coord;
} Particle;

class ParticleEmitter {

 public:

  ParticleEmitter(uint16_t numPixels, uint8_t maxColor);
  ParticleEmitter(void);
  void
    begin(void);
  Particle
    updateParticle(uint16_t i),
    newParticle();
  float
    stripPosition,
    maxVelocity;    
  uint16_t
    numPixels,    // Number of RGB LEDs in strip
    numParticles;
  uint8_t
    maxColor;
  bool
    respawnOnOtherSide,
    threed;

 private:

  Particle
    particles[MAX_PARTICLES];
  float
    masterVelocityDeltaDirection,
    zDeltaDirection;
};
