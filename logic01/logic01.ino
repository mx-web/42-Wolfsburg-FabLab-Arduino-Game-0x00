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

int interval = 30;
unsigned long previousMillis = 0;

void setup() { 
   FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
   pinMode(4, INPUT);
   Serial.begin(9600);
}
void loop() {
  
    unsigned long currentMillis = millis();
    
    for(ledPositionIndex; ledPositionIndex < NUM_LEDS; ledPositionIndex++) { 
        if (currentMillis - previousMillis >= interval) {
          // save the last time you blinked the LED
          previousMillis = currentMillis;
          
          // if the LED is off turn it on and vice-versa:
          leds[ledPositionIndex] = CRGB::Blue;
          leds[goalLEDIndex] = CRGB::Pink;
          FastLED.show();
          if (ledState == LOW) {
            ledState = HIGH;
          } else {
            ledState = LOW;
          }
        leds[ledPositionIndex] = CRGB::Blue;
        leds[goalLEDIndex] = CRGB::Pink;
        FastLED.show();
        delay(interval);
        playerOneButtonState = digitalRead(playerOneButtonPin);
    
        if(playerOneButtonState == HIGH && ledPositionIndex == goalLEDIndex) {
          goalLEDIndex = random(0, 50);
          interval -= 2;
          Serial.println(interval);
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
