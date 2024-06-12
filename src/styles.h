/*********************************************************
* 
*  This header file stores all the styling related info 
*  used throughout the application, from colors to fonts
*  and measures.
*
*  All the color names were taken from the Coolors website:
*   - https://coolors.co/
*
*  Most, if not all, of the colors used in this application
*  chosen to follow the 60-30-10 rule.
*
**********************************************************/

#ifndef _STYLES_H_
#define _STYLES_H_

#include "raylib.h"


// ------------------------------------------------------
// Main Application Styles
// ------------------------------------------------------

#define WINDOW_TITLE "Structualizer"
#define RES_FACTOR 80
#define RES_WIDTH 16
#define RES_HEIGHT 9
#define WINDOW_WIDTH RES_WIDTH*RES_FACTOR
#define WINDOW_HEIGHT RES_HEIGHT*RES_FACTOR
#define TARGET_FPS 60

#define PRIMARY_COLOR (Color){ 221, 225, 228, 255 } // Platinum
#define SECONDARY_COLOR (Color){ 255, 130, 0, 255 } // Safety Orange
#define ACCENT_COLOR (Color){ 30, 95, 180, 255 }    // Denim

#define PRIMARY_TEXT_COLOR (Color){ 0, 0, 0, 255 }             // Black
#define SECONDARY_TEXT_COLOR (Color){ 0x00, 0x00, 0x00, 0xFF } // Black
#define ACCENT_TEXT_COLOR (Color){ 0xFF, 0xFF, 0xFF, 0xFF }    // White

#define SMALL_FONT_SIZE 10
#define MEDIUM_FONT_SIZE 20
#define LARGE_FONT_SIZE 30
#define DEFAULT_FONT_SIZE MEDIUM_FONT_SIZE

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