#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#include "PIN.h"
#include "screen.h"

// Global Initialization
Adafruit_ILI9341 tft = Adafruit_ILI9341(PIN_TFT_CS, PIN_TFT_DC);

void setup()
{
  tft_init();
}

void loop()
{

}
