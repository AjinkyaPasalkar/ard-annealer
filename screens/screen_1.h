#ifndef __SCREEN_1_H__
#define __SCREEN_1_H__

/************************************************************\
 *                         Screen 1                         *
\************************************************************/

// Title
#define TFT_SC1_TITLE_TXT         "SELECT CASE"
#define TFT_SC1_TITLE_TXT_CLR     ILI9341_YELLOW
#define TFT_SC1_TITLE_TXT_FONT    FreeSerifBold18pt7b
#define TFT_SC1_TITLE_TXT_X       10
#define TFT_SC1_TITLE_TXT_Y       30

// Button 1
#define TFT_SC1_BTN1_TXT            "SELECT"
#define TFT_SC1_BTN1_TXT_FONT       FreeSerifBold12pt7b
#define TFT_SC1_BTN1_TXT_X          30
#define TFT_SC1_BTN1_TXT_Y          222

#define TFT_SC1_BTN1_RECT_X         10
#define TFT_SC1_BTN1_RECT_Y         200
#define TFT_SC1_BTN1_RECT_XLEN      140
#define TFT_SC1_BTN1_RECT_YLEN      30
#define TFT_SC1_BTN1_RECT_THICK     1

#define TFT_SC1_BTN1_ROUND_EN       true
#define TFT_SC1_BTN1_FILL_EN        true

#define TFT_SC1_BTN1_TXT_CLR        ILI9341_YELLOW
#define TFT_SC1_BTN1_RECT_CLR       ILI9341_BLUE
#define TFT_SC1_BTN1_FILL_CLR       ILI9341_NAVY

// Button 2
#define TFT_SC1_BTN2_TXT        "ADD"
#define TFT_SC1_BTN2_TXT_FONT   TFT_SC1_BTN1_TXT_FONT
#define TFT_SC1_BTN2_TXT_X      212
#define TFT_SC1_BTN2_TXT_Y      TFT_SC1_BTN1_TXT_Y

#define TFT_SC1_BTN2_RECT_X     170
#define TFT_SC1_BTN2_RECT_Y     TFT_SC1_BTN1_RECT_Y
#define TFT_SC1_BTN2_RECT_XLEN  TFT_SC1_BTN1_RECT_XLEN
#define TFT_SC1_BTN2_RECT_YLEN  TFT_SC1_BTN1_RECT_YLEN
#define TFT_SC1_BTN2_RECT_THICK TFT_SC1_BTN1_RECT_THICK

#define TFT_SC1_BTN2_ROUND_EN   TFT_SC1_BTN1_ROUND_EN
#define TFT_SC1_BTN2_FILL_EN    TFT_SC1_BTN1_FILL_EN

#define TFT_SC1_BTN2_TXT_CLR    TFT_SC1_BTN1_TXT_CLR
#define TFT_SC1_BTN2_RECT_CLR   TFT_SC1_BTN1_RECT_CLR
#define TFT_SC1_BTN2_FILL_CLR   TFT_SC1_BTN1_FILL_CLR

// Button 3 - UP
#define TFT_SC1_BTN3_ARROW_X        290
#define TFT_SC1_BTN3_ARROW_Y        77
#define TFT_SC1_BTN3_ARROW_DIR      0

#define TFT_SC1_BTN3_RECT_X         270
#define TFT_SC1_BTN3_RECT_Y         40
#define TFT_SC1_BTN3_RECT_XLEN      40
#define TFT_SC1_BTN3_RECT_YLEN      73
#define TFT_SC1_BTN3_RECT_THICK     TFT_SC1_BTN1_RECT_THICK

#define TFT_SC1_BTN3_ROUND_EN       false
#define TFT_SC1_BTN3_FILL_EN        TFT_SC1_BTN1_FILL_EN

#define TFT_SC1_BTN3_ARROW_CLR      ILI9341_YELLOW
#define TFT_SC1_BTN3_RECT_CLR       TFT_SC1_BTN1_RECT_CLR
#define TFT_SC1_BTN3_FILL_CLR       TFT_SC1_BTN1_FILL_CLR

// Button 4 - DOWN
#define TFT_SC1_BTN4_ARROW_X        TFT_SC1_BTN3_ARROW_X
#define TFT_SC1_BTN4_ARROW_Y        148
#define TFT_SC1_BTN4_ARROW_DIR      1

#define TFT_SC1_BTN4_RECT_X         TFT_SC1_BTN3_RECT_X
#define TFT_SC1_BTN4_RECT_Y         112
#define TFT_SC1_BTN4_RECT_XLEN      TFT_SC1_BTN3_RECT_XLEN
#define TFT_SC1_BTN4_RECT_YLEN      TFT_SC1_BTN3_RECT_YLEN
#define TFT_SC1_BTN4_RECT_THICK     TFT_SC1_BTN1_RECT_THICK

#define TFT_SC1_BTN4_ROUND_EN       TFT_SC1_BTN3_ROUND_EN
#define TFT_SC1_BTN4_FILL_EN        TFT_SC1_BTN3_FILL_EN

#define TFT_SC1_BTN4_RECT_CLR       TFT_SC1_BTN1_RECT_CLR
#define TFT_SC1_BTN4_ARROW_CLR      TFT_SC1_BTN3_ARROW_CLR
#define TFT_SC1_BTN4_FILL_CLR       TFT_SC1_BTN1_FILL_CLR


#endif
