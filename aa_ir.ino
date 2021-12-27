#define IR_THRESHOLD 80

/*!
    @brief    Initialise IR sensor
*/
void ir_init(void)
{
  pinMode(PIN_IR, INPUT);
}

/*!
    @brief    Check if object is detected
*/
bool ir_detect()
{
  return analogRead(PIN_IR) > IR_THRESHOLD;
}
