#include<FastLED.h>

#define LED_PIN 6
#define NUM_LEDS 10

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
int soundsensor = 8;

void setup() {
  delay(3000);
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(25);
  pinMode(soundsensor, INPUT);

}

void loop() {
int sensval = digitalRead(soundsensor);

if (sensval == 1){
  Serial.println("ON");
  //leds[0] = CRGB :: Red;
  //fill_solid(leds, NUM_LEDS, CRGB :: Blue);
  rainbow_moving();
  FastLED.show();
  delay(10);
  } else {
  //leds[0] = CRGB :: Black; 
  fill_solid(leds, NUM_LEDS, CRGB :: Black);
  FastLED.show();
  delay(10); 
  }
}

void rainbow_moving(){
  for(int i=0; i<NUM_LEDS; i++){
    leds[i] = CHSV(hue + (i * 10), 255, 255);
    } 
  
  EVERY_N_MILLISECONDS(10){
    hue++;
    }
}
