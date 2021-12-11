#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "screens/screen_1.h"
#include "screens/screen_2.h"

/*!
 *  @brief    Screen Text Parameters
 */
typedef struct {
  uint16_t        x;            /*!< X coordinate */
  uint16_t        y;            /*!< Y coordinate */
  char           *text;         /*!< Text of title */
  uint16_t        color;        /*!< Color of text */
  const GFXfont  *font;         /*!< Font of title */
  uint8_t         size;         /*!< Size of text. Keep equal to 1 */
}SCREEN_TEXT_Params;
#endif
