#include <FastLED.h>
#define NUM_LEDS 50
#define DATA_PIN 3
CRGB leds[NUM_LEDS];


int ledPositionIndex = 0;
int playerIndex = 1; // Player One = 1, Player Two = 2

int playerOneDelay = 30;
int playerTwoDelay = 30;

int playerOneCount = 0;
int playerTwoCount = 0;

int playerOneButtonState = 0;
int playerTwoButtonState = 0;

int goalLEDIndex = 24;
    
void setup() { 
   FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
}
void loop() {
    for(ledPositionIndex; ledPositionIndex < NUM_LEDS; ledPositionIndex++) { 
        leds[dot] = CRGB::Blue;
        leds[goalLEDIndex] = CRGB::Pink;
        FastLED.show();
        delay(30);
        // clear this led for the next time around the loop
        leds[dot] = CRGB::Black;
        leds[goalLEDIndex] = CRGB::Pink;
        FastLED.show();
        delay(30);
    }
  goalLEDIndex = random(0, 50);
    
}
