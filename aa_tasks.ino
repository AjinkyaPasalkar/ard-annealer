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
      MACHINE_STATE.case_name = sc1_get_selected_case_name(SC1_STATE.selected_id);
      MACHINE_STATE.case_time_sec = sc1_get_selected_case_time_sec();
      MACHINE_STATE.case_time_msec = sc1_get_selected_case_time_msec();
      MACHINE_STATE.prev_screen_id = 1;
      MACHINE_STATE.screen_id = 2;
      tft_draw_sc2();
    }
    else if ((p.x > TFT_SC1_BTN2_RECT_X) && (p.x < TFT_SC1_BTN2_RECT_X + TFT_SC1_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC1_BTN2_RECT_Y) && (p.y < TFT_SC1_BTN2_RECT_Y + TFT_SC1_BTN2_RECT_YLEN))
    {
      // ADD pressed
      // Draw ADD-NEW-CASE screen and update MACHINE_STATE
      MACHINE_STATE.prev_screen_id = 1;
      MACHINE_STATE.screen_id = 3;
      tft_draw_sc3();
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

  else if (MACHINE_STATE.screen_id == 2)
  {
    if ((p.x > TFT_SC2_BTN1_RECT_X) && (p.x < TFT_SC2_BTN1_RECT_X + TFT_SC2_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC2_BTN1_RECT_Y) && (p.y < TFT_SC2_BTN1_RECT_Y + TFT_SC2_BTN1_RECT_YLEN))
    {
      // START pressed
      MACHINE_STATE.total_cases = SC2_STATE.count;
      MACHINE_STATE.ann_state = 1; // Annealing state = running
      tft_draw_sc4();
      MACHINE_STATE.screen_id = 4;
    }
    else if ((p.x > TFT_SC2_BTN2_RECT_X) && (p.x < TFT_SC2_BTN2_RECT_X + TFT_SC2_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN2_RECT_Y) && (p.y < TFT_SC2_BTN2_RECT_Y + TFT_SC2_BTN2_RECT_YLEN))
    {
      // BACK pressed
      tft_draw_sc1();
      MACHINE_STATE.screen_id = 1;
    }
    else if ((p.x > TFT_SC2_BTN3_RECT_X) && (p.x < TFT_SC2_BTN3_RECT_X + TFT_SC2_BTN3_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN3_RECT_Y) && (p.y < TFT_SC2_BTN3_RECT_Y + TFT_SC2_BTN3_RECT_YLEN))
    {
      // EDIT pressed
      tft_draw_sc3();
      MACHINE_STATE.screen_id = 3;
    }
    else if ((p.x > TFT_SC2_BTN4_RECT_X) && (p.x < TFT_SC2_BTN4_RECT_X + TFT_SC2_BTN4_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN4_RECT_Y) && (p.y < TFT_SC2_BTN4_RECT_Y + TFT_SC2_BTN4_RECT_YLEN))
    {
      // -10 pressed
      if (SC2_STATE.count - 10 >= 1)
      {
        SC2_STATE.count -= 10;
      }
      else
      {
        SC2_STATE.count = 1;
      }
      sc2_draw_count();
    }
    else if ((p.x > TFT_SC2_BTN5_RECT_X) && (p.x < TFT_SC2_BTN5_RECT_X + TFT_SC2_BTN5_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN5_RECT_Y) && (p.y < TFT_SC2_BTN5_RECT_Y + TFT_SC2_BTN5_RECT_YLEN))
    {
      // -1 pressed
      if (SC2_STATE.count - 1 >= 1)
      {
        SC2_STATE.count -= 1;
      }
      else
      {
        SC2_STATE.count = 1;
      }
      sc2_draw_count();
    }
    else if ((p.x > TFT_SC2_BTN6_RECT_X) && (p.x < TFT_SC2_BTN6_RECT_X + TFT_SC2_BTN6_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN6_RECT_Y) && (p.y < TFT_SC2_BTN6_RECT_Y + TFT_SC2_BTN6_RECT_YLEN))
    {
      // +1 pressed
      if (SC2_STATE.count + 1 <= 999)
      {
        SC2_STATE.count += 1;
      }
      else
      {
        SC2_STATE.count = 999;
      }
      sc2_draw_count();
    }
    else if ((p.x > TFT_SC2_BTN7_RECT_X) && (p.x < TFT_SC2_BTN7_RECT_X + TFT_SC2_BTN7_RECT_XLEN) &&
             (p.y > TFT_SC2_BTN7_RECT_Y) && (p.y < TFT_SC2_BTN7_RECT_Y + TFT_SC2_BTN7_RECT_YLEN))
    {
      // +10 pressed
      if (SC2_STATE.count + 10 <= 999)
      {
        SC2_STATE.count += 10;
      }
      else
      {
        SC2_STATE.count = 999;
      }
      sc2_draw_count();
    }
  }

  else if (MACHINE_STATE.screen_id == 3)
  {
    if ((p.x > TFT_SC3_BTN1_RECT_X) && (p.x < TFT_SC3_BTN1_RECT_X + TFT_SC3_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC3_BTN1_RECT_Y) && (p.y < TFT_SC3_BTN1_RECT_Y + TFT_SC3_BTN1_RECT_YLEN))
    {
      // ADD pressed
      sc3_add_case();
      MACHINE_STATE.prev_screen_id = 3;
      MACHINE_STATE.screen_id = 1;
      tft_draw_sc1();
    }
    else if ((p.x > TFT_SC3_BTN2_RECT_X) && (p.x < TFT_SC3_BTN2_RECT_X + TFT_SC3_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN2_RECT_Y) && (p.y < TFT_SC3_BTN2_RECT_Y + TFT_SC3_BTN2_RECT_YLEN))
    {
      // BACK pressed
      MACHINE_STATE.prev_screen_id = 3;
      MACHINE_STATE.screen_id = 1;
      tft_draw_sc1();
    }

    else if ((p.x > TFT_SC3_BTN4_RECT_X) && (p.x < TFT_SC3_BTN4_RECT_X + TFT_SC3_BTN4_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN4_RECT_Y) && (p.y < TFT_SC3_BTN4_RECT_Y + TFT_SC3_BTN4_RECT_YLEN))
    {
      // EDIT pressed
      MACHINE_STATE.prev_screen_id = 3;
      MACHINE_STATE.screen_id = 5;
      tft_draw_sckey();
    }

    else if ((p.x > TFT_SC3_BTN5_RECT_X) && (p.x < TFT_SC3_BTN5_RECT_X + TFT_SC3_BTN5_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN5_RECT_Y) && (p.y < TFT_SC3_BTN5_RECT_Y + TFT_SC3_BTN5_RECT_YLEN))
    {
      // TEST pressed
      sc3_run_test();
    }

    else if ((p.x > TFT_SC3_BTN6_RECT_X) && (p.x < TFT_SC3_BTN6_RECT_X + TFT_SC3_BTN6_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN6_RECT_Y) && (p.y < TFT_SC3_BTN6_RECT_Y + TFT_SC3_BTN6_RECT_YLEN))
    {
      // Seconds++ pressed
      sc3_inc_sec();
    }

    else if ((p.x > TFT_SC3_BTN7_RECT_X) && (p.x < TFT_SC3_BTN7_RECT_X + TFT_SC3_BTN7_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN7_RECT_Y) && (p.y < TFT_SC3_BTN7_RECT_Y + TFT_SC3_BTN7_RECT_YLEN))
    {
      // Seconds-- pressed
      sc3_dec_sec();
    }

    else if ((p.x > TFT_SC3_BTN8_RECT_X) && (p.x < TFT_SC3_BTN8_RECT_X + TFT_SC3_BTN8_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN8_RECT_Y) && (p.y < TFT_SC3_BTN8_RECT_Y + TFT_SC3_BTN8_RECT_YLEN))
    {
      // miliSeconds++ pressed
      sc3_inc_msec();
    }

    else if ((p.x > TFT_SC3_BTN9_RECT_X) && (p.x < TFT_SC3_BTN9_RECT_X + TFT_SC3_BTN9_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN9_RECT_Y) && (p.y < TFT_SC3_BTN9_RECT_Y + TFT_SC3_BTN9_RECT_YLEN))
    {
      // miliSeconds-- pressed
      sc3_dec_msec();
    }
  }

  else if (MACHINE_STATE.screen_id == 4)
  {
    if ((p.x > TFT_SC4_BTN1_RECT_X) && (p.x < TFT_SC4_BTN1_RECT_X + TFT_SC4_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC4_BTN1_RECT_Y) && (p.y < TFT_SC4_BTN1_RECT_Y + TFT_SC4_BTN1_RECT_YLEN))
    {
      // STOP pressed
      MACHINE_STATE.prev_screen_id = 4;
      MACHINE_STATE.screen_id = 8;
      tft_draw_sc8();
    }
    else if ((p.x > TFT_SC4_BTN2_RECT_X) && (p.x < TFT_SC4_BTN2_RECT_X + TFT_SC4_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN2_RECT_Y) && (p.y < TFT_SC4_BTN2_RECT_Y + TFT_SC4_BTN2_RECT_YLEN))
    {
      // PAUSE pressed
      sc4_pause_annealing();
    }
    else if ((p.x > TFT_SC4_BTN4_RECT_X) && (p.x < TFT_SC4_BTN4_RECT_X + TFT_SC4_BTN4_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN4_RECT_Y) && (p.y < TFT_SC4_BTN4_RECT_Y + TFT_SC4_BTN4_RECT_YLEN))
    {
      // SAVE pressed
      sc4_update_case();
    }
    else if ((p.x > TFT_SC4_BTN6_RECT_X) && (p.x < TFT_SC4_BTN6_RECT_X + TFT_SC4_BTN6_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN6_RECT_Y) && (p.y < TFT_SC4_BTN6_RECT_Y + TFT_SC4_BTN6_RECT_YLEN))
    {
      // Seconds++ pressed
      if (SC4_STATE.sec < 99)
      {
        SC4_STATE.sec += 1;
      }
      else
      {
        SC4_STATE.sec = 0;
      }
      sc4_update_time();
    }
    else if ((p.x > TFT_SC4_BTN7_RECT_X) && (p.x < TFT_SC4_BTN7_RECT_X + TFT_SC4_BTN7_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN7_RECT_Y) && (p.y < TFT_SC4_BTN7_RECT_Y + TFT_SC4_BTN7_RECT_YLEN))
    {
      // Seconds-- pressed
      if (SC4_STATE.sec > 0)
      {
        SC4_STATE.sec -= 1;
      }
      else
      {
        SC4_STATE.sec = 99;
      }
      sc4_update_time();
    }

    else if ((p.x > TFT_SC4_BTN8_RECT_X) && (p.x < TFT_SC4_BTN8_RECT_X + TFT_SC4_BTN8_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN8_RECT_Y) && (p.y < TFT_SC4_BTN8_RECT_Y + TFT_SC4_BTN8_RECT_YLEN))
    {
      // miliSeconds++ pressed
      if (SC4_STATE.msec < 9)
      {
        SC4_STATE.msec += 1;
      }
      else
      {
        SC4_STATE.msec = 0;
      }
      sc4_update_time();
    }
    else if ((p.x > TFT_SC4_BTN9_RECT_X) && (p.x < TFT_SC4_BTN9_RECT_X + TFT_SC4_BTN9_RECT_XLEN) &&
             (p.y > TFT_SC4_BTN9_RECT_Y) && (p.y < TFT_SC4_BTN9_RECT_Y + TFT_SC4_BTN9_RECT_YLEN))
    {
      // miliSeconds-- pressed
      if (SC4_STATE.msec > 0)
      {
        SC4_STATE.msec -= 1;
      }
      else
      {
        SC4_STATE.msec = 9;
      }
      sc4_update_time();
    }
  }

  else if (MACHINE_STATE.screen_id == 5)
  {
    if ((p.x > TFT_SCKEY_BTN5_RECT_X) && (p.x < TFT_SCKEY_BTN5_RECT_X + TFT_SCKEY_BTN5_RECT_XLEN) &&
        (p.y > TFT_SCKEY_BTN5_RECT_Y) && (p.y < TFT_SCKEY_BTN5_RECT_Y + TFT_SCKEY_BTN5_RECT_YLEN))
    {
      // SPACE pressed
      strcat(SC5_STATE.textbox, " ");
    }
    else if ((p.x > TFT_SCKEY_BTN6_RECT_X) && (p.x < TFT_SCKEY_BTN6_RECT_X + TFT_SCKEY_BTN6_RECT_XLEN) &&
             (p.y > TFT_SCKEY_BTN6_RECT_Y) && (p.y < TFT_SCKEY_BTN6_RECT_Y + TFT_SCKEY_BTN6_RECT_YLEN))
    {
      // CLEAR pressed
      sc5_clear_textbox();
    }
    else if ((p.x > TFT_SCKEY_BTN7_RECT_X) && (p.x < TFT_SCKEY_BTN7_RECT_X + TFT_SCKEY_BTN7_RECT_XLEN) &&
             (p.y > TFT_SCKEY_BTN7_RECT_Y) && (p.y < TFT_SCKEY_BTN7_RECT_Y + TFT_SCKEY_BTN7_RECT_YLEN))
    {
      // OK pressed
      if (strcmp(SC5_STATE.textbox, "") != 0)
      {
        strcpy(SC3_STATE.casename, SC5_STATE.textbox);
      }
      MACHINE_STATE.prev_screen_id = 5;
      MACHINE_STATE.screen_id = 3;
      tft_draw_sc3();
    }
    else
    {

      for (int row = 0; row < TFT_SCKEY_BTN_ROWS; row++)
      {
        for (int col = 0; col < TFT_SCKEY_BTN_COLUMNS; col++)
        {
          if (row == 2 && (col == 1 || col == 2 || col == 3 || col == 4)) continue;
          if ((p.x > TFT_SCKEY_BTN_RECT_X + (col * TFT_SCKEY_BTN_GAP_X)) && (p.x < TFT_SCKEY_BTN_RECT_X + (col * TFT_SCKEY_BTN_GAP_X) + TFT_SCKEY_BTN1_RECT_XLEN) &&
              (p.y > TFT_SCKEY_BTN_RECT_Y + (row * TFT_SCKEY_BTN_GAP_Y)) && (p.y < TFT_SCKEY_BTN_RECT_Y + (row * TFT_SCKEY_BTN_GAP_Y) + TFT_SCKEY_BTN1_RECT_YLEN))
          {
            sc5_update_textbox(row, col);
          }
        }
      }
    }
  }

  else if (MACHINE_STATE.screen_id == 6)
  {
    if ((p.x > TFT_SC6_BTN1_RECT_X) && (p.x < TFT_SC6_BTN1_RECT_X + TFT_SC6_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC6_BTN1_RECT_Y) && (p.y < TFT_SC6_BTN1_RECT_Y + TFT_SC6_BTN1_RECT_YLEN))
    {
      // REPEAT pressed
      sc6_repeat_annealing();
      MACHINE_STATE.prev_screen_id = 6;
      MACHINE_STATE.screen_id = 4;
      tft_draw_sc4();
    }

    else if ((p.x > TFT_SC6_BTN2_RECT_X) && (p.x < TFT_SC6_BTN2_RECT_X + TFT_SC6_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC6_BTN2_RECT_Y) && (p.y < TFT_SC6_BTN2_RECT_Y + TFT_SC6_BTN2_RECT_YLEN))
    {
      // FINISH pressed
      MACHINE_STATE.prev_screen_id = 6;
      MACHINE_STATE.screen_id = 1;
      tft_draw_sc1();
    }
  }

  else if (MACHINE_STATE.screen_id == 7)
  {
    if ((p.x > TFT_SC7_BTN1_RECT_X) && (p.x < TFT_SC7_BTN1_RECT_X + TFT_SC7_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC7_BTN1_RECT_Y) && (p.y < TFT_SC7_BTN1_RECT_Y + TFT_SC7_BTN1_RECT_YLEN))
    {
      // RETRY pressed
      sc7_retry_annealing();
      MACHINE_STATE.prev_screen_id = 7;
      MACHINE_STATE.screen_id = 4;
      tft_draw_sc4();
    }

    else if ((p.x > TFT_SC7_BTN2_RECT_X) && (p.x < TFT_SC7_BTN2_RECT_X + TFT_SC7_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC7_BTN2_RECT_Y) && (p.y < TFT_SC7_BTN2_RECT_Y + TFT_SC7_BTN2_RECT_YLEN))
    {
      // CANCEL pressed
      MACHINE_STATE.prev_screen_id = 7;
      MACHINE_STATE.screen_id = 1;
      tft_draw_sc1();
    }
  }

  else if (MACHINE_STATE.screen_id == 8)
  {
    if ((p.x > TFT_SC8_BTN1_RECT_X) && (p.x < TFT_SC8_BTN1_RECT_X + TFT_SC8_BTN1_RECT_XLEN) &&
        (p.y > TFT_SC8_BTN1_RECT_Y) && (p.y < TFT_SC8_BTN1_RECT_Y + TFT_SC8_BTN1_RECT_YLEN))
    {
      // YES pressed
      if (MACHINE_STATE.prev_screen_id == 2)
      {
        sc8_delete_case(MACHINE_STATE.case_id);
      }
      else if (MACHINE_STATE.prev_screen_id == 4)
      {
        sc8_stop_annealing();
      }
      MACHINE_STATE.prev_screen_id = 8;
      MACHINE_STATE.screen_id = 1;
      tft_draw_sc1();
    }
    else if ((p.x > TFT_SC8_BTN2_RECT_X) && (p.x < TFT_SC8_BTN2_RECT_X + TFT_SC8_BTN2_RECT_XLEN) &&
             (p.y > TFT_SC8_BTN2_RECT_Y) && (p.y < TFT_SC8_BTN2_RECT_Y + TFT_SC8_BTN2_RECT_YLEN))
    {
      // NO pressed
      if (MACHINE_STATE.prev_screen_id == 2)
      {
        // Go to screen 2
        MACHINE_STATE.prev_screen_id = 8;
        MACHINE_STATE.screen_id = 2;
        tft_draw_sc2();
      }
      else if (MACHINE_STATE.prev_screen_id == 4)
      {
        // Go to screen 4
        MACHINE_STATE.prev_screen_id = 8;
        MACHINE_STATE.screen_id = 4;
        tft_draw_sc4();
      }
    }
  }
}
