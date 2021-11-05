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

int playerOneErrorCount = 0;
int playerTwoErrorCount = 0;

int maxerror = 5;

int playerOneButtonState = 0;
int playerTwoButtonState = 0;

int playerOneButtonPin = 2;
int playerTwoButtonPin = 0;

int goalLEDIndex = 24;

int LEDdelay = 30;
    
void setup() { 
   FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
   pinMode(4, INPUT);
   Serial.begin(9600);
}
void loop() {
    fill_solid(leds,50, CRGB::Black);
    
  //leds[goalLEDIndex] = CRGB::Black;
  //FastLED.show();
  ledPositionIndex = 0;
  
}
