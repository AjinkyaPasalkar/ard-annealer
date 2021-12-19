#ifndef __SCREEN_6_H__
#define __SCREEN_6_H__

/************************************************************\
 *                         Screen 6                         *
\************************************************************/

// Title
#define TFT_SC6_TITLE_TXT         "COMPLETE"
#define TFT_SC6_TITLE_TXT_CLR     ILI9341_GREEN
#define TFT_SC6_TITLE_TXT_FONT    FreeSerifBold18pt7b
#define TFT_SC6_TITLE_TXT_SIZE    1
#define TFT_SC6_TITLE_TXT_X       60
#define TFT_SC6_TITLE_TXT_Y       60

// Text 1
#define TFT_SC6_TXT1_TXT        "ALL CASES ANNEALED"
#define TFT_SC6_TXT1_TXT_CLR    ILI9341_WHITE
#define TFT_SC6_TXT1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC6_TXT1_TXT_X      23
#define TFT_SC6_TXT1_TXT_Y      134


// Button 1
#define TFT_SC6_BTN1_TXT        "REPEAT"
#define TFT_SC6_BTN1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC6_BTN1_TXT_X      32
#define TFT_SC6_BTN1_TXT_Y      222

#define TFT_SC6_BTN1_RECT_X     10
#define TFT_SC6_BTN1_RECT_Y     200
#define TFT_SC6_BTN1_RECT_XLEN  140
#define TFT_SC6_BTN1_RECT_YLEN  30
#define TFT_SC6_BTN1_RECT_THICK 2

#define TFT_SC6_BTN1_FILL_EN    true
#define TFT_SC6_BTN1_ROUND_EN   true

#define TFT_SC6_BTN1_TXT_CLR    ILI9341_YELLOW
#define TFT_SC6_BTN1_RECT_CLR   ILI9341_BLUE
#define TFT_SC6_BTN1_FILL_CLR   ILI9341_NAVY

// Button 2
#define TFT_SC6_BTN2_TXT        "FINISH"
#define TFT_SC6_BTN2_TXT_FONT   TFT_SC6_BTN1_TXT_FONT
#define TFT_SC6_BTN2_TXT_X      200
#define TFT_SC6_BTN2_TXT_Y      TFT_SC6_BTN1_TXT_Y

#define TFT_SC6_BTN2_RECT_X     170
#define TFT_SC6_BTN2_RECT_Y     TFT_SC6_BTN1_RECT_Y
#define TFT_SC6_BTN2_RECT_XLEN  TFT_SC6_BTN1_RECT_XLEN
#define TFT_SC6_BTN2_RECT_YLEN  TFT_SC6_BTN1_RECT_YLEN
#define TFT_SC6_BTN2_RECT_THICK TFT_SC6_BTN1_RECT_THICK

#define TFT_SC6_BTN2_FILL_EN    TFT_SC6_BTN1_FILL_EN
#define TFT_SC6_BTN2_ROUND_EN   TFT_SC6_BTN1_ROUND_EN

#define TFT_SC6_BTN2_TXT_CLR    TFT_SC6_BTN1_TXT_CLR
#define TFT_SC6_BTN2_RECT_CLR   TFT_SC6_BTN1_RECT_CLR
#define TFT_SC6_BTN2_FILL_CLR   TFT_SC6_BTN1_FILL_CLR

#endif
