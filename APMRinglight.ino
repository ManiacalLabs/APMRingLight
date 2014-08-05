//APMRingLight
//by Dan, of ManiacalLabs.com
//Ft. FastLED light control by focalintent: github.com/FastLED/FastLED
//colortable.h by Adam of ManiacalLabs.com

#include "FastLED.h"
#include "colortable.h"

// How many leds in your strip?
#define NUM_LEDS 16

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7
#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

int count = 0;

void setup() { 
	FastLED.addLeds<NEOPIXEL, DATA_PIN, GRB>(leds, NUM_LEDS);
	FastLED.setBrightness(128);

}

void loop() { 
	// Comment/Uncomment to change animations

	/*bouncingLED();*/
	/*colorSweep();*/
	pulseColors();
}

void bouncingLED(){
	// First slide the led in one direction
	for(int i = 0; i < NUM_LEDS; i++) {
		// Set the i'th led to red
                if(count == 0){leds[i] = CRGB::Red;}
		if(count == 1){leds[i] = CRGB::Green;}
                if(count == 2){leds[i] = CRGB::Blue;}
                // Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = CRGB::Black;
		// Wait a little bit before we loop around and do it again
		delay(10);
	}

	// Now go in the other direction.  
	for(int i = NUM_LEDS-1; i >= 0; i--) {
		// Set the i'th led to red 
		if(count == 0){leds[i] = CRGB::Red;}
		if(count == 1){leds[i] = CRGB::Green;}
                if(count == 2){leds[i] = CRGB::Blue;}
		// Show the leds
		FastLED.show();
		// now that we've shown the leds, reset the i'th led to black
		leds[i] = CRGB::Black;
		// Wait a little bit before we loop around and do it again
		delay(10);
	}
        count++;
        if(count>2){count=0;}
}

void colorSweep(){
	TRGB sColor = colorMinSec[count];
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB::CRGB(sColor.r, sColor.g, sColor.b);
	}
	count++;
	if (count==60){count=0;}
	FastLED.show();
	delay(1000);
}

void pulseColors(){
	TRGB sColor = colorMinSec[random(1,60)];
	for(int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CRGB::CRGB(sColor.r, sColor.g, sColor.b);
	}
	for(int i = 0; i < 128; i++) {
		FastLED.setBrightness(i);
		FastLED.show();
		delay(10);
	}
	for(int i = 128; i >= 0; i--) {
		FastLED.setBrightness(i);
		FastLED.show();
		delay(10);
	}
	count++;
	if (count==60){count=0;}
	//FastLED.show();
	delay(2000);
}
