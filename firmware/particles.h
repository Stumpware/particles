#define MAX_PARTICLES 33

struct particle {
    float velocity;
    int redColor;
    int greenColor;
    int blueColor;
    int dimmed;
    unsigned long int startTime;
    float startStripPosition;
    float currentStripPosition;
};

class ParticleEmitter {

 public:

  ParticleEmitter(int n);
  ParticleEmitter(void);
  void
    begin(void);
  particle
    updateParticle(int i),
    newParticle();
  float
    stripPosition;
  int
    numPixels,    // Number of RGB LEDs in strip
    numParticles;

 private:

  float
    maxVelocity;
  particle
    particles[MAX_PARTICLES];
};
