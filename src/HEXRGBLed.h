/*
  rgbLed.h - Arduino Library for easy to
  use RGB Led Colors using the HEX value 
  of the color, and equipped with web color 
  conventions for easy usage.

  by : https://github.com/IslamNegm
*/

#ifndef _RGBLED_H_
#define _RGBLED_H_
#include <stdint.h>   /* For using the standard int datatypes */
#include <string.h>   /* For the strlen() function */
#include "webColorHEXCodes.h"


class RGBLed {
    int redPin, greenPin, bluePin;
    /* 
     *  0xFFFFFF >> full format
     *  0xFFF    >> apperviated format (small)
    */
    bool fullFormat = true;
    
    uint8_t getRedVal(int32_t HEXColor);
    uint8_t getGreenVal(int32_t HEXColor);
    uint8_t getBlueVal(int32_t HEXColor);
    int32_t getHEXValFromStr (char * HEXStr);
  public: 
    RGBLed (const int redPin, const int greenPin, const int bluePin);
    void setColor(char *HEXColorStr);
};
#endif
