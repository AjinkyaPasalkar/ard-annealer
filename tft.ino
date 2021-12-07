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
  tft_draw_thick_rect(0, 0, tft.width(), tft.height(), clr, 2);
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
  tft.drawRect(10, 40, 320 - 10 - 10, 145, ILI9341_WHITE);
  tft.drawRect(270, 40, 40, 73, ILI9341_WHITE);
  tft.drawRect(270, 40 + 72, 40, 73, ILI9341_WHITE);
  tft.drawFastHLine(10, 40 + 48, 260, ILI9341_WHITE);
  tft.drawFastHLine(10, 40 + 48 + 48, 260, ILI9341_WHITE);

  // button 1
  tft_draw_thick_rect(TFT_SC1_BTN1_RECT_X, TFT_SC1_BTN1_RECT_Y,
                      TFT_SC1_BTN1_RECT_XLEN, TFT_SC1_BTN1_RECT_YLEN,
                      TFT_SC1_BTN1_RECT_CLR, TFT_SC1_BTN1_RECT_THICK);
  tft.setTextSize(TFT_SC1_BTN1_TXT_SIZE);
  tft.setCursor(TFT_SC1_BTN1_TXT_X, TFT_SC1_BTN1_TXT_Y);
  tft.println(TFT_SC1_BTN1_TXT);

  // button 2
  tft_draw_thick_rect(TFT_SC1_BTN2_RECT_X, TFT_SC1_BTN2_RECT_Y,
                      TFT_SC1_BTN2_RECT_XLEN, TFT_SC1_BTN2_RECT_YLEN,
                      TFT_SC1_BTN2_RECT_CLR, TFT_SC1_BTN2_RECT_THICK);
  tft.setTextSize(TFT_SC1_BTN2_TXT_SIZE);
  tft.setCursor(TFT_SC1_BTN2_TXT_X, TFT_SC1_BTN2_TXT_Y);
  tft.println(TFT_SC1_BTN2_TXT);
}

/*!
    @brief    Draw rectangle with thickness.
    @param    x,y        Coordinates.
    @param    w,h        Height and width.
    @param    color      Color of rectangle.
    @param    thickness  Thickness of rectangle.
*/
void tft_draw_thick_rect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, int8_t thickness)
{
  for (int8_t i = 0; i < thickness; i++)
  {
    tft.drawRect(x + i, y + i, w - (2 * i), h - (2 * i), color);
  }
}
