/*!
    @brief    Initialise Servo motor
*/
void servo_init(void)
{
  Servo1.attach(PIN_SERVO);
  Servo1.write(0);
}

/*!
    @brief    Set Servo motor angle
*/
void servo_set_angle(uint8_t angle)
{
  static uint8_t currAngle = 0;

  if (currAngle != angle)
  {
    currAngle = angle;
    Servo1.write(currAngle);
  }

}
