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
  textParams.text_x       = TFT_SC1_TITLE_TXT_X;
  textParams.text_y       = TFT_SC1_TITLE_TXT_Y;
  textParams.text         = TFT_SC1_TITLE_TXT;
  textParams.text_color   = TFT_SC1_TITLE_TXT_CLR;
  textParams.text_font    = &TFT_SC1_TITLE_TXT_FONT;
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
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC1_BTN1_TXT_X;
  textParams.text_y           = TFT_SC1_BTN1_TXT_Y;
  textParams.text             = TFT_SC1_BTN1_TXT;
  textParams.text_font        = &TFT_SC1_BTN1_TXT_FONT;

  textParams.rect_x           = TFT_SC1_BTN1_RECT_X;
  textParams.rect_y           = TFT_SC1_BTN1_RECT_Y;
  textParams.rect_x_len       = TFT_SC1_BTN1_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC1_BTN1_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC1_BTN1_RECT_THICK;

  textParams.text_color       = TFT_SC1_BTN1_TXT_CLR;
  textParams.rect_color       = TFT_SC1_BTN1_RECT_CLR;
  tft_draw_text(textParams);

  // button 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC1_BTN2_TXT_X;
  textParams.text_y           = TFT_SC1_BTN2_TXT_Y;
  textParams.text             = TFT_SC1_BTN2_TXT;
  textParams.text_font        = &TFT_SC1_BTN2_TXT_FONT;

  textParams.rect_x           = TFT_SC1_BTN2_RECT_X;
  textParams.rect_y           = TFT_SC1_BTN2_RECT_Y;
  textParams.rect_x_len       = TFT_SC1_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC1_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC1_BTN2_RECT_THICK;

  textParams.text_color       = TFT_SC1_BTN2_TXT_CLR;
  textParams.rect_color       = TFT_SC1_BTN2_RECT_CLR;
  tft_draw_text(textParams);
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
  textParams.text_x       = TFT_SC2_TITLE_TXT_X;
  textParams.text_y       = TFT_SC2_TITLE_TXT_Y;
  textParams.text         = TFT_SC2_TITLE_TXT;
  textParams.text_color   = TFT_SC2_TITLE_TXT_CLR;
  textParams.text_font    = &TFT_SC2_TITLE_TXT_FONT;
  tft_draw_text(textParams);

  // Text 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC2_TXT1_TXT_X;
  textParams.text_y       = TFT_SC2_TXT1_TXT_Y;
  textParams.text         = TFT_SC2_TXT1_TXT;
  textParams.text_color   = TFT_SC2_TXT1_TXT_CLR;
  textParams.text_font    = &TFT_SC2_TXT1_TXT_FONT;
  tft_draw_text(textParams);

  tft.drawFastHLine(2, 78, 316, ILI9341_WHITE);

  // Text 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC2_TXT2_TXT_X;
  textParams.text_y       = TFT_SC2_TXT2_TXT_Y;
  textParams.text         = TFT_SC2_TXT2_TXT;
  textParams.text_color   = TFT_SC2_TXT2_TXT_CLR;
  textParams.text_font    = &TFT_SC2_TXT2_TXT_FONT;
  tft_draw_text(textParams);

  // button 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN1_TXT_X;
  textParams.text_y           = TFT_SC2_BTN1_TXT_Y;
  textParams.text             = TFT_SC2_BTN1_TXT;
  textParams.text_font        = &TFT_SC2_BTN1_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN1_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN1_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN1_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN1_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN1_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN1_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN1_RECT_CLR;
  tft_draw_text(textParams);

  // button 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN2_TXT_X;
  textParams.text_y           = TFT_SC2_BTN2_TXT_Y;
  textParams.text             = TFT_SC2_BTN2_TXT;
  textParams.text_font        = &TFT_SC2_BTN2_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN2_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN2_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN2_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN2_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN2_RECT_CLR;
  tft_draw_text(textParams);

  // button 3
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN3_TXT_X;
  textParams.text_y           = TFT_SC2_BTN3_TXT_Y;
  textParams.text             = TFT_SC2_BTN3_TXT;
  textParams.text_font        = &TFT_SC2_BTN3_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN3_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN3_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN3_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN3_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN3_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN3_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN3_RECT_CLR;
  tft_draw_text(textParams);

  // button 4
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN4_TXT_X;
  textParams.text_y           = TFT_SC2_BTN4_TXT_Y;
  textParams.text             = TFT_SC2_BTN4_TXT;
  textParams.text_font        = &TFT_SC2_BTN4_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN4_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN4_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN4_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN4_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN4_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN4_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN4_RECT_CLR;
  tft_draw_text(textParams);

  // button 5
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN5_TXT_X;
  textParams.text_y           = TFT_SC2_BTN5_TXT_Y;
  textParams.text             = TFT_SC2_BTN5_TXT;
  textParams.text_font        = &TFT_SC2_BTN5_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN5_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN5_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN5_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN5_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN5_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN5_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN5_RECT_CLR;
  tft_draw_text(textParams);

  // button 6
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN6_TXT_X;
  textParams.text_y           = TFT_SC2_BTN6_TXT_Y;
  textParams.text             = TFT_SC2_BTN6_TXT;
  textParams.text_font        = &TFT_SC2_BTN6_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN6_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN6_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN6_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN6_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN6_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN6_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN6_RECT_CLR;
  tft_draw_text(textParams);

  // button 7
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC2_BTN7_TXT_X;
  textParams.text_y           = TFT_SC2_BTN7_TXT_Y;
  textParams.text             = TFT_SC2_BTN7_TXT;
  textParams.text_font        = &TFT_SC2_BTN7_TXT_FONT;

  textParams.rect_x           = TFT_SC2_BTN7_RECT_X;
  textParams.rect_y           = TFT_SC2_BTN7_RECT_Y;
  textParams.rect_x_len       = TFT_SC2_BTN7_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC2_BTN7_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC2_BTN7_RECT_THICK;

  textParams.text_color       = TFT_SC2_BTN7_TXT_CLR;
  textParams.rect_color       = TFT_SC2_BTN7_RECT_CLR;
  tft_draw_text(textParams);
}

/*!
    @brief    Draw screen 3
*/
void tft_draw_sc3(void)
{
  SCREEN_TEXT_Params textParams;

  // Erase previous screen
  tft.fillScreen(ILI9341_BLACK);

  // Draw border of screen white
  tft_draw_border(ILI9341_WHITE);

  // Text 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC3_TXT1_TXT_X;
  textParams.text_y       = TFT_SC3_TXT1_TXT_Y;
  textParams.text         = TFT_SC3_TXT1_TXT;
  textParams.text_color   = TFT_SC3_TXT1_TXT_CLR;
  textParams.text_font    = &TFT_SC3_TXT1_TXT_FONT;
  tft_draw_text(textParams);

  // Text 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC3_TXT2_TXT_X;
  textParams.text_y       = TFT_SC3_TXT2_TXT_Y;
  textParams.text         = TFT_SC3_TXT2_TXT;
  textParams.text_color   = TFT_SC3_TXT2_TXT_CLR;
  textParams.text_font    = &TFT_SC3_TXT2_TXT_FONT;
  tft_draw_text(textParams);

  // button 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC3_BTN1_TXT_X;
  textParams.text_y           = TFT_SC3_BTN1_TXT_Y;
  textParams.text             = TFT_SC3_BTN1_TXT;
  textParams.text_font        = &TFT_SC3_BTN1_TXT_FONT;

  textParams.rect_x           = TFT_SC3_BTN1_RECT_X;
  textParams.rect_y           = TFT_SC3_BTN1_RECT_Y;
  textParams.rect_x_len       = TFT_SC3_BTN1_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC3_BTN1_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC3_BTN1_RECT_THICK;

  textParams.text_color       = TFT_SC3_BTN1_TXT_CLR;
  textParams.rect_color       = TFT_SC3_BTN1_RECT_CLR;
  tft_draw_text(textParams);;

  // button 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC3_BTN2_TXT_X;
  textParams.text_y           = TFT_SC3_BTN2_TXT_Y;
  textParams.text             = TFT_SC3_BTN2_TXT;
  textParams.text_font        = &TFT_SC3_BTN2_TXT_FONT;

  textParams.rect_x           = TFT_SC3_BTN2_RECT_X;
  textParams.rect_y           = TFT_SC3_BTN2_RECT_Y;
  textParams.rect_x_len       = TFT_SC3_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC3_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC3_BTN2_RECT_THICK;

  textParams.text_color       = TFT_SC3_BTN2_TXT_CLR;
  textParams.rect_color       = TFT_SC3_BTN2_RECT_CLR;
  tft_draw_text(textParams);

  // button 3
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC3_BTN3_TXT_X;
  textParams.text_y           = TFT_SC3_BTN3_TXT_Y;
  textParams.text             = TFT_SC3_BTN3_TXT;
  textParams.text_font        = &TFT_SC3_BTN3_TXT_FONT;

  textParams.rect_x           = TFT_SC3_BTN3_RECT_X;
  textParams.rect_y           = TFT_SC3_BTN3_RECT_Y;
  textParams.rect_x_len       = TFT_SC3_BTN3_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC3_BTN3_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC3_BTN3_RECT_THICK;

  textParams.text_color       = TFT_SC3_BTN3_TXT_CLR;
  textParams.rect_color       = TFT_SC3_BTN3_RECT_CLR;
  tft_draw_text(textParams);

  // button 4
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC3_BTN4_TXT_X;
  textParams.text_y           = TFT_SC3_BTN4_TXT_Y;
  textParams.text             = TFT_SC3_BTN4_TXT;
  textParams.text_font        = &TFT_SC3_BTN4_TXT_FONT;

  textParams.rect_x           = TFT_SC3_BTN4_RECT_X;
  textParams.rect_y           = TFT_SC3_BTN4_RECT_Y;
  textParams.rect_x_len       = TFT_SC3_BTN4_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC3_BTN4_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC3_BTN4_RECT_THICK;

  textParams.text_color       = TFT_SC3_BTN4_TXT_CLR;
  textParams.rect_color       = TFT_SC3_BTN4_RECT_CLR;
  tft_draw_text(textParams);

  // button 5
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC3_BTN5_TXT_X;
  textParams.text_y           = TFT_SC3_BTN5_TXT_Y;
  textParams.text             = TFT_SC3_BTN5_TXT;
  textParams.text_font        = &TFT_SC3_BTN5_TXT_FONT;

  textParams.rect_x           = TFT_SC3_BTN5_RECT_X;
  textParams.rect_y           = TFT_SC3_BTN5_RECT_Y;
  textParams.rect_x_len       = TFT_SC3_BTN5_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC3_BTN5_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC3_BTN5_RECT_THICK;

  textParams.text_color       = TFT_SC3_BTN5_TXT_CLR;
  textParams.rect_color       = TFT_SC3_BTN5_RECT_CLR;
  tft_draw_text(textParams);

  // up down buttons
  tft.fillTriangle(85, 78, 75, 93, 95, 93, ILI9341_WHITE);
  tft.fillTriangle(85, 164, 75, 149, 95, 149, ILI9341_WHITE);
  tft.fillTriangle(155, 78, 145, 93, 165, 93, ILI9341_WHITE);
  tft.fillTriangle(155, 164, 145, 149, 165, 149, ILI9341_WHITE);
}

/*!
    @brief    Draw screen 4
*/
void tft_draw_sc4(void)
{
  SCREEN_TEXT_Params textParams;

  // Erase previous screen
  tft.fillScreen(ILI9341_BLACK);

  // Draw border of screen white
  tft_draw_border(ILI9341_WHITE);

  // title
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC4_TITLE_TXT_X;
  textParams.text_y       = TFT_SC4_TITLE_TXT_Y;
  textParams.text         = TFT_SC4_TITLE_TXT;
  textParams.text_color   = TFT_SC4_TITLE_TXT_CLR;
  textParams.text_font    = &TFT_SC4_TITLE_TXT_FONT;
  tft_draw_text(textParams);

  // Text 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC4_TXT1_TXT_X;
  textParams.text_y       = TFT_SC4_TXT1_TXT_Y;
  textParams.text         = TFT_SC4_TXT1_TXT;
  textParams.text_color   = TFT_SC4_TXT1_TXT_CLR;
  textParams.text_font    = &TFT_SC4_TXT1_TXT_FONT;
  tft_draw_text(textParams);

  // Text 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x       = TFT_SC4_TXT2_TXT_X;
  textParams.text_y       = TFT_SC4_TXT2_TXT_Y;
  textParams.text         = TFT_SC4_TXT2_TXT;
  textParams.text_color   = TFT_SC4_TXT2_TXT_CLR;
  textParams.text_font    = &TFT_SC4_TXT2_TXT_FONT;
  tft_draw_text(textParams);

  // button 1
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC4_BTN1_TXT_X;
  textParams.text_y           = TFT_SC4_BTN1_TXT_Y;
  textParams.text             = TFT_SC4_BTN1_TXT;
  textParams.text_font        = &TFT_SC4_BTN1_TXT_FONT;

  textParams.rect_x           = TFT_SC4_BTN1_RECT_X;
  textParams.rect_y           = TFT_SC4_BTN1_RECT_Y;
  textParams.rect_x_len       = TFT_SC4_BTN1_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC4_BTN1_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC4_BTN1_RECT_THICK;

  textParams.text_color       = TFT_SC4_BTN1_TXT_CLR;
  textParams.rect_color       = TFT_SC4_BTN1_RECT_CLR;
  tft_draw_text(textParams);;

  // button 2
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC4_BTN2_TXT_X;
  textParams.text_y           = TFT_SC4_BTN2_TXT_Y;
  textParams.text             = TFT_SC4_BTN2_TXT;
  textParams.text_font        = &TFT_SC4_BTN2_TXT_FONT;

  textParams.rect_x           = TFT_SC4_BTN2_RECT_X;
  textParams.rect_y           = TFT_SC4_BTN2_RECT_Y;
  textParams.rect_x_len       = TFT_SC4_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC4_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC4_BTN2_RECT_THICK;

  textParams.text_color       = TFT_SC4_BTN2_TXT_CLR;
  textParams.rect_color       = TFT_SC4_BTN2_RECT_CLR;
  tft_draw_text(textParams);

  // button 4
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC4_BTN4_TXT_X;
  textParams.text_y           = TFT_SC4_BTN4_TXT_Y;
  textParams.text             = TFT_SC4_BTN4_TXT;
  textParams.text_font        = &TFT_SC4_BTN4_TXT_FONT;

  textParams.rect_x           = TFT_SC4_BTN4_RECT_X;
  textParams.rect_y           = TFT_SC4_BTN4_RECT_Y;
  textParams.rect_x_len       = TFT_SC4_BTN4_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC4_BTN4_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC4_BTN4_RECT_THICK;

  textParams.text_color       = TFT_SC4_BTN4_TXT_CLR;
  textParams.rect_color       = TFT_SC4_BTN4_RECT_CLR;
  tft_draw_text(textParams);

  // button 5
  tft_screen_text_params_init(&textParams);
  textParams.text_x           = TFT_SC4_BTN5_TXT_X;
  textParams.text_y           = TFT_SC4_BTN5_TXT_Y;
  textParams.text             = TFT_SC4_BTN5_TXT;
  textParams.text_font        = &TFT_SC4_BTN5_TXT_FONT;

  textParams.rect_x           = TFT_SC4_BTN5_RECT_X;
  textParams.rect_y           = TFT_SC4_BTN5_RECT_Y;
  textParams.rect_x_len       = TFT_SC4_BTN5_RECT_XLEN;
  textParams.rect_y_len       = TFT_SC4_BTN5_RECT_YLEN;
  textParams.rect_thickness   = TFT_SC4_BTN5_RECT_THICK;

  textParams.text_color       = TFT_SC4_BTN5_TXT_CLR;
  textParams.rect_color       = TFT_SC4_BTN5_RECT_CLR;
  tft_draw_text(textParams);

  // up down buttons
  tft.fillTriangle(45, 78, 35, 93, 55, 93, ILI9341_WHITE);
  tft.fillTriangle(45, 164, 35, 149, 55, 149, ILI9341_WHITE);
  tft.fillTriangle(115, 78, 105, 93, 125, 93, ILI9341_WHITE);
  tft.fillTriangle(115, 164, 105, 149, 125, 149, ILI9341_WHITE);

}

/*!
    @brief    Draw screen keyboard
*/
void tft_draw_sckey(void)
{
  SCREEN_TEXT_Params textParams;

  // Erase previous screen
  tft.fillScreen(ILI9341_BLACK);

  // Draw border of screen white
  tft_draw_border(ILI9341_WHITE);

  for (int row = 0; row < TFT_SCKEY_BTN_ROWS; row++)
  {
    for (int col = 0; col < TFT_SCKEY_BTN_COLUMNS; col++)
    {
      tft_screen_text_params_init(&textParams);

      textParams.rect_x           = TFT_SCKEY_BTN_RECT_X + (col * TFT_SCKEY_BTN_GAP_X);
      textParams.rect_y           = TFT_SCKEY_BTN_RECT_Y + (row * TFT_SCKEY_BTN_GAP_Y);
      textParams.rect_x_len       = TFT_SCKEY_BTN1_RECT_XLEN;
      textParams.rect_y_len       = TFT_SCKEY_BTN1_RECT_YLEN;
      textParams.rect_thickness   = TFT_SCKEY_BTN_RECT_THICK;
      textParams.fill_en          = TFT_SCKEY_BTN_FILL_EN;
      textParams.round_en         = TFT_SCKEY_BTN_ROUND_EN;

      textParams.fill_color       = TFT_SCKEY_BTN_FILL_CLR;
      textParams.rect_color       = TFT_SCKEY_BTN_RECT_CLR;

      tft_draw_text(textParams);
    }
  }

  // Button 5 Space bar
  tft_screen_text_params_init(&textParams);

  textParams.text_x           = TFT_SCKEY_BTN5_TXT_X;
  textParams.text_y           = TFT_SCKEY_BTN5_TXT_Y;
  textParams.text             = TFT_SCKEY_BTN5_TXT;
  textParams.text_font        = &TFT_SCKEY_BTN_TXT_FONT;

  textParams.rect_x           = TFT_SCKEY_BTN_RECT_X + (1 * TFT_SCKEY_BTN_GAP_X);
  textParams.rect_y           = TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y);
  textParams.rect_x_len       = TFT_SCKEY_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SCKEY_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SCKEY_BTN_RECT_THICK;
  
  textParams.fill_en          = TFT_SCKEY_BTN_FILL_EN;
  textParams.round_en         = TFT_SCKEY_BTN_ROUND_EN;

  textParams.fill_color       = TFT_SCKEY_BTN_FILL_CLR;
  textParams.rect_color       = TFT_SCKEY_BTN_RECT_CLR;
  textParams.text_color       = TFT_SCKEY_BTN_TXT_CLR;

  tft_draw_text(textParams);

  // Button 6 Clear
  tft_screen_text_params_init(&textParams);

  textParams.text_x           = TFT_SCKEY_BTN6_TXT_X;
  textParams.text_y           = TFT_SCKEY_BTN6_TXT_Y;
  textParams.text             = TFT_SCKEY_BTN6_TXT;
  textParams.text_font        = &TFT_SCKEY_BTN_TXT_FONT;

  textParams.rect_x           = TFT_SCKEY_BTN_RECT_X + (3 * TFT_SCKEY_BTN_GAP_X);
  textParams.rect_y           = TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y);
  textParams.rect_x_len       = TFT_SCKEY_BTN2_RECT_XLEN;
  textParams.rect_y_len       = TFT_SCKEY_BTN2_RECT_YLEN;
  textParams.rect_thickness   = TFT_SCKEY_BTN_RECT_THICK;
  
  textParams.fill_en          = TFT_SCKEY_BTN_FILL_EN;
  textParams.round_en         = TFT_SCKEY_BTN_ROUND_EN;

  textParams.fill_color       = TFT_SCKEY_BTN_FILL_CLR;
  textParams.rect_color       = TFT_SCKEY_BTN_RECT_CLR;
  textParams.text_color       = TFT_SCKEY_BTN_TXT_CLR;

  tft_draw_text(textParams);

  // Button 7 OK
  tft_screen_text_params_init(&textParams);

  textParams.text_x           = TFT_SCKEY_BTN7_TXT_X;
  textParams.text_y           = TFT_SCKEY_BTN7_TXT_Y;
  textParams.text             = TFT_SCKEY_BTN7_TXT;
  textParams.text_font        = &TFT_SCKEY_BTN7_TXT_FONT;

  textParams.rect_x           = TFT_SCKEY_BTN7_RECT_X;
  textParams.rect_y           = TFT_SCKEY_BTN7_RECT_Y;
  textParams.rect_x_len       = TFT_SCKEY_BTN7_RECT_XLEN;
  textParams.rect_y_len       = TFT_SCKEY_BTN7_RECT_YLEN;
  textParams.rect_thickness   = TFT_SCKEY_BTN7_RECT_THICK;

  textParams.round_en         = TFT_SCKEY_BTN7_ROUND_EN;
  textParams.fill_en          = TFT_SCKEY_BTN7_FILL_EN;

  textParams.fill_color       = TFT_SCKEY_BTN7_FILL_CLR;
  textParams.rect_color       = TFT_SCKEY_BTN7_RECT_CLR;
  textParams.text_color       = TFT_SCKEY_BTN7_TXT_CLR;

  tft_draw_text(textParams);

  // Text 1 Input textbox
  tft_screen_text_params_init(&textParams);

  textParams.text_x           = TFT_SCKEY_TXT1_TXT_X;
  textParams.text_y           = TFT_SCKEY_TXT1_TXT_Y;
  textParams.text             = TFT_SCKEY_TXT1_TXT;
  textParams.text_font        = &TFT_SCKEY_TXT1_TXT_FONT;

  textParams.rect_x           = TFT_SCKEY_TXT1_RECT_X;
  textParams.rect_y           = TFT_SCKEY_TXT1_RECT_Y;
  textParams.rect_x_len       = TFT_SCKEY_TXT1_RECT_XLEN;
  textParams.rect_y_len       = TFT_SCKEY_TXT1_RECT_YLEN;
  textParams.rect_thickness   = TFT_SCKEY_TXT1_RECT_THICK;
  
  textParams.fill_en          = TFT_SCKEY_TXT1_FILL_EN;

  textParams.fill_color       = TFT_SCKEY_TXT1_FILL_CLR;
  textParams.rect_color       = TFT_SCKEY_TXT1_RECT_CLR;
  textParams.text_color       = TFT_SCKEY_TXT1_TXT_CLR;

  tft_draw_text(textParams);

  // Bottom row buttons
  tft_draw_arrow_button(TFT_SCKEY_BTN3_ARROW_X, TFT_SCKEY_BTN3_ARROW_Y, TFT_SCKEY_BTN3_ARROW_CLR, TFT_SCKEY_BTN3_ARROW_DIR);
  tft_draw_arrow_button(TFT_SCKEY_BTN4_ARROW_X, TFT_SCKEY_BTN4_ARROW_Y, TFT_SCKEY_BTN4_ARROW_CLR, TFT_SCKEY_BTN4_ARROW_DIR);
}
