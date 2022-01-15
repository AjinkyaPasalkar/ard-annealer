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

}

void sc3_run_test(void)
{

}

void sc3_inc_sec(void)
{

}

void sc3_dec_sec(void)
{

}

void sc3_inc_msec(void)
{

}

void sc3_dec_msec(void)
{

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
