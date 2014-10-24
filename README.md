Particles create particle trails of varyin colors on an LED strip. 

`	
	#include "particles.h"
	
	ParticleEmitter emitter = ParticleEmitter(PIXEL_COUNT);

	void particles() {
	  emitter.stripPosition = random(100) / 100.0;

	  for (int j=0; j < emitter.numParticles * 10; j++) {  
	    
	    for (int i=0; i < emitter.numParticles; i++) {
	      
	      particle prt = emitter.updateParticle(i);
	      uint16_t pixel = leds.numPixels() * prt.currentStripPosition;
	  
	      // High velocity particles have longer tails
	      uint8_t tailLength = abs(prt.velocity * 5);
	      uint8_t slot = pixel;
	      
	      for (int z=0; z < tailLength; z++) { 
	        
	        float colorScale = ( (tailLength-z*0.999) / tailLength );
	        if (z == 0 && prt.dimmed) {
	          colorScale *= 0.25;
	        }

	        strip.setPixelColor(slot, strip.Color(prt.redColor*colorScale, 
	                                              prt.blueColor*colorScale, 
	                                              prt.greenColor*colorScale));

	        slot = pixel + ((z+1) * (prt.velocity > 0 ? -1 : 1));
	      }
	      strip.setPixelCoor(slot, strip.Color(0,0,0));
	    }
	    leds.show();
	    delay(50);
	  }
	}