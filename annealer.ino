#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
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

// Schedular Setup
#define TASK_INTV_TOUCH 10
#define TASK_OFST_TOUCH 0
unsigned long currMillis = 0;
unsigned long prevMillis_TOUCH = 0;


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
  currMillis = millis();
  
  if ((currMillis - prevMillis_TOUCH - TASK_OFST_TOUCH) >= TASK_INTV_TOUCH)
  {
    prevMillis_TOUCH = currMillis;
    task_touch();
  }

}
