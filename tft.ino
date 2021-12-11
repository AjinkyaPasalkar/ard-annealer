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
    @brief    Draw screen 1
*/
void tft_draw_sc1(void)
{
  SCREEN_TEXT_Params textParams;
  
  // Erase previous screen
  tft.fillScreen(ILI9341_BLACK);

  // Draw border of screen white
  tft_draw_border(ILI9341_WHITE);

  // title
  tft_screen_text_params_init(&textParams);
  textParams.x      = TFT_SC1_TITLE_TXT_X;
  textParams.y      = TFT_SC1_TITLE_TXT_Y;
  textParams.text   = TFT_SC1_TITLE_TXT;
  textParams.color  = TFT_SC1_TITLE_TXT_CLR;
  textParams.font   = &TFT_SC1_TITLE_TXT_FONT;
  tft_draw_text(textParams);

  // selection window
  tft.drawRect(10, 40, 320 - 10 - 10, 145, ILI9341_WHITE);
  tft.drawRect(270, 40, 40, 73, ILI9341_WHITE);
  tft.drawRect(270, 40 + 72, 40, 73, ILI9341_WHITE);
  tft.drawFastHLine(10, 40 + 48, 260, ILI9341_WHITE);
  tft.drawFastHLine(10, 40 + 48 + 48, 260, ILI9341_WHITE);
  tft.fillTriangle(290, 70, 280, 85, 300, 85, ILI9341_WHITE);
  tft.fillTriangle(290, 156, 280, 141, 300, 141, ILI9341_WHITE);

  // button 1
  tft_draw_thick_rect(TFT_SC1_BTN1_RECT_X, TFT_SC1_BTN1_RECT_Y,
                      TFT_SC1_BTN1_RECT_XLEN, TFT_SC1_BTN1_RECT_YLEN,
                      TFT_SC1_BTN1_RECT_CLR, TFT_SC1_BTN1_RECT_THICK);
  tft.setFont(&TFT_SC1_BTN1_TXT_FONT);
  tft.setTextSize(TFT_SC1_BTN1_TXT_SIZE);
  tft.setTextColor(TFT_SC1_BTN1_TXT_CLR);
  tft.setCursor(TFT_SC1_BTN1_TXT_X, TFT_SC1_BTN1_TXT_Y);
  tft.println(TFT_SC1_BTN1_TXT);

  // button 2
  tft_draw_thick_rect(TFT_SC1_BTN2_RECT_X, TFT_SC1_BTN2_RECT_Y,
                      TFT_SC1_BTN2_RECT_XLEN, TFT_SC1_BTN2_RECT_YLEN,
                      TFT_SC1_BTN2_RECT_CLR, TFT_SC1_BTN2_RECT_THICK);
  tft.setFont(&TFT_SC1_BTN2_TXT_FONT);
  tft.setTextSize(TFT_SC1_BTN2_TXT_SIZE);
  tft.setTextColor(TFT_SC1_BTN2_TXT_CLR);
  tft.setCursor(TFT_SC1_BTN2_TXT_X, TFT_SC1_BTN2_TXT_Y);
  tft.println(TFT_SC1_BTN2_TXT);
}

void tft_draw_sc2(void)
{
  SCREEN_TEXT_Params textParams;
  
  // Erase previous screen
  tft.fillScreen(ILI9341_BLACK);

  // Draw border of screen white
  tft_draw_border(ILI9341_WHITE);

  // title
  tft_screen_text_params_init(&textParams);
  textParams.x       = TFT_SC2_TITLE_TXT_X;
  textParams.y       = TFT_SC2_TITLE_TXT_Y;
  textParams.text    = TFT_SC2_TITLE_TXT;
  textParams.color   = TFT_SC2_TITLE_TXT_CLR;
  textParams.font    = &TFT_SC2_TITLE_TXT_FONT;
  tft_draw_text(textParams);

  // Text 1
  tft_screen_text_params_init(&textParams);
  textParams.x       = TFT_SC2_TXT1_TXT_X;
  textParams.y       = TFT_SC2_TXT1_TXT_Y;
  textParams.text    = TFT_SC2_TXT1_TXT;
  textParams.color   = TFT_SC2_TXT1_TXT_CLR;
  textParams.font    = &TFT_SC2_TXT1_TXT_FONT;
  tft_draw_text(textParams);

  tft.drawFastHLine(2, 78, 316, ILI9341_WHITE);

  // Text 2
  tft_screen_text_params_init(&textParams);
  textParams.x       = TFT_SC2_TXT2_TXT_X;
  textParams.y       = TFT_SC2_TXT2_TXT_Y;
  textParams.text    = TFT_SC2_TXT2_TXT;
  textParams.color   = TFT_SC2_TXT2_TXT_CLR;
  textParams.font    = &TFT_SC2_TXT2_TXT_FONT;
  tft_draw_text(textParams);

  // button 1
  tft_draw_thick_rect(TFT_SC2_BTN1_RECT_X, TFT_SC2_BTN1_RECT_Y,
                      TFT_SC2_BTN1_RECT_XLEN, TFT_SC2_BTN1_RECT_YLEN,
                      TFT_SC2_BTN1_RECT_CLR, TFT_SC2_BTN1_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN1_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN1_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN1_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN1_TXT_X, TFT_SC2_BTN1_TXT_Y);
  tft.println(TFT_SC2_BTN1_TXT);

  // button 2
  tft_draw_thick_rect(TFT_SC2_BTN2_RECT_X, TFT_SC2_BTN2_RECT_Y,
                      TFT_SC2_BTN2_RECT_XLEN, TFT_SC2_BTN2_RECT_YLEN,
                      TFT_SC2_BTN2_RECT_CLR, TFT_SC2_BTN2_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN2_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN2_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN2_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN2_TXT_X, TFT_SC2_BTN2_TXT_Y);
  tft.println(TFT_SC2_BTN2_TXT);

  // button 3
  tft_draw_thick_rect(TFT_SC2_BTN3_RECT_X, TFT_SC2_BTN3_RECT_Y,
                      TFT_SC2_BTN3_RECT_XLEN, TFT_SC2_BTN3_RECT_YLEN,
                      TFT_SC2_BTN3_RECT_CLR, TFT_SC2_BTN3_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN3_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN3_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN3_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN3_TXT_X, TFT_SC2_BTN3_TXT_Y);
  tft.println(TFT_SC2_BTN3_TXT);

  // button 4
  tft_draw_thick_rect(TFT_SC2_BTN4_RECT_X, TFT_SC2_BTN4_RECT_Y,
                      TFT_SC2_BTN4_RECT_XLEN, TFT_SC2_BTN4_RECT_YLEN,
                      TFT_SC2_BTN4_RECT_CLR, TFT_SC2_BTN4_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN4_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN4_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN4_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN4_TXT_X, TFT_SC2_BTN4_TXT_Y);
  tft.println(TFT_SC2_BTN4_TXT);

  // button 5
  tft_draw_thick_rect(TFT_SC2_BTN5_RECT_X, TFT_SC2_BTN5_RECT_Y,
                      TFT_SC2_BTN5_RECT_XLEN, TFT_SC2_BTN5_RECT_YLEN,
                      TFT_SC2_BTN5_RECT_CLR, TFT_SC2_BTN5_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN5_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN5_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN5_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN5_TXT_X, TFT_SC2_BTN5_TXT_Y);
  tft.println(TFT_SC2_BTN5_TXT);

  // button 6
  tft_draw_thick_rect(TFT_SC2_BTN6_RECT_X, TFT_SC2_BTN6_RECT_Y,
                      TFT_SC2_BTN6_RECT_XLEN, TFT_SC2_BTN6_RECT_YLEN,
                      TFT_SC2_BTN6_RECT_CLR, TFT_SC2_BTN6_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN6_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN6_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN6_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN6_TXT_X, TFT_SC2_BTN6_TXT_Y);
  tft.println(TFT_SC2_BTN6_TXT);

  // button 7
  tft_draw_thick_rect(TFT_SC2_BTN7_RECT_X, TFT_SC2_BTN7_RECT_Y,
                      TFT_SC2_BTN7_RECT_XLEN, TFT_SC2_BTN7_RECT_YLEN,
                      TFT_SC2_BTN7_RECT_CLR, TFT_SC2_BTN7_RECT_THICK);
  tft.setFont(&TFT_SC2_BTN7_TXT_FONT);
  tft.setTextSize(TFT_SC2_BTN7_TXT_SIZE);
  tft.setTextColor(TFT_SC2_BTN7_TXT_CLR);
  tft.setCursor(TFT_SC2_BTN7_TXT_X, TFT_SC2_BTN7_TXT_Y);
  tft.println(TFT_SC2_BTN7_TXT);
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

/*!
 *  @brief    Initialize the SCREEN_TEXT_Params to its defaults.
 *  @param    params  Pointer to a parameter block..
 */
void tft_screen_text_params_init(SCREEN_TEXT_Params *params)
{
  params->x      = 0;
  params->y      = 0;
  params->text   = "";
  params->color  = ILI9341_WHITE;
  params->font   = NULL;
  params->size   = 1;
}

/*!
 *  @brief    Draw text on the screen.
 *  @param    params  Parameter structure.
 */
void tft_draw_text(SCREEN_TEXT_Params params)
{
  tft.setFont(params.font);
  tft.setTextSize(params.size);
  tft.setTextColor(params.color);
  tft.setCursor(params.x, params.y);
  tft.println(params.text);
}
