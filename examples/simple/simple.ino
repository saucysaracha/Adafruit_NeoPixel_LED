// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        8 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 150 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels10

void setup() {


  Serial.begin(9600);  // open printf function.
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
 // pixels.show();
}

//rgb, rgb, rgb, rgb..

// Change this to "loop" and the other to loop2 and run.  This will set all of the pixels to the same color in a seqeunce.
// Change the values in the call pixels.Color(R,G,B) to change the color
void loop() {

  pixels.clear(); // Set all pixel colors to 'off'
  int colorRed = 0;
  int colorGreen = 10;
  int colorBlue = 10;
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    
    //pixels.clear(); // Set all pixel colors to 'off'
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //pixels.setPixelColor(i, pixels.Color(0, 50, 0));
    // Here we're using a moderately bright red color:
    pixels.setPixelColor(i, pixels.Color(colorRed, colorGreen, colorBlue));
    colorRed += 0;
    colorGreen += 0;
    colorBlue += 0;
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
}


// Testing out HUEs.  This allows you to select a color on a color wheel from 0 to 65000
//  Where yellow ish is towards 0, and purple is towards 65000.  Makes it easer to get a "linear" color vs RGB colors which is not the easiest to deal with.

// This also shows how to use the print routines to print out the hue value.  Look for "Serial" is this code to see how to open it and use it.
//
void loop2()
{
  uint16_t hueValue;
  uint8_t brightness;
  pixels.clear();

 // Loop through all values of hue which is like a linear color wheel where yellow is 0, purple is 65000 and everything else is in between
 // This link kind of shows it.  https://www.researchgate.net/figure/Cylindrical-HSV-color-model_fig1_261985151
 //  ColorHSV(uint16_t hue, uint8_t sat = 255, uint8_t val = 255);
 // A low sat value makes it pretty white.
 // A high sat value makes it pretty colorfull

  for (hueValue = 0; hueValue<(255*255); hueValue+=1000)
  {
    Serial.print("HUE VALUE = ");
    Serial.println(hueValue);
    brightness = 100;

    pixels.fill(pixels.ColorHSV( hueValue, 240,brightness));
    pixels.show();
    delay(200);
  }
  
}

