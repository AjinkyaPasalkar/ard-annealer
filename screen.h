#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "screens/screen_1.h"
#include "screens/screen_2.h"
#include "screens/screen_3.h"

/*!
    @brief    Screen Text Parameters
*/
typedef struct {
  char           *text;             /*!< Text */
  const GFXfont  *text_font;        /*!< Font of text */
  uint8_t         text_size;        /*!< Size of text. Keep equal to 1 */
  uint16_t        text_x;           /*!< X coordinate */
  uint16_t        text_y;           /*!< Y coordinate */

  uint8_t         rect_thickness;   /*!< Thickness of border. Default: 0 */
  uint16_t        rect_x;           /*!< X coordinate */
  uint16_t        rect_y;           /*!< Y coordinate */
  uint16_t        rect_x_len;       /*!< Width */
  uint16_t        rect_y_len;       /*!< Height */

  uint8_t         fill_en;          /*!< Enable fill. Default: false */

  uint16_t        text_color;       /*!< Text color */
  uint16_t        rect_color;       /*!< Border color */
  uint16_t        fill_color;       /*!< Fill color */
} SCREEN_TEXT_Params;
#endif
