/*!
    @brief    Initialise TFT LCD
*/
void tft_init(void)
{
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
}

/*!
    @brief    Draw welcome screen
*/
void tft_welcome(void)
{
  tft.setCursor(100, 90);
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(3);
  tft.println("WELCOME");
  tft.setCursor(110, 115);
  tft.println("SCREEN");
}

/*!
    @brief    Draw border around the screen.
    @param    clr  Colour of the border.
    @note     Use this to indicate current state of the system.
              White: Normal
              Green: Running
              Red: Error
*/
void tft_draw_border(uint16_t clr)
{
  tft.drawRect(0, 0, tft.width(), tft.height(), clr);
  tft.drawRect(1, 1, tft.width() - 2, tft.height() - 2, clr);
}

/*!
    @brief    Draw screen 1
*/
void tft_draw_sc1(void)
{
  tft.fillScreen(ILI9341_BLACK);

  tft_draw_border(ILI9341_WHITE);

  // title
  tft.setTextSize(3);
  tft.setCursor(10, 10);
  tft.println("SELECT CASE");

  // selection window
  tft.drawRect(10, 40, 320-10-10, 145, ILI9341_WHITE);
  tft.drawRect(270, 40, 40, 73, ILI9341_WHITE);
  tft.drawRect(270, 40+72, 40, 73, ILI9341_WHITE);
  tft.drawFastHLine(10, 40+48, 260, ILI9341_WHITE);
  tft.drawFastHLine(10, 40+48+48, 260, ILI9341_WHITE);

  // button 1
  tft.drawRect(10, 200, 140, 30, ILI9341_WHITE);
  tft.drawRect(11, 201, 138, 28, ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(45, 208);
  tft.println("SELECT");

  // button 2
  tft.drawRect(170, 200, 140, 30, ILI9341_WHITE);
  tft.drawRect(171, 201, 138, 28, ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(220, 208);
  tft.println("ADD");
}
