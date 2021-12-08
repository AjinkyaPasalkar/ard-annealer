#ifndef __SCREEN_H__
#define __SCREEN_H__

/************************************************************\
 *                         Screen 1                         *
\************************************************************/

// Title
#define TFT_SC1_TITLE_TXT         "SELECT CASE"
#define TFT_SC1_TITLE_TXT_CLR     ILI9341_WHITE
#define TFT_SC1_TITLE_TXT_FONT    FreeSerifBold18pt7b
#define TFT_SC1_TITLE_TXT_SIZE    1
#define TFT_SC1_TITLE_TXT_X       10
#define TFT_SC1_TITLE_TXT_Y       30

// Button 1
#define TFT_SC1_BTN1_TXT        "SELECT"
#define TFT_SC1_BTN1_TXT_CLR    ILI9341_WHITE
#define TFT_SC1_BTN1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC1_BTN1_TXT_SIZE   1
#define TFT_SC1_BTN1_TXT_X      30
#define TFT_SC1_BTN1_TXT_Y      222

#define TFT_SC1_BTN1_RECT_X     10
#define TFT_SC1_BTN1_RECT_Y     200
#define TFT_SC1_BTN1_RECT_XLEN  140
#define TFT_SC1_BTN1_RECT_YLEN  30
#define TFT_SC1_BTN1_RECT_THICK 2
#define TFT_SC1_BTN1_RECT_CLR   ILI9341_WHITE

// Button 2
#define TFT_SC1_BTN2_TXT        "ADD"
#define TFT_SC1_BTN2_TXT_CLR    TFT_SC1_BTN1_TXT_CLR
#define TFT_SC1_BTN2_TXT_FONT   TFT_SC1_BTN1_TXT_FONT
#define TFT_SC1_BTN2_TXT_SIZE   TFT_SC1_BTN1_TXT_SIZE
#define TFT_SC1_BTN2_TXT_X      212
#define TFT_SC1_BTN2_TXT_Y      TFT_SC1_BTN1_TXT_Y

#define TFT_SC1_BTN2_RECT_X     170
#define TFT_SC1_BTN2_RECT_Y     TFT_SC1_BTN1_RECT_Y
#define TFT_SC1_BTN2_RECT_XLEN  TFT_SC1_BTN1_RECT_XLEN
#define TFT_SC1_BTN2_RECT_YLEN  TFT_SC1_BTN1_RECT_YLEN
#define TFT_SC1_BTN2_RECT_THICK TFT_SC1_BTN1_RECT_THICK
#define TFT_SC1_BTN2_RECT_CLR   TFT_SC1_BTN1_RECT_CLR



#endif
