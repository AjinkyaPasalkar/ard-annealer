void task_touch(void)
{
  TS_Point p = touch_get_coord();
  if (p.x == 0 && p.y == 0)
  {
    // No touch detected.
    return;
  }

  if (MACHINE_STATE.screen_id == 1)
  {
    if ((p.x > TFT_SC1_BTN1_RECT_X) && (p.x < TFT_SC1_BTN1_RECT_X + TFT_SC1_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC1_BTN1_RECT_Y) && (p.y < TFT_SC1_BTN1_RECT_Y + TFT_SC1_BTN1_RECT_YLEN))
    {
      // SELECT pressed
      MACHINE_STATE.case_id   = SC1_STATE.selected_id;
      MACHINE_STATE.case_name = sc1_get_selected_case_name();
      MACHINE_STATE.case_time = sc1_get_selected_case_time();
      tft_draw_sc2();
      MACHINE_STATE.screen_id = 2;
    }
    else if ((p.x > TFT_SC1_BTN2_RECT_X) && (p.x < TFT_SC1_BTN2_RECT_X + TFT_SC1_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC1_BTN2_RECT_Y) && (p.y < TFT_SC1_BTN2_RECT_Y + TFT_SC1_BTN2_RECT_YLEN))
    {
      // ADD pressed
      // Draw ADD-NEW-CASE screen and update MACHINE_STATE
      tft_draw_sc3();
      MACHINE_STATE.screen_id = 3;
    }
    else if ((p.x > TFT_SC1_BTN3_RECT_X) && (p.x < TFT_SC1_BTN3_RECT_X + TFT_SC1_BTN3_RECT_XLEN) &&
             (p.y > TFT_SC1_BTN3_RECT_Y) && (p.y < TFT_SC1_BTN3_RECT_Y + TFT_SC1_BTN3_RECT_YLEN))
    {
      // UP pressed
      if (SC1_STATE.selected_id <= 1)
      {
        SC1_STATE.selected_id = 1;
      }
      else
      {
        SC1_STATE.selected_id -= 1;
      }
      sc1_draw_list();
    }
    else if ((p.x > TFT_SC1_BTN4_RECT_X) && (p.x < TFT_SC1_BTN4_RECT_X + TFT_SC1_BTN4_RECT_XLEN) &&
             (p.y > TFT_SC1_BTN4_RECT_Y) && (p.y < TFT_SC1_BTN4_RECT_Y + TFT_SC1_BTN4_RECT_YLEN))
    {
      // DOWN pressed
      if (SC1_STATE.selected_id >= SC1_STATE.max_cases)
      {
        SC1_STATE.selected_id = SC1_STATE.max_cases;
      }
      else
      {
        SC1_STATE.selected_id += 1;
      }
      sc1_draw_list();
    }
  }
}
