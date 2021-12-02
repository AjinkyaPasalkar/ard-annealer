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

void tft_draw_border(uint16_t clr)
{
  tft.drawRect(0, 0, tft.width(), tft.height(), clr);
  tft.drawRect(1, 1, tft.width()-2, tft.height()-2, clr);
}
void tft_draw_sc1(void)
{
  tft.fillScreen(ILI9341_BLACK);

  tft_draw_border(ILI9341_RED);
  
  tft.drawRect(10, 200, 140, 30, ILI9341_WHITE);
  tft.drawRect(11, 201, 138, 28, ILI9341_WHITE);

  tft.drawRect(170, 200, 140, 30, ILI9341_WHITE);
  tft.drawRect(171, 201, 138, 28, ILI9341_WHITE);

  tft.setTextSize(3);
  tft.setCursor(10, 10);
  tft.println("SELECT CASE");

  tft.setTextSize(2);
  tft.setCursor(45, 208);
  tft.println("SELECT");

  tft.setTextSize(2);
  tft.setCursor(220, 208);
  tft.println("ADD");
}
