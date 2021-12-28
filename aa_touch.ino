// This is calibration data for the raw touch data to the screen coordinates
#define TS_MINX 370
#define TS_MINY 310
#define TS_MAXX 3800
#define TS_MAXY 3740

/*!
    @brief    Initialise Touch screen
*/
void touch_init(void)
{
  ts.begin();
  ts.setRotation(1);
}

/*!
    @brief    Return coordinates if touched
*/
TS_Point touch_get_coord()
{
  TS_Point p;

  if (ts.tirqTouched() && ts.touched())
  {
    // Retrieve a point
    p = ts.getPoint();

    // Scale from ~0->4000 to tft.width using the calibration #'s
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.width());
    p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.height());
  }
  return p;
}
