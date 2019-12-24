// code based on https://gist.github.com/kriegsman/1f7ccbbfa492a73c015e
#include <Arduino.h>
#include <FastLED.h>

#define BRIGHTNESS 10

#define NUM_LEDS 34
#define DATA_PIN 0

CRGB leds[NUM_LEDS];

void setup()
{
  delay(100); // power-up safety delay
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void fadeall()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i].fadeToBlackBy(32);
    // leds[i].nscale8(250);
  }
}

void loop()
{
  static uint8_t hue = 0;
  // First slide the led in one direction
  for (int i = 0; i < NUM_LEDS; i++)
  {
    // Set the i'th led to red
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(50);
  }

  // // Now go in the other direction.
  // for (int i = (NUM_LEDS)-1; i >= 0; i--)
  // {
  //   // Set the i'th led to red
  //   leds[i] = CHSV(hue++, 255, 255);
  //   // Show the leds
  //   FastLED.show();
  //   // now that we've shown the leds, reset the i'th led to black
  //   // leds[i] = CRGB::Black;
  //   fadeall();
  //   // Wait a little bit before we loop around and do it again
  //   delay(10);
  // }
}

// #include <Arduino.h>
// #include <FastLED.h>

// #define NUM_LEDS 33
// #define DATA_PIN 0
// #define BRIGHTNESS 10

// CRGB leds[NUM_LEDS];

// void setup()
// {
//   FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
//   FastLED.setBrightness(BRIGHTNESS);
// }

// void loop()
// {
//   // Turn the LED on, then pause
//   fill_solid(leds, NUM_LEDS, CRGB::Red);
//   // leds[0] = CRGB::Red;
//   FastLED.show();
//   delay(500);
//   // Now turn the LED off, then pause
//   fill_solid(leds, NUM_LEDS, CRGB::Black);
//   // leds[0] = CRGB::Black;
//   FastLED.show();
//   delay(500);
// }