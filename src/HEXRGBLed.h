/*
  rgbLed.h - Arduino Library for easy to
  use RGB Led Colors using the HEX value 
  of the color, and equipped with web color 
  conventions for easy usage.

  by : https://github.com/IslamNegm
*/

#ifndef RGBLED_H
#define RGBLED_H
#include <stdint.h>   /* For using the standard int datatypes */
#include "webColorHEXCodes.h"


class RGBLed {
    int redPin, greenPin, bluePin;
    /* 
     *  0xFFFFFF >> full format
     *  0xFFF    >> apperviated format (small)
    */
    bool fullFormat = true;
    /* Set debugData to true in the constuctor to be able
     to print serial lines about the colors status*/
    bool debugData = false; 
    
    uint8_t getRedVal(uint32_t HEXColor);
    uint8_t getGreenVal(uint32_t HEXColor);
    uint8_t getBlueVal(uint32_t HEXColor);
    
  public: 
    RGBLed (const int redPinNo, const int greenPinNo, 
            const int bluePinNo, bool enableDebug = false);
    void setColor(uint32_t HEXColorStr);
};
#endif
