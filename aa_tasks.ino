void task_touch(void)
{
  TS_Point p = touch_get_coord();
  if (p.x == 0 && p.y == 0)
  {
    // No touch detected.
    return;
  }

  // Handle Touch on screen 1. Case selection screen
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
      if (SC1_STATE.selected_id <= 0)
      {
        SC1_STATE.selected_id = 0;
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
      if (SC1_STATE.selected_id >= SC1_STATE.max_cases - 1)
      {
        SC1_STATE.selected_id = SC1_STATE.max_cases - 1;
      }
      else
      {
        SC1_STATE.selected_id += 1;
      }
      sc1_draw_list();
    }
  }

  // Handle Touch on screen 2. Case count selection screen
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

  // Handle Touch on screen 3. Add new case
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
      if (SC3_STATE.sec < 99)
      {
        SC3_STATE.sec += 1;
      }
      else
      {
        SC3_STATE.sec = 0;
      }
      sc3_update_time();
    }
    else if ((p.x > TFT_SC3_BTN7_RECT_X) && (p.x < TFT_SC3_BTN7_RECT_X + TFT_SC3_BTN7_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN7_RECT_Y) && (p.y < TFT_SC3_BTN7_RECT_Y + TFT_SC3_BTN7_RECT_YLEN))
    {
      // Seconds-- pressed
      if (SC3_STATE.sec > 0)
      {
        SC3_STATE.sec -= 1;
      }
      else
      {
        SC3_STATE.sec = 99;
      }
      sc3_update_time();
    }
    else if ((p.x > TFT_SC3_BTN8_RECT_X) && (p.x < TFT_SC3_BTN8_RECT_X + TFT_SC3_BTN8_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN8_RECT_Y) && (p.y < TFT_SC3_BTN8_RECT_Y + TFT_SC3_BTN8_RECT_YLEN))
    {
      // miliSeconds++ pressed
      if (SC3_STATE.msec < 9)
      {
        SC3_STATE.msec += 1;
      }
      else
      {
        SC3_STATE.msec = 0;
      }
      sc3_update_time();
    }

    else if ((p.x > TFT_SC3_BTN9_RECT_X) && (p.x < TFT_SC3_BTN9_RECT_X + TFT_SC3_BTN9_RECT_XLEN) &&
             (p.y > TFT_SC3_BTN9_RECT_Y) && (p.y < TFT_SC3_BTN9_RECT_Y + TFT_SC3_BTN9_RECT_YLEN))
    {
      // miliSeconds-- pressed
      if (SC3_STATE.msec > 0)
      {
        SC3_STATE.msec -= 1;
      }
      else
      {
        SC3_STATE.msec = 9;
      }
      sc3_update_time();
    }
  }

  // Handle Touch on screen 4. Annealing in progress screen
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

  // Handle Touch on screen 5. Keyboard screen
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

  // Handle Touch on screen 6. Annealing finished screen
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

  // Handle Touch on screen 7. Error screen
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

  // Handle Touch on screen 8. Confirmation screen
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

void task_motor(void)
{
  static bool prev_state = false;
  static uint32_t motor_start_time;

  // Motor will be ON if MACHINE_STATE.motor is true
  // Motor will be OFF if MACHINE_STATE.motor is false
  ed_enable(MACHINE_STATE.motor);

  // If motor state is changing from OFF to ON
  if (prev_state == false && MACHINE_STATE.motor == true)
  {
    // Update previous state and store current time
    prev_state = true;
    motor_start_time = currMillis;
  }
  // Else if motor state is changing from ON to OFF
  else if (prev_state == true && MACHINE_STATE.motor == false)
  {
    // Update previous step
    prev_state = false;
  }

  // If 60 seconds have passed but still IR has not detected a case
  if ((currMillis > motor_start_time + 60000) && MACHINE_STATE.motor == true)
  {
    // Turn off motor, stop annealing and display error screen
    MACHINE_STATE.ann_state = 0;
    MACHINE_STATE.motor == false;

    MACHINE_STATE.prev_screen_id = 4;
    MACHINE_STATE.screen_id = 7;
    tft_draw_sc7();
  }
}

void task_ir(void)
{
  // If motor is ON and IR detects a case
  if (MACHINE_STATE.motor == true && ir_detect() == true)
  {
    // Turn OFF motor and Turn ON relay
    MACHINE_STATE.motor = false;
    MACHINE_STATE.ssr = true;
  }
}

void task_ssr(void)
{
  static bool prev_state = false;
  static uint32_t ssr_start_time;

  // Relay will be ON if MACHINE_STATE.ssr is true
  // Relay will be OFF if MACHINE_STATE.ssr is false
  ssr_set(MACHINE_STATE.ssr);

  // If relay state is changing from OFF to ON
  if (prev_state == false && MACHINE_STATE.ssr == true)
  {
    // Update previous state and store current time
    prev_state = true;
    ssr_start_time = currMillis;
  }
  // Else if relay state is changing from ON to OFF
  else if (prev_state == true && MACHINE_STATE.ssr == false)
  {
    // Update previous step
    prev_state = false;
  }

  // Wait for time set for the case
  if (currMillis > (MACHINE_STATE.case_time_sec * 1000 + MACHINE_STATE.case_time_msec) && MACHINE_STATE.ssr == true)
  {
    // Turn OFF relay and turn ON servo
    MACHINE_STATE.ssr = false;
    MACHINE_STATE.servo = true;
  }
}

void task_servo(void)
{
  static bool prev_state = false;
  static uint32_t servo_start_time;

  // Servo will be 90 degree if MACHINE_STATE.servo is true
  // Servo will be 0 degree if MACHINE_STATE.servo is false
  servo_set_angle(MACHINE_STATE.servo * 90);

  // If servo state is changing from OFF to ON
  if (prev_state == false && MACHINE_STATE.servo == true)
  {
    // Update previous state and store current time
    prev_state = true;
    servo_start_time = currMillis;
  }
  // Else if servo state is changing from ON to OFF
  else if (prev_state == true && MACHINE_STATE.servo == false)
  {
    // Wait for at least 10 sec or twice the time for the case
    if (currMillis > servo_start_time + 10000)
    {
      if (currMillis > 2 * (MACHINE_STATE.case_time_sec * 1000 + MACHINE_STATE.case_time_msec))
      {
        // Increase count, update previous state and start motor
        MACHINE_STATE.count += 1;
        sc4_draw_count();
        prev_state = false;
        MACHINE_STATE.motor == true;
      }
    }
  }

  // Turn OFF servo after 0.5 seconds
  if ((currMillis > servo_start_time + 500) && MACHINE_STATE.servo == true)
  {
    MACHINE_STATE.servo = false;
  }
}
