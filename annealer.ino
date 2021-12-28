#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeSerifBold18pt7b.h>
#include <XPT2046_Touchscreen.h>
#include <Servo.h>


#include "PIN.h"
#include "screen.h"

// Global Initialization
Adafruit_ILI9341 tft = Adafruit_ILI9341(PIN_TFT_CS, PIN_TFT_DC);
XPT2046_Touchscreen ts(PIN_TOUCH_CS, PIN_TOUCH_IRQ);
Servo Servo1;

void setup()
{
  touch_init();
  ssr_init();
  ir_init();
  servo_init();
  ed_init();
  tft_init();
}

void loop()
{

}
