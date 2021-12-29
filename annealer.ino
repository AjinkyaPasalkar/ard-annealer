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
struct
{
  uint8_t   screen_id;      /*!< Current screen being displayed */
  bool      motor;          /*!< Motor status. ON/OFF */
  uint32_t  motor_time;     /*!< Motor ON time. ms */
  bool      ir;             /*!< IR status. Object Detected/Not Detected */
  bool      ssr;            /*!< SSR status. ON/OFF */
  uint32_t  ssr_time;       /*!< SSR ON time. ms */
  bool      servo;          /*!< Servo status. 0/90 */
  uint32_t  servo_time;     /*!< Servo 90 time. ms */
  uint16_t  count;          /*!< Number of cases completed */
  uint8_t   case_id;        /*!< Selected case id */
  char     *case_name;      /*!< Selected case name */
  uint16_t  case_time;      /*!< Selected case time. (ms/100) */
} MACHINE_STATE;
struct
{
  uint8_t selected_id;
  uint8_t max_cases;
}SC1_STATE;

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
