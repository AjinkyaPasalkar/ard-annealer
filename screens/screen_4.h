#ifndef __SCREEN_4_H__
#define __SCREEN_4_H__

/************************************************************\
 *                         Screen 4                         *
\************************************************************/

// Title
#define TFT_SC4_TITLE_TXT         "CASE NAME"
#define TFT_SC4_TITLE_TXT_CLR     ILI9341_WHITE
#define TFT_SC4_TITLE_TXT_FONT    FreeSerifBold18pt7b
#define TFT_SC4_TITLE_TXT_SIZE    1
#define TFT_SC4_TITLE_TXT_X       10
#define TFT_SC4_TITLE_TXT_Y       30

// Text 1 Seconds
#define TFT_SC4_TXT1_TXT        "00"
#define TFT_SC4_TXT1_TXT_CLR    ILI9341_WHITE
#define TFT_SC4_TXT1_TXT_FONT   FreeSerifBold18pt7b
#define TFT_SC4_TXT1_TXT_SIZE   1
#define TFT_SC4_TXT1_TXT_X      28
#define TFT_SC4_TXT1_TXT_Y      134

// Text 2 milliseconds
#define TFT_SC4_TXT2_TXT        "0"
#define TFT_SC4_TXT2_TXT_CLR    ILI9341_WHITE
#define TFT_SC4_TXT2_TXT_FONT   FreeSerifBold18pt7b
#define TFT_SC4_TXT2_TXT_SIZE   1
#define TFT_SC4_TXT2_TXT_X      107
#define TFT_SC4_TXT2_TXT_Y      TFT_SC4_TXT1_TXT_Y

// Button 1
#define TFT_SC4_BTN1_TXT        "STOP"
#define TFT_SC4_BTN1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC4_BTN1_TXT_X      50
#define TFT_SC4_BTN1_TXT_Y      222

#define TFT_SC4_BTN1_RECT_X     10
#define TFT_SC4_BTN1_RECT_Y     200
#define TFT_SC4_BTN1_RECT_XLEN  140
#define TFT_SC4_BTN1_RECT_YLEN  30
#define TFT_SC4_BTN1_RECT_THICK 1

#define TFT_SC4_BTN1_ROUND_EN   true
#define TFT_SC4_BTN1_FILL_EN    true

#define TFT_SC4_BTN1_TXT_CLR    ILI9341_YELLOW
#define TFT_SC4_BTN1_RECT_CLR   ILI9341_BLUE
#define TFT_SC4_BTN1_FILL_CLR   ILI9341_NAVY

// Button 2
#define TFT_SC4_BTN2_TXT        "PASUE"
#define TFT_SC4_BTN2_TXT_FONT   TFT_SC4_BTN1_TXT_FONT
#define TFT_SC4_BTN2_TXT_X      202
#define TFT_SC4_BTN2_TXT_Y      TFT_SC4_BTN1_TXT_Y

#define TFT_SC4_BTN2_RECT_X     170
#define TFT_SC4_BTN2_RECT_Y     TFT_SC4_BTN1_RECT_Y
#define TFT_SC4_BTN2_RECT_XLEN  TFT_SC4_BTN1_RECT_XLEN
#define TFT_SC4_BTN2_RECT_YLEN  TFT_SC4_BTN1_RECT_YLEN
#define TFT_SC4_BTN2_RECT_THICK TFT_SC4_BTN1_RECT_THICK

#define TFT_SC4_BTN2_ROUND_EN   TFT_SC4_BTN1_ROUND_EN
#define TFT_SC4_BTN2_FILL_EN    TFT_SC4_BTN1_FILL_EN

#define TFT_SC4_BTN2_TXT_CLR    TFT_SC4_BTN1_TXT_CLR
#define TFT_SC4_BTN2_RECT_CLR   TFT_SC4_BTN1_RECT_CLR
#define TFT_SC4_BTN2_FILL_CLR   TFT_SC4_BTN1_FILL_CLR

// Button 4
#define TFT_SC4_BTN4_TXT        "SAVE"
#define TFT_SC4_BTN4_TXT_CLR    TFT_SC4_BTN1_TXT_CLR
#define TFT_SC4_BTN4_TXT_FONT   TFT_SC4_BTN1_TXT_FONT
#define TFT_SC4_BTN4_TXT_SIZE   TFT_SC4_BTN1_TXT_SIZE
#define TFT_SC4_BTN4_TXT_X      243
#define TFT_SC4_BTN4_TXT_Y      29

#define TFT_SC4_BTN4_RECT_X     238
#define TFT_SC4_BTN4_RECT_Y     8
#define TFT_SC4_BTN4_RECT_XLEN  74
#define TFT_SC4_BTN4_RECT_YLEN  30
#define TFT_SC4_BTN4_RECT_THICK 1
#define TFT_SC4_BTN4_RECT_CLR   TFT_SC4_BTN1_RECT_CLR

// Button 5
#define TFT_SC4_BTN5_TXT        "COUNT"
#define TFT_SC4_BTN5_TXT_CLR    TFT_SC4_BTN1_TXT_CLR
#define TFT_SC4_BTN5_TXT_FONT   TFT_SC4_BTN1_TXT_FONT
#define TFT_SC4_BTN5_TXT_SIZE   TFT_SC4_BTN1_TXT_SIZE
#define TFT_SC4_BTN5_TXT_X      246-50
#define TFT_SC4_BTN5_TXT_Y      39+60

#define TFT_SC4_BTN5_RECT_X     238-50
#define TFT_SC4_BTN5_RECT_Y     17+60
#define TFT_SC4_BTN5_RECT_XLEN  100
#define TFT_SC4_BTN5_RECT_YLEN  30
#define TFT_SC4_BTN5_RECT_THICK 1
#define TFT_SC4_BTN5_RECT_CLR   TFT_SC4_BTN1_RECT_CLR

// Button 6 - Seconds++
#define TFT_SC4_BTN6_ARROW_X        85
#define TFT_SC4_BTN6_ARROW_Y        93
#define TFT_SC4_BTN6_ARROW_DIR      0

#define TFT_SC4_BTN6_RECT_X         75
#define TFT_SC4_BTN6_RECT_Y         78
#define TFT_SC4_BTN6_RECT_XLEN      20
#define TFT_SC4_BTN6_RECT_YLEN      20
#define TFT_SC4_BTN6_RECT_THICK     0

#define TFT_SC4_BTN6_ROUND_EN       false
#define TFT_SC4_BTN6_FILL_EN        false

#define TFT_SC4_BTN6_ARROW_CLR      ILI9341_YELLOW
#define TFT_SC4_BTN6_RECT_CLR       ILI9341_BLACK
#define TFT_SC4_BTN6_FILL_CLR       ILI9341_BLACK

// Button 7 - Seconds--
#define TFT_SC4_BTN7_ARROW_X        TFT_SC4_BTN6_ARROW_X
#define TFT_SC4_BTN7_ARROW_Y        149
#define TFT_SC4_BTN7_ARROW_DIR      1

#define TFT_SC4_BTN7_RECT_X         TFT_SC4_BTN6_RECT_X
#define TFT_SC4_BTN7_RECT_Y         134
#define TFT_SC4_BTN7_RECT_XLEN      TFT_SC4_BTN6_RECT_XLEN
#define TFT_SC4_BTN7_RECT_YLEN      TFT_SC4_BTN6_RECT_YLEN
#define TFT_SC4_BTN7_RECT_THICK     TFT_SC4_BTN6_RECT_THICK

#define TFT_SC4_BTN7_ROUND_EN       TFT_SC4_BTN6_ROUND_EN
#define TFT_SC4_BTN7_FILL_EN        TFT_SC4_BTN6_FILL_EN

#define TFT_SC4_BTN7_ARROW_CLR      TFT_SC4_BTN6_ARROW_CLR
#define TFT_SC4_BTN7_RECT_CLR       TFT_SC4_BTN6_RECT_CLR
#define TFT_SC4_BTN7_FILL_CLR       TFT_SC4_BTN6_FILL_CLR

// Button 8 - miliSeconds++
#define TFT_SC4_BTN8_ARROW_X        155
#define TFT_SC4_BTN8_ARROW_Y        TFT_SC4_BTN6_ARROW_Y
#define TFT_SC4_BTN8_ARROW_DIR      TFT_SC4_BTN6_ARROW_DIR

#define TFT_SC4_BTN8_RECT_X         145
#define TFT_SC4_BTN8_RECT_Y         TFT_SC4_BTN6_RECT_Y
#define TFT_SC4_BTN8_RECT_XLEN      TFT_SC4_BTN6_RECT_XLEN
#define TFT_SC4_BTN8_RECT_YLEN      TFT_SC4_BTN6_RECT_YLEN
#define TFT_SC4_BTN8_RECT_THICK     TFT_SC4_BTN6_RECT_THICK

#define TFT_SC4_BTN8_ROUND_EN       TFT_SC4_BTN6_ROUND_EN
#define TFT_SC4_BTN8_FILL_EN        TFT_SC4_BTN6_FILL_EN

#define TFT_SC4_BTN8_ARROW_CLR      TFT_SC4_BTN6_ARROW_CLR
#define TFT_SC4_BTN8_RECT_CLR       TFT_SC4_BTN6_RECT_CLR
#define TFT_SC4_BTN8_FILL_CLR       TFT_SC4_BTN6_FILL_CLR

// Button 9 - miliSeconds--
#define TFT_SC4_BTN9_ARROW_X        TFT_SC4_BTN8_ARROW_X
#define TFT_SC4_BTN9_ARROW_Y        TFT_SC4_BTN7_ARROW_Y
#define TFT_SC4_BTN9_ARROW_DIR      TFT_SC4_BTN7_ARROW_DIR

#define TFT_SC4_BTN9_RECT_X         TFT_SC4_BTN8_RECT_X
#define TFT_SC4_BTN9_RECT_Y         TFT_SC4_BTN7_RECT_Y
#define TFT_SC4_BTN9_RECT_XLEN      TFT_SC4_BTN6_RECT_XLEN
#define TFT_SC4_BTN9_RECT_YLEN      TFT_SC4_BTN6_RECT_YLEN
#define TFT_SC4_BTN9_RECT_THICK     TFT_SC4_BTN6_RECT_THICK

#define TFT_SC4_BTN9_ROUND_EN       TFT_SC4_BTN6_ROUND_EN
#define TFT_SC4_BTN9_FILL_EN        TFT_SC4_BTN6_FILL_EN

#define TFT_SC4_BTN9_ARROW_CLR      TFT_SC4_BTN6_ARROW_CLR
#define TFT_SC4_BTN9_RECT_CLR       TFT_SC4_BTN6_RECT_CLR
#define TFT_SC4_BTN9_FILL_CLR       TFT_SC4_BTN6_FILL_CLR


#endif
