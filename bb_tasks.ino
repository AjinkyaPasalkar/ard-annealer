char* sc1_get_selected_case_name(void)
{

}

uint16_t sc1_get_selected_case_time(void)
{

}

void sc1_draw_list(void)
{

}

void sc2_draw_count(void)
{

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
    // update time of current case in EEPROM
    SC4_STATE.save_enabled = false;
  }
}

void sc4_update_time(void)
{
  // erase sec msec times
  // draw sec time
  // draw msec time
  // enable save button if not already
}

void sc5_add_space(void)
{

}

void sc5_clear_textbox(void)
{

}

void sc5_update_textbox(int row, int col)
{

}

void sc8_delete_case(uint8_t case_id)
{

}

void sc8_stop_annealing(void)
{

}

void sc6_repeat_annealing(void)
{

}

void sc7_retry_annealing(void)
{

}
