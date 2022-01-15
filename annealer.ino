#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Fonts/FreeSerifBold12pt7b.h>
#include <Fonts/FreeSerifBold18pt7b.h>
#include <XPT2046_Touchscreen.h>
#include <Servo.h>
#include <EEPROM.h>
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
  uint8_t   prev_screen_id; /*!< Previous screen id */
  bool      motor;          /*!< Motor status. ON/OFF */
  uint32_t  motor_time;     /*!< Motor ON time. ms */
  bool      ir;             /*!< IR status. Object Detected/Not Detected */
  bool      ssr;            /*!< SSR status. ON/OFF */
  uint32_t  ssr_time;       /*!< SSR ON time. ms */
  bool      servo;          /*!< Servo status. 0/90 */
  uint32_t  servo_time;     /*!< Servo 90 time. ms */
  uint16_t  count;          /*!< Number of cases completed */
  int16_t   total_cases;    /*!< Total number of cases to be completed */
  int8_t    case_id;        /*!< Selected case id */
  char     *case_name;      /*!< Selected case name */
  uint8_t   case_time_sec;  /*!< Selected case time seconds */
  uint8_t   case_time_msec; /*!< Selected case time milliseconds */
  uint8_t   ann_state;      /*!< Annealing state. 0-Stopped 1-Running 2-Paused */
} MACHINE_STATE;
struct
{
  int8_t  selected_id;
  uint8_t max_cases;
} SC1_STATE;
struct
{
  int16_t count;
} SC2_STATE;
struct
{
  char casename[20];        /*!< New case name to be added */
} SC3_STATE;
struct
{
  int8_t sec;             /*!< Current case seconds */
  int8_t msec;            /*!< Current case miliseconds */
  bool save_enabled;      /*!< Enabled if current case sec msec is changed */
} SC4_STATE;
struct
{
  char textbox[20];         /*!< Case name data holder */
  uint8_t keyboard_page;    /*!< Current keybpard screen page */
} SC5_STATE;

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
