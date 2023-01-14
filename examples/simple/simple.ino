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

//Change this to "loop" and the other to loop2 and run.  
//Loop to ust display one color
void loop() {
  //DESCRIPTION: This loop sets all pixels to one color, they sit there and don't do anything
  pixels.show();
  ////pixels.rainbow(1, 1, 255, 255, true);
  pixels.fill(pixels.Color(60, 10, 10));
  //pixels.fill(1, 1, 1); // Idk what I am trying to do here
  //I believe pixels.fill makes all of the pixels one color
  pixels.setBrightness(255); //Makes pixels brighter or dimmer, uint8_t is 0 through 255 decimal
}


//This will set all of the pixels to the same color in a seqeunce.
// Change the values in the call pixels.Color(R,G,B) to change the color
void loop2() {

  //DESCRIPTION: This loop shoots light like shooting star across left to right, switches colors, then goes right to left, repeats for all colors

  //pixels.clear(); // Set all pixel colors to 'off'
  //Initalize colors to pink
  int colorRed= 70;
  int colorGreen= 5;
  int colorBlue = 5;
  //pixels.fill(pixels.ColorHSV((100 * 100), 240, 100));
  pixels.show();

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.

  //This for loop will shoot pixels of light across from left to right
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    //pixels.clear(); // Set all pixel colors to 'off'
    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //pixels.setPixelColor(i, pixels.Color(0, 50, 0));
    // Here we're using a moderately bright red color:
    pixels.setPixelColor(i, pixels.Color(70, 0, 0));

    //If we want each pixel to increase, by a certain amount of colors so that we get an increasing rainbow of sorts, use code below
    //This code is just to make the pixels shoot back and forth though, so I wont do that
    colorRed += 0;
    colorGreen += 0;
    colorBlue += 0;
    pixels.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }

  //This for loop will go from right to left, overriding all the old colors.
  for(int i=NUMPIXELS; i>0; i--) { // For each pixel...
  //pretty tealish aquamarine color
    pixels.setPixelColor(i, pixels.Color(50, 20, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

  //From left to right, new color
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(50, 40, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

  //From right to left, new color
  for(int i=NUMPIXELS; i>0; i--) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(0, 50, 4));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

    //From left to right, new color
    for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(20, 70, 70));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

    //From right to left, new color
    for(int i=NUMPIXELS; i>0; i--) { // For each pixel...
    pixels.setPixelColor(i, pixels.Color(50, 0, 50));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

}


// Testing out HUEs.  This allows you to select a color on a color wheel from 0 to 65000
//  Where yellow ish is towards 0, and purple is towards 65000.  Makes it easer to get a "linear" color vs RGB colors which is not the easiest to deal with.

// This also shows how to use the print routines to print out the hue value.  Look for "Serial" is this code to see how to open it and use it.
//
void loop3()
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
    delay(40);
  }
  
}

