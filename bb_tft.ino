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
    @brief    Initialize the SCREEN_TEXT_Params to its defaults.
    @param    params  Pointer to a parameter block..
*/
void tft_screen_text_params_init(SCREEN_TEXT_Params *params)
{
  params->text_x            = 0;
  params->text_y            = 0;
  params->text              = "";
  params->text_font         = NULL;
  params->text_size         = 1;

  params->rect_thickness    = 0;
  params->rect_x            = 0;
  params->rect_y            = 0;
  params->rect_x_len        = 0;
  params->rect_y_len        = 0;

  params->fill_en           = false;

  params->text_color        = ILI9341_WHITE;
  params->rect_color        = ILI9341_WHITE;
  params->fill_color        = ILI9341_BLACK;
}

/*!
    @brief    Draw text on the screen.
    @param    params  Parameter structure.
*/
void tft_draw_text(SCREEN_TEXT_Params params)
{
  if (params.fill_en == true)
  {
    tft.fillRect(params.rect_x, params.rect_y, params.rect_x_len, params.rect_y_len, params.fill_color);
  }

  // Draw box
  tft_draw_thick_rect(params.rect_x, params.rect_y, params.rect_x_len, params.rect_y_len, params.rect_color, params.rect_thickness);

  tft.setFont(params.text_font);
  tft.setTextSize(params.text_size);
  tft.setTextColor(params.text_color);
  tft.setCursor(params.text_x, params.text_y);
  tft.println(params.text);
}
