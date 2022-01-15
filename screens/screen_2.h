#ifndef __SCREEN_2_H__
#define __SCREEN_2_H__

/************************************************************\
 *                         Screen 2                         *
\************************************************************/

// Title
#define TFT_SC2_TITLE_TXT         "CASE xxxx"
#define TFT_SC2_TITLE_TXT_CLR     ILI9341_WHITE
#define TFT_SC2_TITLE_TXT_FONT    FreeSerifBold18pt7b
#define TFT_SC2_TITLE_TXT_SIZE    1
#define TFT_SC2_TITLE_TXT_X       10
#define TFT_SC2_TITLE_TXT_Y       30

// Text 1
#define TFT_SC2_TXT1_TXT        "Time: 00.0 sec"
#define TFT_SC2_TXT1_TXT_CLR    ILI9341_WHITE
#define TFT_SC2_TXT1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC2_TXT1_TXT_SIZE   1
#define TFT_SC2_TXT1_TXT_X      20
#define TFT_SC2_TXT1_TXT_Y      65

// Text 2
#define TFT_SC2_TXT2_TXT        "Count: 000"
#define TFT_SC2_TXT2_TXT_CLR    ILI9341_WHITE
#define TFT_SC2_TXT2_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC2_TXT2_TXT_SIZE   1
#define TFT_SC2_TXT2_TXT_X      20
#define TFT_SC2_TXT2_TXT_Y      112

// Button 1
#define TFT_SC2_BTN1_TXT        "START"
#define TFT_SC2_BTN1_TXT_CLR    ILI9341_WHITE
#define TFT_SC2_BTN1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC2_BTN1_TXT_SIZE   1
#define TFT_SC2_BTN1_TXT_X      40
#define TFT_SC2_BTN1_TXT_Y      222

#define TFT_SC2_BTN1_RECT_X     10
#define TFT_SC2_BTN1_RECT_Y     200
#define TFT_SC2_BTN1_RECT_XLEN  140
#define TFT_SC2_BTN1_RECT_YLEN  30
#define TFT_SC2_BTN1_RECT_THICK 2
#define TFT_SC2_BTN1_RECT_CLR   ILI9341_WHITE

// Button 2
#define TFT_SC2_BTN2_TXT        "BACK"
#define TFT_SC2_BTN2_TXT_CLR    TFT_SC2_BTN1_TXT_CLR
#define TFT_SC2_BTN2_TXT_FONT   TFT_SC2_BTN1_TXT_FONT
#define TFT_SC2_BTN2_TXT_SIZE   TFT_SC2_BTN1_TXT_SIZE
#define TFT_SC2_BTN2_TXT_X      207
#define TFT_SC2_BTN2_TXT_Y      TFT_SC2_BTN1_TXT_Y

#define TFT_SC2_BTN2_RECT_X     170
#define TFT_SC2_BTN2_RECT_Y     TFT_SC2_BTN1_RECT_Y
#define TFT_SC2_BTN2_RECT_XLEN  TFT_SC2_BTN1_RECT_XLEN
#define TFT_SC2_BTN2_RECT_YLEN  TFT_SC2_BTN1_RECT_YLEN
#define TFT_SC2_BTN2_RECT_THICK TFT_SC2_BTN1_RECT_THICK
#define TFT_SC2_BTN2_RECT_CLR   TFT_SC2_BTN1_RECT_CLR

// Button 3
#define TFT_SC2_BTN3_TXT        "EDIT"
#define TFT_SC2_BTN3_TXT_CLR    TFT_SC2_BTN1_TXT_CLR
#define TFT_SC2_BTN3_TXT_FONT   TFT_SC2_BTN1_TXT_FONT
#define TFT_SC2_BTN3_TXT_SIZE   TFT_SC2_BTN1_TXT_SIZE
#define TFT_SC2_BTN3_TXT_X      240
#define TFT_SC2_BTN3_TXT_Y      32

#define TFT_SC2_BTN3_RECT_X     230
#define TFT_SC2_BTN3_RECT_Y     10
#define TFT_SC2_BTN3_RECT_XLEN  80
#define TFT_SC2_BTN3_RECT_YLEN  TFT_SC2_BTN1_RECT_YLEN
#define TFT_SC2_BTN3_RECT_THICK TFT_SC2_BTN1_RECT_THICK
#define TFT_SC2_BTN3_RECT_CLR   TFT_SC2_BTN1_RECT_CLR

// Button 4
#define TFT_SC2_BTN4_TXT        "-10"
#define TFT_SC2_BTN4_TXT_CLR    TFT_SC2_BTN1_TXT_CLR
#define TFT_SC2_BTN4_TXT_FONT   TFT_SC2_BTN1_TXT_FONT
#define TFT_SC2_BTN4_TXT_SIZE   TFT_SC2_BTN1_TXT_SIZE
#define TFT_SC2_BTN4_TXT_X      32
#define TFT_SC2_BTN4_TXT_Y      157

#define TFT_SC2_BTN4_RECT_X     20
#define TFT_SC2_BTN4_RECT_Y     130
#define TFT_SC2_BTN4_RECT_XLEN  60
#define TFT_SC2_BTN4_RECT_YLEN  40
#define TFT_SC2_BTN4_RECT_THICK TFT_SC2_BTN1_RECT_THICK
#define TFT_SC2_BTN4_RECT_CLR   TFT_SC2_BTN1_RECT_CLR

// Button 5
#define TFT_SC2_BTN5_TXT        "-1"
#define TFT_SC2_BTN5_TXT_CLR    TFT_SC2_BTN4_TXT_CLR
#define TFT_SC2_BTN5_TXT_FONT   TFT_SC2_BTN4_TXT_FONT
#define TFT_SC2_BTN5_TXT_SIZE   TFT_SC2_BTN4_TXT_SIZE
#define TFT_SC2_BTN5_TXT_X      110
#define TFT_SC2_BTN5_TXT_Y      TFT_SC2_BTN4_TXT_Y

#define TFT_SC2_BTN5_RECT_X     90
#define TFT_SC2_BTN5_RECT_Y     TFT_SC2_BTN4_RECT_Y
#define TFT_SC2_BTN5_RECT_XLEN  TFT_SC2_BTN4_RECT_XLEN
#define TFT_SC2_BTN5_RECT_YLEN  TFT_SC2_BTN4_RECT_YLEN
#define TFT_SC2_BTN5_RECT_THICK TFT_SC2_BTN4_RECT_THICK
#define TFT_SC2_BTN5_RECT_CLR   TFT_SC2_BTN4_RECT_CLR

// Button 6
#define TFT_SC2_BTN6_TXT        "+1"
#define TFT_SC2_BTN6_TXT_CLR    TFT_SC2_BTN4_TXT_CLR
#define TFT_SC2_BTN6_TXT_FONT   TFT_SC2_BTN4_TXT_FONT
#define TFT_SC2_BTN6_TXT_SIZE   TFT_SC2_BTN4_TXT_SIZE
#define TFT_SC2_BTN6_TXT_X      185
#define TFT_SC2_BTN6_TXT_Y      TFT_SC2_BTN4_TXT_Y

#define TFT_SC2_BTN6_RECT_X     170
#define TFT_SC2_BTN6_RECT_Y     TFT_SC2_BTN4_RECT_Y
#define TFT_SC2_BTN6_RECT_XLEN  TFT_SC2_BTN4_RECT_XLEN
#define TFT_SC2_BTN6_RECT_YLEN  TFT_SC2_BTN4_RECT_YLEN
#define TFT_SC2_BTN6_RECT_THICK TFT_SC2_BTN4_RECT_THICK
#define TFT_SC2_BTN6_RECT_CLR   TFT_SC2_BTN4_RECT_CLR

// Button 7
#define TFT_SC2_BTN7_TXT        "+10"
#define TFT_SC2_BTN7_TXT_CLR    TFT_SC2_BTN4_TXT_CLR
#define TFT_SC2_BTN7_TXT_FONT   TFT_SC2_BTN4_TXT_FONT
#define TFT_SC2_BTN7_TXT_SIZE   TFT_SC2_BTN4_TXT_SIZE
#define TFT_SC2_BTN7_TXT_X      247
#define TFT_SC2_BTN7_TXT_Y      TFT_SC2_BTN4_TXT_Y

#define TFT_SC2_BTN7_RECT_X     240
#define TFT_SC2_BTN7_RECT_Y     TFT_SC2_BTN4_RECT_Y
#define TFT_SC2_BTN7_RECT_XLEN  TFT_SC2_BTN4_RECT_XLEN
#define TFT_SC2_BTN7_RECT_YLEN  TFT_SC2_BTN4_RECT_YLEN
#define TFT_SC2_BTN7_RECT_THICK TFT_SC2_BTN4_RECT_THICK
#define TFT_SC2_BTN7_RECT_CLR   TFT_SC2_BTN4_RECT_CLR


#endif
