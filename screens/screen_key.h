#ifndef __SCREEN_KEY_H__
#define __SCREEN_KEY_H__

/************************************************************\
 *                      Screen Keyboard                     *
\************************************************************/

// Top Left button coordinates
#define TFT_SCKEY_BTN_RECT_X    15
#define TFT_SCKEY_BTN_RECT_Y    90

// Button rows and columns
#define TFT_SCKEY_BTN_ROWS      3
#define TFT_SCKEY_BTN_COLUMNS   6
#define TFT_SCKEY_BTN_GAP_X     50
#define TFT_SCKEY_BTN_GAP_Y     50

// Common button specifications
#define TFT_SCKEY_BTN_TXT_CLR       ILI9341_YELLOW
#define TFT_SCKEY_BTN_TXT_FONT      FreeSerifBold12pt7b
#define TFT_SCKEY_BTN_TXT_X_OFFSET  13
#define TFT_SCKEY_BTN_TXT_Y_OFFSET  27

#define TFT_SCKEY_BTN_RECT_THICK    1
#define TFT_SCKEY_BTN_FILL_EN       true
#define TFT_SCKEY_BTN_ROUND_EN      true
#define TFT_SCKEY_BTN_RECT_CLR      ILI9341_BLUE
#define TFT_SCKEY_BTN_FILL_CLR      ILI9341_NAVY

// Button 1
#define TFT_SCKEY_BTN1_RECT_XLEN    40
#define TFT_SCKEY_BTN1_RECT_YLEN    40

// Button 2
#define TFT_SCKEY_BTN2_RECT_XLEN    90
#define TFT_SCKEY_BTN2_RECT_YLEN    40

// Button 3 right arrow
#define TFT_SCKEY_BTN3_ARROW_X      285
#define TFT_SCKEY_BTN3_ARROW_Y      210
#define TFT_SCKEY_BTN3_ARROW_DIR    2
#define TFT_SCKEY_BTN3_ARROW_CLR    ILI9341_YELLOW

// Button 4 left arrow
#define TFT_SCKEY_BTN4_ARROW_X      35
#define TFT_SCKEY_BTN4_ARROW_Y      TFT_SCKEY_BTN3_ARROW_Y
#define TFT_SCKEY_BTN4_ARROW_DIR    3
#define TFT_SCKEY_BTN4_ARROW_CLR    ILI9341_YELLOW

// Button 5 Space
#define TFT_SCKEY_BTN5_TXT          "SPACE"
#define TFT_SCKEY_BTN5_TXT_X        (TFT_SCKEY_BTN_RECT_X + (1 * TFT_SCKEY_BTN_GAP_X)) + 5
#define TFT_SCKEY_BTN5_TXT_Y        (TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y)) + 27
#define TFT_SCKEY_BTN5_RECT_X       (TFT_SCKEY_BTN_RECT_X + (1 * TFT_SCKEY_BTN_GAP_X))
#define TFT_SCKEY_BTN5_RECT_Y       (TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y))
#define TFT_SCKEY_BTN5_RECT_XLEN    TFT_SCKEY_BTN2_RECT_XLEN
#define TFT_SCKEY_BTN5_RECT_YLEN    TFT_SCKEY_BTN2_RECT_YLEN

// Button 6 Clear
#define TFT_SCKEY_BTN6_TXT          "CLEAR"
#define TFT_SCKEY_BTN6_TXT_X        (TFT_SCKEY_BTN_RECT_X + (3 * TFT_SCKEY_BTN_GAP_X)) + 3
#define TFT_SCKEY_BTN6_TXT_Y        (TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y)) + 27
#define TFT_SCKEY_BTN6_RECT_X       (TFT_SCKEY_BTN_RECT_X + (3 * TFT_SCKEY_BTN_GAP_X))
#define TFT_SCKEY_BTN6_RECT_Y       (TFT_SCKEY_BTN_RECT_Y + (2 * TFT_SCKEY_BTN_GAP_Y))
#define TFT_SCKEY_BTN6_RECT_XLEN    TFT_SCKEY_BTN2_RECT_XLEN
#define TFT_SCKEY_BTN6_RECT_YLEN    TFT_SCKEY_BTN2_RECT_YLEN

// Button 7 OK
#define TFT_SCKEY_BTN7_TXT          "OK"
#define TFT_SCKEY_BTN7_TXT_FONT     TFT_SCKEY_BTN_TXT_FONT
#define TFT_SCKEY_BTN7_TXT_X        TFT_SCKEY_BTN7_RECT_X + 10
#define TFT_SCKEY_BTN7_TXT_Y        TFT_SCKEY_BTN7_RECT_Y + 27

#define TFT_SCKEY_BTN7_RECT_X       240
#define TFT_SCKEY_BTN7_RECT_Y       20
#define TFT_SCKEY_BTN7_RECT_XLEN    60
#define TFT_SCKEY_BTN7_RECT_YLEN    40
#define TFT_SCKEY_BTN7_RECT_THICK   TFT_SCKEY_BTN_RECT_THICK
#define TFT_SCKEY_BTN7_ROUND_EN     TFT_SCKEY_BTN_ROUND_EN

#define TFT_SCKEY_BTN7_FILL_EN      TFT_SCKEY_BTN_FILL_EN

#define TFT_SCKEY_BTN7_TXT_CLR      TFT_SCKEY_BTN_TXT_CLR
#define TFT_SCKEY_BTN7_RECT_CLR     TFT_SCKEY_BTN_RECT_CLR
#define TFT_SCKEY_BTN7_FILL_CLR     TFT_SCKEY_BTN_FILL_CLR

// Text 1 Input box
#define TFT_SCKEY_TXT1_TXT          "Enter Case Name"
#define TFT_SCKEY_TXT1_TXT_FONT     TFT_SCKEY_BTN_TXT_FONT
#define TFT_SCKEY_TXT1_TXT_X        TFT_SCKEY_TXT1_RECT_X + 10
#define TFT_SCKEY_TXT1_TXT_Y        TFT_SCKEY_TXT1_RECT_Y + 27

#define TFT_SCKEY_TXT1_RECT_X       10
#define TFT_SCKEY_TXT1_RECT_Y       20
#define TFT_SCKEY_TXT1_RECT_XLEN    220
#define TFT_SCKEY_TXT1_RECT_YLEN    40
#define TFT_SCKEY_TXT1_RECT_THICK   TFT_SCKEY_BTN_RECT_THICK
#define TFT_SCKEY_TXT1_ROUND_EN     TFT_SCKEY_BTN_ROUND_EN

#define TFT_SCKEY_TXT1_FILL_EN      false

#define TFT_SCKEY_TXT1_TXT_CLR      TFT_SCKEY_BTN_TXT_CLR
#define TFT_SCKEY_TXT1_RECT_CLR     TFT_SCKEY_BTN_RECT_CLR
#define TFT_SCKEY_TXT1_FILL_CLR     TFT_SCKEY_BTN_FILL_CLR


#endif
