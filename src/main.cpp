#include <Arduino.h>
#include <FastLED.h>

#define BRIGHTNESS 10

#define NUM_LEDS 34
#define DATA_PIN 0

#define FADE_BY 128
#define DELAY_TIME 50

CRGB leds[NUM_LEDS];

void setup()
{
  delay(100); // power-up safety delay
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

// void fadeVelp()
// {
//   for (int i = 0; i < 8; i++)
//   {
//     leds[i].nscale8_video(FADE_BY);
//   }
// }

static uint8_t hue = 0;

void setSection(uint8_t start, uint8_t end)
{
  for (int i = start; i < end; i++)
  {
    leds[i] = CHSV(hue++, 255, 255);
    FastLED.show();
    for (int j = start; j < end; j++)
    {
      leds[j].nscale8_video(FADE_BY);
    }
    delay(DELAY_TIME);
  }
}

void loop()
{
  // setSection(0, 8);
  // setSection(8, 20);

  for (int i = 0; i < 12; i++)
  {
    leds[i] = CHSV(hue++, 255, 255);
    leds[i + 8] = CHSV(hue, 255, 255);
    leds[i + 20] = CHSV(hue, 255, 255);

    FastLED.show();
    for (int j = 0; j < NUM_LEDS; j++)
    {
      leds[j].nscale8_video(FADE_BY);
    }
    delay(DELAY_TIME);
  }

  // setSection(20, 33);
  // for (int i = 0; i < 8; i++)
  // {
  //   leds[i] = CHSV(hue++, 255, 255);
  //   FastLED.show();
  //   fadeVelp();
  //   delay(50);
  // }
  // for (int i = 9; i < 20; i++)
  // {
  //   leds[i] = CHSV(hue++, 255, 255);
  //   FastLED.show();
  //   fadeVelp();
  //   delay(50);
  // }
  // for (int i = 21; i < 33; i++)
  // {
  //   leds[i] = CHSV(hue++, 255, 255);
  //   FastLED.show();
  //   fadeVelp();
  //   delay(50);
  // }
}