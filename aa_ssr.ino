/*!
    @brief    Initialise Solid State Relay
*/
void ssr_init(void)
{
  pinMode(PIN_SSR, OUTPUT);
  digitalWrite(PIN_SSR, LOW);
}

/*!
    @brief    Enable/Disable SSR
*/
void ssr_set(bool state)
{
  static uint8_t currState = false;

  if (currState != state)
  {
    currState = state;
    digitalWrite(PIN_SSR, currState);
  }
}
