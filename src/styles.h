/*********************************************************
* 
*  This header file stores all the styling related info 
*  used throughout the application, from colors to fonts
*  and measures.
*
*  All the color names were taken from the Coolors website:
*   - https://coolors.co/
*
**********************************************************/

#ifndef _STYLES_H_
#define _STYLES_H_

#include "raylib.h"


// ------------------------------------------------------
// Main Styles
// ------------------------------------------------------

// The main colors of the application were chosen to
// follow a 60-30-10 rule.

#define PRIMARY_COLOR (Color){ 221, 225, 228, 255 } // Platinum
#define SECONDARY_COLOR (Color){ 255, 130, 0, 255 } // Safety Orange
#define ACCENT_COLOR (Color){ 30, 95, 180, 255 }    // Denim

#define PRIMARY_TEXT_COLOR (Color){ 0, 0, 0, 255 }             // Black
#define SECONDARY_TEXT_COLOR (Color){ 0x00, 0x00, 0x00, 0xFF } // Black
#define ACCENT_TEXT_COLOR (Color){ 0xFF, 0xFF, 0xFF, 0xFF }    // White

#define DEFAULT_FONT_SIZE 20

// ------------------------------------------------------


// ------------------------------------------------------
// Button Styles
// ------------------------------------------------------

#define BTN_IDLE_COLOR SECONDARY_COLOR                // Safety Orange
#define BTN_HOVER_COLOR (Color){ 238, 174, 114, 255 } // Fawn
#define BTN_PRESSED_COLOR (Color){ 95, 85, 75, 255 }  // Walnut Brown

#define DEFAULT_BTN_WIDTH 150
#define DEFAULT_BTN_HEIGHT 50
#define DEFAULT_BTN_SPACING 10

// ------------------------------------------------------

#endif // _STYLES_H_