#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define NUM_LEDS_OUTSIDE_RING 30
#define NUM_LEDS_INSIDE_RING 25

Adafruit_NeoPixel stripInside = Adafruit_NeoPixel(NUM_LEDS_INSIDE_RING, 2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripInside2 = Adafruit_NeoPixel(NUM_LEDS_INSIDE_RING, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel stripOutside = Adafruit_NeoPixel(NUM_LEDS_OUTSIDE_RING, 3, NEO_GRB + NEO_KHZ800);

void setup() {
        stripInside.begin();
        stripInside2.begin();
        stripOutside.begin();
        stripInside.show();
        stripInside2.show();
        stripOutside.show();
}

void loop() {

        int r = 225;
        int g = 130;
        int b = 30;

        for(int x = 0; x <NUM_LEDS_OUTSIDE_RING; x++)
        {
                int flicker = random(0,125);
                int r1 = r-flicker;
                int g1 = g-flicker;
                int b1 = b-flicker;
                if(g1<0) g1=0;
                if(r1<0) r1=0;
                if(b1<0) b1=0;
                stripInside.setPixelColor(x,r1,g1, b1);
                stripInside2.setPixelColor(x,r1,g1, b1);
                stripOutside.setPixelColor(x,r1,g1, b1);
        }

        stripInside.show();
        stripInside2.show();
        stripOutside.show();

        delay(random(25,180));
}
