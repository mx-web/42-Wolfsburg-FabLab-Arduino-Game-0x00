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
  
    
    
    for(ledPositionIndex; ledPositionIndex < NUM_LEDS; ledPositionIndex++) { 
        leds[ledPositionIndex] = CRGB::Blue;
        leds[goalLEDIndex] = CRGB::Pink;
        FastLED.show();
        delay(LEDdelay);
        playerOneButtonState = digitalRead(playerOneButtonPin);
    
        if(playerOneButtonState == HIGH && ledPositionIndex == goalLEDIndex) {
          goalLEDIndex = random(0, 50);
          LEDdelay -= 2;
          Serial.println(LEDdelay);
        }
        // clear this led for the next time around the loop
        leds[ledPositionIndex] = CRGB::Black;
        leds[goalLEDIndex] = CRGB::Pink;
        FastLED.show();
        delay(LEDdelay);
    }
  leds[goalLEDIndex] = CRGB::Black;
  FastLED.show();
  ledPositionIndex = 0;
  
}
