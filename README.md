[![](https://raw.githubusercontent.com/IslamNegm/Arduino-RGBLed-Library/master/preview_HEXRGBLed.gif)]

# Arduino-RGBLed-Library
Arduino Library for easy to use RGB Led Colors using the HEX value of the color, and equipped with web color conventions for easy use.

# Usage
Simple program will go like this
```arduino
/*
  Example on Arduino Library for easy to
  use RGB Led Colors using the HEX value 
  of the color, and equipped with web color 
  conventions for easy usage.

  Just switching the blue and red lights on the led

  connection: 
    red     > D6 (PWM)
    green   > D5 (PWM)
    blue    > D3 (PWM)
*/

#include <HEXRGBLed.h>
#include <webColorHEXCodes.h>

const int redPin = 6, greenPin = 5, bluePin = 3; 

RGBLed rgb(redPin, greenPin, bluePin);

void setup() {
 
}

void loop() {
  rgb.setColor(color_DarkBlue);
  delay(1000);
  rgb.setColor(color_DarkRed);
  delay(1000);
}

```
