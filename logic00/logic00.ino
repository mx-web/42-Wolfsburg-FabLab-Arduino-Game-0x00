    #include <FastLED.h>
    #define NUM_LEDS 50
    #define DATA_PIN 3
    CRGB leds[NUM_LEDS];
    
   void setup() { 
       FastLED.addLeds<WS2811, DATA_PIN>(leds, NUM_LEDS);
   }
    void loop() {
        for(int dot = 0; dot < NUM_LEDS; dot++) { 
            leds[dot] = CRGB::Blue;
            FastLED.show();
            delay(30);
            // clear this led for the next time around the loop
            leds[dot] = CRGB::Black;
            FastLED.show();
            delay(30);
        }
    }
