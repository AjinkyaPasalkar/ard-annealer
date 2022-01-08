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
  // if paused
  // let current annealing go complete
  // change pause -> start

  // else
  // change start -> pause
  // start annealing
}

void sc4_update_case(void)
{
  // if save button enabled
  // update time of current case
  // make save button disabled
}

void sc4_update_time(void)
{
  // erase sec msec times
  // draw sec time
  // draw msec time
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
