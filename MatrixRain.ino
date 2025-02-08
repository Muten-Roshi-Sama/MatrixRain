#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include "DigitalRainAnim.h"


// TFT object initialization
TFT_eSPI tft = TFT_eSPI();

DigitalRainAnim digitalRainAnim = DigitalRainAnim(); 

// **User-defined animation speed variables**
int new_line_len_min = 5;
int new_line_len_max = 18;
int min_line_speed = 3;  // Minimum speed of falling characters (higher = slower)
int max_line_speed = 5;  // Maximum speed of falling characters (higher = slower)
int frame_delay = 20;    // Time delay per frame (lower = faster animation)



void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  digitalRainAnim.init(&tft, new_line_len_min, new_line_len_max, min_line_speed, max_line_speed, frame_delay);
}

void loop() {
  
  if(millis()>5000) digitalRainAnim.stop();

  if(millis()>7000) digitalRainAnim.resume();


  digitalRainAnim.loop();
}



