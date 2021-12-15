#ifndef __SCREEN_3_H__
#define __SCREEN_3_H__

/************************************************************\
 *                         Screen 3                         *
\************************************************************/

// Text 1
#define TFT_SC3_TXT1_TXT        "00"
#define TFT_SC3_TXT1_TXT_CLR    ILI9341_WHITE
#define TFT_SC3_TXT1_TXT_FONT   FreeSerifBold18pt7b
#define TFT_SC3_TXT1_TXT_SIZE   1
#define TFT_SC3_TXT1_TXT_X      68
#define TFT_SC3_TXT1_TXT_Y      134

// Text 2
#define TFT_SC3_TXT2_TXT        "0"
#define TFT_SC3_TXT2_TXT_CLR    ILI9341_WHITE
#define TFT_SC3_TXT2_TXT_FONT   FreeSerifBold18pt7b
#define TFT_SC3_TXT2_TXT_SIZE   1
#define TFT_SC3_TXT2_TXT_X      147
#define TFT_SC3_TXT2_TXT_Y      134

// Button 1
#define TFT_SC3_BTN1_TXT        "ADD"
#define TFT_SC3_BTN1_TXT_CLR    ILI9341_WHITE
#define TFT_SC3_BTN1_TXT_FONT   FreeSerifBold12pt7b
#define TFT_SC3_BTN1_TXT_SIZE   1
#define TFT_SC3_BTN1_TXT_X      50
#define TFT_SC3_BTN1_TXT_Y      222

#define TFT_SC3_BTN1_RECT_X     10
#define TFT_SC3_BTN1_RECT_Y     200
#define TFT_SC3_BTN1_RECT_XLEN  140
#define TFT_SC3_BTN1_RECT_YLEN  30
#define TFT_SC3_BTN1_RECT_THICK 2
#define TFT_SC3_BTN1_RECT_CLR   ILI9341_WHITE

// Button 2
#define TFT_SC3_BTN2_TXT        "BACK"
#define TFT_SC3_BTN2_TXT_CLR    TFT_SC3_BTN1_TXT_CLR
#define TFT_SC3_BTN2_TXT_FONT   TFT_SC3_BTN1_TXT_FONT
#define TFT_SC3_BTN2_TXT_SIZE   TFT_SC3_BTN1_TXT_SIZE
#define TFT_SC3_BTN2_TXT_X      212
#define TFT_SC3_BTN2_TXT_Y      TFT_SC3_BTN1_TXT_Y

#define TFT_SC3_BTN2_RECT_X     170
#define TFT_SC3_BTN2_RECT_Y     TFT_SC3_BTN1_RECT_Y
#define TFT_SC3_BTN2_RECT_XLEN  TFT_SC3_BTN1_RECT_XLEN
#define TFT_SC3_BTN2_RECT_YLEN  TFT_SC3_BTN1_RECT_YLEN
#define TFT_SC3_BTN2_RECT_THICK TFT_SC3_BTN1_RECT_THICK
#define TFT_SC3_BTN2_RECT_CLR   TFT_SC3_BTN1_RECT_CLR

// Button 3
#define TFT_SC3_BTN3_TXT        "Case Name"
#define TFT_SC3_BTN3_TXT_CLR    TFT_SC3_BTN1_TXT_CLR
#define TFT_SC3_BTN3_TXT_FONT   TFT_SC3_BTN1_TXT_FONT
#define TFT_SC3_BTN3_TXT_SIZE   TFT_SC3_BTN1_TXT_SIZE
#define TFT_SC3_BTN3_TXT_X      20
#define TFT_SC3_BTN3_TXT_Y      40

#define TFT_SC3_BTN3_RECT_X     10
#define TFT_SC3_BTN3_RECT_Y     15
#define TFT_SC3_BTN3_RECT_XLEN  225
#define TFT_SC3_BTN3_RECT_YLEN  35
#define TFT_SC3_BTN3_RECT_THICK 1
#define TFT_SC3_BTN3_RECT_CLR   TFT_SC3_BTN1_RECT_CLR

// Button 4
#define TFT_SC3_BTN4_TXT        "EDIT"
#define TFT_SC3_BTN4_TXT_CLR    TFT_SC3_BTN1_TXT_CLR
#define TFT_SC3_BTN4_TXT_FONT   TFT_SC3_BTN1_TXT_FONT
#define TFT_SC3_BTN4_TXT_SIZE   TFT_SC3_BTN1_TXT_SIZE
#define TFT_SC3_BTN4_TXT_X      246
#define TFT_SC3_BTN4_TXT_Y      39

#define TFT_SC3_BTN4_RECT_X     238
#define TFT_SC3_BTN4_RECT_Y     17
#define TFT_SC3_BTN4_RECT_XLEN  74
#define TFT_SC3_BTN4_RECT_YLEN  30
#define TFT_SC3_BTN4_RECT_THICK 1
#define TFT_SC3_BTN4_RECT_CLR   TFT_SC3_BTN1_RECT_CLR

// Button 5
#define TFT_SC3_BTN5_TXT        "TEST"
#define TFT_SC3_BTN5_TXT_CLR    TFT_SC3_BTN1_TXT_CLR
#define TFT_SC3_BTN5_TXT_FONT   TFT_SC3_BTN1_TXT_FONT
#define TFT_SC3_BTN5_TXT_SIZE   TFT_SC3_BTN1_TXT_SIZE
#define TFT_SC3_BTN5_TXT_X      246
#define TFT_SC3_BTN5_TXT_Y      39+90

#define TFT_SC3_BTN5_RECT_X     238
#define TFT_SC3_BTN5_RECT_Y     17+90
#define TFT_SC3_BTN5_RECT_XLEN  74
#define TFT_SC3_BTN5_RECT_YLEN  30
#define TFT_SC3_BTN5_RECT_THICK 1
#define TFT_SC3_BTN5_RECT_CLR   TFT_SC3_BTN1_RECT_CLR


#endif
