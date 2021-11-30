#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// PIN assignment
#define PIN_TFT_DC 9
#define PIN_TFT_CS 10

// Global Initialization
Adafruit_ILI9341 tft = Adafruit_ILI9341(PIN_TFT_CS, PIN_TFT_DC);

void setup()
{
  tft_init();
  tft_welcome();
}

void loop()
{

}

void tft_init(void)
{
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
}

void tft_welcome(void)
{
  tft.setCursor(100, 90);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("WELCOME");
  tft.setCursor(110, 115);
  tft.println("SCREEN");
}
