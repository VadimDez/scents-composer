#include <Adafruit_NeoPixel.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define PIN 5


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "39c668ad76694160a130e698c368fad7";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "JustBox-731";
char pass[] = "JustBox+731";

int ledCount = 48;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(ledCount, PIN, NEO_GRB + NEO_KHZ800);

//int colorVal = 100;
//int x;
//boolean NeopixelColor = false;
int brightness = 255;
int incrementStep = 2;
int increment = incrementStep;
//int prev[3][3] = {
//  {0, 0, 0},
//  {0, 0, 0}
//};
int r = 0;
int rIncrement = incrementStep;
int g = 0;
int gIncrement = incrementStep;
int b = 0;
int bIncrement = incrementStep;
bool reverseIncrement = false;

bool updateRed = true;
bool updateGreen = true;
bool updateBlue = true;


void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show();
  strip.setBrightness(brightness);

  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

//void setBrightness() {
//  strip.setBrightness(brightness);  
//  
//  if (brightness < 0) {
//    brightness = 0;
//    increment = incrementStep;
//  } else if (brightness > 255) {
//    brightness = 255;
//    increment = incrementStep * -1;
//  }
//  
//  brightness += increment;
//}
//
//void colors() {
//  prev[1][0] = prev[0][0];
//  prev[1][1] = prev[0][1];
//  prev[1][2] = prev[0][2];
//  prev[0][0] = r;
//  prev[0][1] = g;
//  prev[0][2] = b;
//
//  if (updateRed && checkMax(r)) {
//    r = r + rIncrement;
//  } else {
//    updateRed = false;
//    rIncrement = rIncrement * -1;
//    r = getMaxValue();
//
//    if (updateGreen && checkMax(g)) {
//      g = g + gIncrement;
//    } else {
//      updateGreen = false;
//      gIncrement = gIncrement * -1;
//      g = getMaxValue();
//      
//      if (checkMax(b)) {
//        b = b + bIncrement;
//      } else {
//        b = getMaxValue();
//        bIncrement = bIncrement * -1;
//        updateRed = true;
//        updateGreen - true;
//        reverseIncrement = !reverseIncrement;
//      }
//    }
//  }
//}

int getMaxValue() {
  return reverseIncrement ? 5 : 250;
}

bool checkMax(int value) {
  return reverseIncrement ? value >= 5 : value <= 250;
}

//void loop() {
//  
//  for (x = 0; x <= 12; x++) {
//    strip.setPixelColor(x, r, g, b);
//    strip.show();
//  }
//
//  
//  for (x = 13; x <= 24; x++) {
//    strip.setPixelColor(x, prev[0][0], prev[0][1], prev[0][2]);
//    strip.show();
//  }
//
//  
//  for (x = 25; x <= 48; x++) {
//    strip.setPixelColor(x, prev[1][0], prev[1][1], prev[1][2]);
//    strip.show();
//  }
//
//  colors(); 
//}

void loop() {
  Blynk.run();
  
  for (int i = 0; i <= 48; i++) {
    strip.setPixelColor(i, r, g, b);
    incrementColors();
    strip.show();
    delay(20);
  }
}

void incrementColors() {
  
  if (updateRed && checkMax(r)) {
    r = r + rIncrement;
  } else {
    updateRed = false;
    rIncrement = rIncrement * -1;
    r = getMaxValue();

    if (updateGreen && checkMax(g)) {
      g = g + gIncrement;
    } else {
      updateGreen = false;
      gIncrement = gIncrement * -1;
      g = getMaxValue();
      
      if (checkMax(b)) {
        b = b + bIncrement;
      } else {
        b = getMaxValue();
        bIncrement = bIncrement * -1;
        updateRed = true;
        updateGreen = true;
        reverseIncrement = !reverseIncrement;
      }
    }
  }
}


