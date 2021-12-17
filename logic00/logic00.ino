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
   randomSeed(analogRead(0));
   Serial.begin(9600);
}
void loop() {
    for(ledPositionIndex; ledPositionIndex < NUM_LEDS; ledPositionIndex++) { 
        leds[ledPositionIndex] = CRGB::Blue;
        leds[goalLEDIndex] = CRGB::Green;
        FastLED.show();
        delay(LEDdelay);
        if (playerIndex == 1){
          playerOneButtonState = digitalRead(playerOneButtonPin);
      
          if(playerOneButtonState == HIGH && ledPositionIndex == goalLEDIndex) {
            goalLEDIndex = random(0, 50);
            LEDdelay -= 2;
            playerOneCount++;
            Serial.println(LEDdelay);
            delay(100);
          }
          else if (playerOneButtonState == HIGH && ledPositionIndex != goalLEDIndex){
              playerOneErrorCount++;
              delay(75);
               Serial.println(playerOneErrorCount);
            }
           if (playerOneErrorCount == maxerror){
            fill_solid(leds,50, CRGB::Red);
            
            FastLED.show();
            delay(1000);
            fill_solid(leds,50, CRGB::Black);
           
            playerIndex = 2;
            }
          
        }
        if (playerIndex == 2){
          playerTwoButtonState = digitalRead(playerOneButtonPin);
      
          if(playerTwoButtonState == HIGH && ledPositionIndex == goalLEDIndex) {
            goalLEDIndex = random(0, 50);
            LEDdelay -= 2;
            playerOneCount++;
            Serial.println(LEDdelay);
            delay(100);
          }
          else if (playerTwoButtonState == HIGH && ledPositionIndex != goalLEDIndex){
              playerTwoErrorCount++;
              delay(75);
               Serial.println(playerTwoErrorCount);
            }
           if (playerTwoErrorCount == maxerror){
            fill_solid(leds,50, CRGB::Red);
            
            FastLED.show();
            delay(1000);
            fill_solid(leds,50, CRGB::Black);
           
            playerIndex = 1;
            }
          
        }
        // clear this led for the next time around the loop
        leds[ledPositionIndex] = CRGB::Black;
        leds[goalLEDIndex] = CRGB::Green;
        FastLED.show();
        delay(LEDdelay);
    }
  leds[goalLEDIndex] = CRGB::Black;
  FastLED.show();
  ledPositionIndex = 0;
  
}
