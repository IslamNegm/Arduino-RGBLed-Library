#include "Arduino.h"
#include "HEXRGBLed.h"


/* Small macro as a closure for repetitive map function*/
#define mapToAnalogFullFormat(HEXColorMask) map(HEXColorMask,0,0xFF,255,0)
#define mapToAnalogSmallFormat(HEXColorMask) map(HEXColorMask,0,0xF,255,0)


/* Constructor */
RGBLed::RGBLed(const int redPinNo, const int greenPinNo, const int bluePinNo) {
  redPin = redPinNo;
  greenPin = greenPinNo;
  bluePin = bluePinNo;
  pinMode(redPin  ,OUTPUT);   digitalWrite(redPin   ,HIGH);
  pinMode(greenPin,OUTPUT);   digitalWrite(greenPin ,HIGH);
  pinMode(bluePin ,OUTPUT);   digitalWrite(bluePin  ,HIGH);
  
}

int32_t RGBLed::getHEXValFromStr (char * HEXStr) {
    char *tempPtr;
    if(*(HEXStr) == '#') {
        HEXStr++;   /*Skip the '#'*/
    }
    /* Check if the string is full or appreviated format */
    if(strlen(HEXStr)>3)
      fullFormat = true;
    else
      fullFormat = false;
      
    return (int32_t) strtol(HEXStr,&tempPtr,16);
}

uint8_t RGBLed::getBlueVal(int32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(mapToAnalogFullFormat( ((HEXColor & 0xFF)>>0) ));
  else
    return (uint8_t)(mapToAnalogSmallFormat(  ((HEXColor & 0xF)>>0) ));
}

uint8_t RGBLed::getGreenVal(int32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(mapToAnalogFullFormat( ((HEXColor & 0x00FF00)>>8) ));
  else
    return (uint8_t)(mapToAnalogSmallFormat(  ((HEXColor & 0x0F0)   >>4) ));
}

uint8_t RGBLed::getRedVal(int32_t HEXColor){
  if(fullFormat == true)
    return (uint8_t)(mapToAnalogFullFormat( ((HEXColor & 0xFF0000)>>16) ));
  else
    return (uint8_t)(mapToAnalogSmallFormat(  ((HEXColor & 0xF00)   >>8) ));
}

void RGBLed::setColor(char *HEXColorStr) {
  int32_t HEXColor = getHEXValFromStr(HEXColorStr);
  analogWrite(redPin   , getRedVal(HEXColor)   );
  analogWrite(greenPin , getGreenVal(HEXColor) );  
  analogWrite(bluePin  , getBlueVal(HEXColor)  );
  Serial.print(getRedVal(HEXColor));
  Serial.print(",");
  Serial.print(getGreenVal(HEXColor));
  Serial.print(",");
  Serial.println(getBlueVal(HEXColor));
}



