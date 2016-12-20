#include "Arduino.h"
#include "HEXRGBLed.h"


/* Small macro as a closure for repetitive map function*/
#define MAP_TO_ANALOG_FULL_FORMAT(HEXColorMask) map(HEXColorMask,0,0xFF,255,0)
#define MAP_TO_ANALOG_SMALL_FORMAT(HEXColorMask) map(HEXColorMask,0,0xF,255,0)


/* Constructor */
RGBLed::RGBLed(const int redPinNo, const int greenPinNo, 
                const int bluePinNo, bool enableDebug = false) {
  redPin = redPinNo;
  greenPin = greenPinNo;
  bluePin = bluePinNo;
  debugData = enableDebug;

  pinMode(redPin  ,OUTPUT);   digitalWrite(redPin   ,HIGH);
  pinMode(greenPin,OUTPUT);   digitalWrite(greenPin ,HIGH);
  pinMode(bluePin ,OUTPUT);   digitalWrite(bluePin  ,HIGH);
  
}

uint8_t RGBLed::getBlueVal(uint32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(MAP_TO_ANALOG_FULL_FORMAT( ((HEXColor & 0xFF)>>0) ));
  else
    return (uint8_t)(MAP_TO_ANALOG_SMALL_FORMAT(  ((HEXColor & 0xF)>>0) ));
}

uint8_t RGBLed::getGreenVal(uint32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(MAP_TO_ANALOG_FULL_FORMAT( ((HEXColor & 0x00FF00)>>8) ));
  else
    return (uint8_t)(MAP_TO_ANALOG_SMALL_FORMAT(  ((HEXColor & 0x0F0)   >>4) ));
}

uint8_t RGBLed::getRedVal(uint32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(MAP_TO_ANALOG_FULL_FORMAT( ((HEXColor & 0xFF0000)>>16) ));
  else
    return (uint8_t)(MAP_TO_ANALOG_SMALL_FORMAT(  ((HEXColor & 0xF00)   >>8) ));
}

void RGBLed::setColor(uint32_t HEXColor) {
  
  analogWrite(redPin   , getRedVal(HEXColor)   );
  analogWrite(greenPin , getGreenVal(HEXColor) );  
  analogWrite(bluePin  , getBlueVal(HEXColor)  );
  if(debugData == true) {
    Serial.print(getRedVal(HEXColor));
    Serial.print(",");
    Serial.print(getGreenVal(HEXColor));
    Serial.print(",");
    Serial.println(getBlueVal(HEXColor));
  }
}



