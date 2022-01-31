char* sc1_get_selected_case_name(int8_t id)
{
  // 1 byte id, 1 byte sec, 1 byte msec, 20 byte name
  static char casename[20] = {0};

  // Search id of all 20 cases
  for (int i = 0; i < 20; i++)
  {
    if (EEPROM[i * 23] == id)
    {
      for (int j = 0; j < 20; j++)
      {
        // Copy 20 characters of casename to variable
        casename[j] = EEPROM[i * 23 + 3 + j];
      }
      break;
    }
  }
  return casename;
}

uint8_t sc1_get_selected_case_time_sec(void)
{
  // 1 byte id, 1 byte sec, 1 byte msec, 20 byte name
  uint8_t id = SC1_STATE.selected_id;
  uint8_t sec = 0;

  // Search for id
  for (int i = 0; i < 20; i++)
  {
    if (EEPROM[i * 23] == id)
    {
      sec = EEPROM[i * 23 + 1];
      break;
    }
  }
  return sec;
}

uint8_t sc1_get_selected_case_time_msec(void)
{
  // 1 byte id, 1 byte sec, 1 byte msec, 20 byte name
  uint8_t id = SC1_STATE.selected_id;
  uint8_t msec = 0;

  // Search for id
  for (int i = 0; i < 20; i++)
  {
    if (EEPROM[i * 23] == id)
    {
      msec = EEPROM[i * 23 + 1];
      break;
    }
  }
  return msec;
}

void sc1_draw_list(void)
{
  char *casename;

  // Erase table
  tft.fillRect(10, 40, 260, 145, ILI9341_BLACK);

  // Draw table
  tft.drawRect(10, 40, 260, 145, ILI9341_WHITE);
  tft.drawFastHLine(10, 88, 260, ILI9341_WHITE);
  tft.drawFastHLine(10, 136, 260, ILI9341_WHITE);

  // Draw text
  tft.setFont(&TFT_SC1_TXT1_TXT_FONT);
  tft.setTextSize(1);
  tft.setTextColor(TFT_SC1_TXT1_TXT_CLR);

  // Selected case
  casename = sc1_get_selected_case_name(SC1_STATE.selected_id);
  tft.setCursor(TFT_SC1_TXT1_TXT_X, TFT_SC1_TXT1_TXT_Y);
  tft.println(casename);

  if (SC1_STATE.selected_id > 0)
  {
    // Top case
    casename = sc1_get_selected_case_name(SC1_STATE.selected_id - 1);
    tft.setCursor(TFT_SC1_TXT2_TXT_X, TFT_SC1_TXT2_TXT_Y);
    tft.println(casename);
  }

  if (SC1_STATE.selected_id < SC1_STATE.max_cases - 1)
  {
    // Bottom case
    casename = sc1_get_selected_case_name(SC1_STATE.selected_id + 1);
    tft.setCursor(TFT_SC1_TXT3_TXT_X, TFT_SC1_TXT3_TXT_Y);
    tft.println(casename);
  }
}

void sc2_draw_time(void)
{
  int16_t  x1, y1;
  uint16_t w, h;

  // erase previous time
  tft.getTextBounds(TFT_SC2_TXT1_TXT, TFT_SC2_TXT1_TXT_X, TFT_SC2_TXT1_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);

  // draw new time
  tft.setFont(&TFT_SC2_TXT1_TXT_FONT);
  tft.setTextSize(1);
  tft.setTextColor(TFT_SC2_TXT1_TXT_CLR);
  tft.setCursor(TFT_SC2_TXT1_TXT_X, TFT_SC2_TXT1_TXT_Y);
  tft.print("Time: ");
  tft.print(MACHINE_STATE.case_time_sec);
  tft.print(".");
  tft.print(MACHINE_STATE.case_time_msec);
  tft.print(" sec");
}

void sc2_draw_count(void)
{
  int16_t  x1, y1;
  uint16_t w, h;

  // erase previous count
  tft.getTextBounds(TFT_SC2_TXT2_TXT, TFT_SC2_TXT2_TXT_X, TFT_SC2_TXT2_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);

  // draw new count
  tft.setFont(&TFT_SC2_TXT2_TXT_FONT);
  tft.setTextSize(1);
  tft.setTextColor(TFT_SC2_TXT2_TXT_CLR);
  tft.setCursor(TFT_SC2_TXT2_TXT_X, TFT_SC2_TXT2_TXT_Y);
  tft.print("Count: ");
  tft.println(SC2_STATE.count);
}

void sc3_add_case(void)
{
  // Search for empty locaition
  for (int i = 0; i < 20; i++)
  {
    if (EEPROM[i * 23] == 0xff)
    {
      // Write case ID
      EEPROM[i * 23] = SC1_STATE.max_cases;
      SC1_STATE.max_cases += 1;
      EEPROM[SC1_MAX_CASES_ADDR] = SC1_STATE.max_cases;

      // Write sec, msec
      EEPROM[i * 23 + 1] = SC3_STATE.sec;
      EEPROM[i * 23 + 2] = SC3_STATE.msec;

      // Write case name
      for (int i = 0; i < 14; i++)
      {
        EEPROM[i * 23 + 3 + i] = SC3_STATE.casename[i];
      }
      EEPROM[i * 23 + 3 + 14] = 0;
      break;
    }
  }
}

void sc3_run_test(void)
{

}

void sc3_update_time(void)
{
  int16_t  x1, y1;
  uint16_t w, h;

  // erase sec msec times
  tft.getTextBounds("00", TFT_SC3_TXT1_TXT_X, TFT_SC3_TXT1_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);
  tft.getTextBounds("0", TFT_SC3_TXT2_TXT_X, TFT_SC3_TXT2_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);

  // draw sec, msec time
  tft.setFont(&TFT_SC3_TXT1_TXT_FONT);
  tft.setTextSize(1);

  tft.setTextColor(TFT_SC3_TXT1_TXT_CLR);
  tft.setCursor(TFT_SC3_TXT1_TXT_X, TFT_SC3_TXT1_TXT_Y);
  tft.println(SC3_STATE.sec);

  tft.setTextColor(TFT_SC3_TXT2_TXT_CLR);
  tft.setCursor(TFT_SC3_TXT2_TXT_X, TFT_SC3_TXT2_TXT_Y);
  tft.println(SC3_STATE.msec);
}

void sc4_pause_annealing(void)
{
  tft.setFont(&TFT_SC4_BTN2_TXT_FONT);
  tft.setTextSize(1);

  if (MACHINE_STATE.ann_state = 2)
  {
    // write pause in bg color
    tft.setTextColor(TFT_SC4_BTN2_FILL_CLR);
    tft.setCursor(TFT_SC4_BTN2_TXT_X, TFT_SC4_BTN2_TXT_Y);
    tft.println(TFT_SC4_BTN2_TXT);

    // write start in main color
    tft.setTextColor(TFT_SC4_BTN2_TXT_CLR);
    tft.setCursor(TFT_SC4_BTN2_TXT_X, TFT_SC4_BTN2_TXT_Y);
    tft.println("START");

    // pause annealing
    MACHINE_STATE.ann_state = 2;
  }
  else
  {
    // write start in bg color
    tft.setTextColor(TFT_SC4_BTN2_FILL_CLR);
    tft.setCursor(TFT_SC4_BTN2_TXT_X, TFT_SC4_BTN2_TXT_Y);
    tft.println("start");

    // write pause in main color
    tft.setTextColor(TFT_SC4_BTN2_TXT_CLR);
    tft.setCursor(TFT_SC4_BTN2_TXT_X, TFT_SC4_BTN2_TXT_Y);
    tft.println(TFT_SC4_BTN2_TXT);

    // Start annealing
    MACHINE_STATE.ann_state = 1;
  }
}

void sc4_update_case(void)
{
  if (SC4_STATE.save_enabled)
  {
    SC4_STATE.save_enabled = false;

    // update time of current case in EEPROM
    for (int i = 0; i < 20; i++)
    {
      if (MACHINE_STATE.case_id == EEPROM[i * 23])
      {
        EEPROM[i * 23 + 1] = SC4_STATE.sec;
        EEPROM[i * 23 + 2] = SC4_STATE.msec;
        break;
      }
    }
  }
}

void sc4_update_time(void)
{
  int16_t  x1, y1;
  uint16_t w, h;

  // erase sec msec times
  tft.getTextBounds("00", TFT_SC4_TXT1_TXT_X, TFT_SC4_TXT1_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);
  tft.getTextBounds("0", TFT_SC4_TXT2_TXT_X, TFT_SC4_TXT2_TXT_Y, &x1, &y1, &w, &h);
  tft.fillRect(x1, y1, w, h, ILI9341_BLACK);

  // draw sec, msec time
  tft.setFont(&TFT_SC4_BTN2_TXT_FONT);
  tft.setTextSize(1);

  tft.setTextColor(TFT_SC4_TXT1_TXT_CLR);
  tft.setCursor(TFT_SC4_TXT1_TXT_X, TFT_SC4_TXT1_TXT_Y);
  tft.println(SC4_STATE.sec);

  tft.setTextColor(TFT_SC4_TXT2_TXT_CLR);
  tft.setCursor(TFT_SC4_TXT2_TXT_X, TFT_SC4_TXT2_TXT_Y);
  tft.println(SC4_STATE.msec);

  // update global struct
  MACHINE_STATE.case_time_sec = SC4_STATE.sec;
  MACHINE_STATE.case_time_msec = SC4_STATE.msec;

  // enable save button
  SC4_STATE.save_enabled = true;
}

void sc4_draw_count(void)
{

}

void sc5_clear_textbox(void)
{
  strcpy(SC5_STATE.textbox, "");
  tft.fillRect(
    TFT_SCKEY_TXT1_RECT_X + 1,
    TFT_SCKEY_TXT1_RECT_Y + 1,
    TFT_SCKEY_TXT1_RECT_XLEN - 2,
    TFT_SCKEY_TXT1_RECT_YLEN - 2,
    TFT_SCKEY_TXT1_FILL_CLR);
}

void sc5_update_textbox(int row, int col)
{
  char key[2] = {0};

  if (row == 2)
  {
    if (col == 0)
    {
      // < pressed
      if (SC5_STATE.keyboard_page <= 0) SC5_STATE.keyboard_page = 2;
      else SC5_STATE.keyboard_page -= 1;
      sc5_draw_keys(SC5_STATE.keyboard_page);
    }
    else if (col == 5)
    {
      // > pressed
      if (SC5_STATE.keyboard_page >= 2) SC5_STATE.keyboard_page = 0;
      else SC5_STATE.keyboard_page += 1;
      sc5_draw_keys(SC5_STATE.keyboard_page);
    }
    return;
  }

  else if (row < 2)
  {
    key[0] = 'A' + (col + row * 6 + SC5_STATE.keyboard_page * 12);
    if (key[0] > 'Z')
    {
      key[0] = key[0] - 'Z' + '0' - 1;
    }
    strcat(SC5_STATE.textbox, key);

    tft.setFont(&TFT_SCKEY_TXT1_TXT_FONT);
    tft.setTextSize(1);
    tft.setTextColor(TFT_SCKEY_TXT1_TXT_CLR);
    tft.setCursor(TFT_SCKEY_TXT1_TXT_X, TFT_SCKEY_TXT1_TXT_Y);
    tft.println(SC5_STATE.textbox);
  }
}

void sc5_draw_keys(uint8_t keyboard_page)
{
  char key[2] = {0};
  SCREEN_TEXT_Params textParams;

  for (int row = 0; row < TFT_SCKEY_BTN_ROWS - 1; row++)
  {
    for (int col = 0; col < TFT_SCKEY_BTN_COLUMNS; col++)
    {
      tft_screen_text_params_init(&textParams);

      key[0] = 'A' + (col + row * 6 + keyboard_page * 12);
      if (key[0] > 'Z')
      {
        key[0] = key[0] - 'Z' + '0' - 1;
      }

      textParams.text_x           = TFT_SCKEY_BTN_RECT_X + (col * TFT_SCKEY_BTN_GAP_X) + TFT_SCKEY_BTN_TXT_X_OFFSET;
      textParams.text_y           = TFT_SCKEY_BTN_RECT_Y + (row * TFT_SCKEY_BTN_GAP_Y) + TFT_SCKEY_BTN_TXT_Y_OFFSET;
      textParams.text             = key;
      textParams.text_font        = &TFT_SCKEY_BTN_TXT_FONT;

      textParams.rect_x           = TFT_SCKEY_BTN_RECT_X + (col * TFT_SCKEY_BTN_GAP_X);
      textParams.rect_y           = TFT_SCKEY_BTN_RECT_Y + (row * TFT_SCKEY_BTN_GAP_Y);
      textParams.rect_x_len       = TFT_SCKEY_BTN1_RECT_XLEN;
      textParams.rect_y_len       = TFT_SCKEY_BTN1_RECT_YLEN;
      textParams.rect_thickness   = TFT_SCKEY_BTN_RECT_THICK;

      textParams.fill_en          = TFT_SCKEY_BTN_FILL_EN;
      textParams.round_en         = TFT_SCKEY_BTN_ROUND_EN;

      textParams.fill_color       = TFT_SCKEY_BTN_FILL_CLR;
      textParams.rect_color       = TFT_SCKEY_BTN_RECT_CLR;
      textParams.text_color       = TFT_SCKEY_BTN_TXT_CLR;

      tft_draw_text(textParams);
    }
  }
}


void sc8_delete_case(int8_t case_id)
{
  // 1 byte id, 1 byte sec, 1 byte msec, 20 byte name

  // Write 0xff as id for case_id
  for (int i = 0; i < 20; i++)
  {
    int8_t eeprom_id = EEPROM[i * 23];
    if (eeprom_id == case_id)
    {
      // Erase case ID
      EEPROM.update(i * 23, 0xff);
      SC1_STATE.max_cases -= 1;
      EEPROM[SC1_MAX_CASES_ADDR] = SC1_STATE.max_cases;
    }
    else if (eeprom_id > case_id && eeprom_id < 20)
    {
      EEPROM[i * 23] = eeprom_id - 1;
    }
  }
}

void sc8_stop_annealing(void)
{
  MACHINE_STATE.ann_state = 0;
}

void sc6_repeat_annealing(void)
{
  // !Set count back to full

  // Start annealing
  MACHINE_STATE.ann_state = 1;
}

void sc7_retry_annealing(void)
{
  // Start annealing
  MACHINE_STATE.ann_state = 1;
}
