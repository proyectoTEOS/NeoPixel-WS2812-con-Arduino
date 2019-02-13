/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://www.proyecto-teos.com
*/

#include <Adafruit_NeoPixel.h>
uint8_t pinPixelT = 2;
uint8_t widthT = 3;
uint16_t rateT = 35;
uint16_t seriesT = 4;
uint16_t numPixelsT = 8;

Adafruit_NeoPixel stripLedT = Adafruit_NeoPixel(numPixelsT, pinPixelT, NEO_GRB + NEO_KHZ800);

void setup() {
  stripLedT.begin();
  delay(1000);
}

void loop() {
  larsonScannerT(0xFF0000);
  larsonScannerT(0xFF7F00);
  larsonScannerT(0xFFFF00);
  larsonScannerT(0x7FFF00);
  larsonScannerT(0x00FF00);
  larsonScannerT(0x00FF7F);
  larsonScannerT(0x00FFFF);
  larsonScannerT(0x007FFF);
  larsonScannerT(0x0000FF);
  larsonScannerT(0x7F00FF);
  larsonScannerT(0xFF00FF);
  larsonScannerT(0xFF007F);
  larsonScannerT(0xFFFFFF);
}

void larsonScannerT(uint32_t colorT) {
  uint32_t previousValT[numPixelsT];
  for (int iT = 0; iT < seriesT; iT++) {
    for (int countLeftT = 1; countLeftT < numPixelsT; countLeftT++) {
      stripLedT.setPixelColor(countLeftT, colorT);
      previousValT[countLeftT] = colorT;
      for (int xT = countLeftT; xT > 0; xT--) {
        previousValT[xT - 1] = getColorT(previousValT[xT - 1], widthT);
        stripLedT.setPixelColor(xT - 1, previousValT[xT - 1]);
      }
      stripLedT.show();
      delay(rateT);
    }
    for (int countRightT = numPixelsT - 1; countRightT >= 0; countRightT--) {
      stripLedT.setPixelColor(countRightT, colorT);
      previousValT[countRightT] = colorT;
      for (int xT = countRightT; xT <= numPixelsT ; xT++) {
        previousValT[xT - 1] = getColorT(previousValT[xT - 1], widthT);
        stripLedT.setPixelColor(xT + 1, previousValT[xT + 1]);
      }
      stripLedT.show();
      delay(rateT);
    }
  }
}

uint32_t getColorT(uint32_t colorT, uint8_t widthT) {
  return (((colorT & 0xFF0000) / widthT) & 0xFF0000) + (((colorT & 0x00FF00) / widthT) & 0x00FF00) + (((colorT & 0x0000FF) / widthT) & 0x0000FF);
}
