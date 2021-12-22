/*!
    @brief    Initialise Easydriver stepper motor
*/
void ed_init(void)
{
  pinMode(PIN_ED_DIR, OUTPUT);
  pinMode(PIN_ED_STEP, OUTPUT);

  digitalWrite(PIN_ED_DIR, HIGH);
  digitalWrite(PIN_ED_STEP, LOW);
}

/*!
    @brief    Enable/Disable stepper motor turning
*/
void ed_enable(bool state)
{
  static bool currState = false;

  if (currState != state)
  {
    currState = state;
    if (currState == true)
    {
      analogWrite(PIN_ED_STEP, 127);
    }
    else
    {
      digitalWrite(PIN_ED_STEP, LOW);
    }
  }
}
