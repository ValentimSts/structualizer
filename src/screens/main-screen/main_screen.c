#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"

#include "main_screen.h"
#include "../../utils/button.h"
#include "../../styles.h"

#define BTN_PADDING 10

typedef enum Orientation {
    HORIZONTAL = 0,
    VERTICAL = 1
} Orientation;


static void draw_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height,
    int btn_width, int btn_height, int btn_spacing, char** btn_names, int btn_count,
    Orientation orientation);

static void draw_default_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height,
    char** btn_names, int btn_count, Orientation orientation);

static void draw_custom_buttons(int start_x, int start_y, int btn_section_width, int btn_section_height,
    int btn_width, int btn_height, int btn_spacing, char** btn_names, int btn_count,
    Orientation orientation);

void test_action();

void update_main_screen(ScreenController* screen_controller, char** btn_names, int btn_count)
{
    ClearBackground(PRIMARY_COLOR);
    
    int section_width = screen_controller->screen_width / 2;
    int section_height = screen_controller->screen_height;

    draw_default_buttons(10, 10, section_width - 20, section_height - 20, btn_names, btn_count, VERTICAL);
    draw_custom_buttons(section_width + 10, 10, section_width - 20, section_height - 20, 250, 75, 10, btn_names, btn_count, VERTICAL);
}


/**
 * @brief Draws buttons within a section of the screen with default width,
 * height and spacing values. Some buttons may not be drawn if they
 * exceed the maximum width or height defined for the section.
 * 
 * @param start_x The x position of the top-left corner of the section.
 * @param start_y The y position of the top-left corner of the section.
 * @param max_btn_section_width The maximum width of the section.
 * @param max_btn_section_height The maximum height of the section.
 * @param btn_names The names of the buttons to be drawn.
 * @param btn_count The number of buttons to be drawn.
 * @param orientation The orientation of the buttons (HORIZONTAL or VERTICAL).
 */
static void draw_default_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height,
    char** btn_names, int btn_count, Orientation orientation)
{   
    draw_buttons(start_x, start_y, max_btn_section_width, max_btn_section_height,
        DEFAULT_BTN_WIDTH, DEFAULT_BTN_HEIGHT, DEFAULT_BTN_SPACING,
        btn_names, btn_count, orientation);
}

/**
 * @brief Draws buttons within a section of the screen with custom width, height
 * and spacing values. Some buttons, may not be drawn if they exceed the maximum
 * width or height defined for the section.
 * 
 * @param start_x The x position of the top-left corner of the section.
 * @param start_y The y position of the top-left corner of the section.
 * @param max_btn_section_width The maximum width of the section.
 * @param max_btn_section_height The maximum height of the section.
 * @param btn_width The width of the buttons to be drawn.
 * @param btn_height The height of the buttons to be drawn.
 * @param btn_spacing The spacing between the buttons.
 * @param btn_names The names of the buttons to be drawn.
 * @param btn_count The number of buttons to be drawn.
 * @param orientation The orientation of the buttons (HORIZONTAL or VERTICAL).
 */
static void draw_custom_buttons( int start_x, int start_y, int max_btn_section_width, int max_btn_section_height,
    int btn_width, int btn_height, int btn_spacing, char** btn_names, int btn_count, Orientation orientation)
{
    draw_buttons(start_x, start_y, max_btn_section_width, max_btn_section_height,
        btn_width, btn_height, btn_spacing, btn_names, btn_count, orientation);
}

/**
 * @brief Draws buttons within a section of the screen with the given parameters.
 * Some buttons may not be drawn if they exceed the maximum width or height defined
 * for the section.
 * 
 * @param start_x The x position of the top-left corner of the section.
 * @param start_y The y position of the top-left corner of the section.
 * @param max_btn_section_width The maximum width of the section.
 * @param max_btn_section_height The maximum height of the section.
 * @param btn_width The width of the buttons to be drawn.
 * @param btn_height The height of the buttons to be drawn.
 * @param btn_spacing The spacing between the buttons.
 * @param btn_names The names of the buttons to be drawn.
 * @param btn_count The number of buttons to be drawn.
 * @param orientation The orientation of the buttons (HORIZONTAL or VERTICAL).
 */
static void draw_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height,
    int btn_width, int btn_height, int btn_spacing, char** btn_names, int btn_count,
    Orientation orientation)
{
    // Don't draw any buttons if the width or height of the buttons
    // exceed the maximum values defined for the button section.
    if (btn_width > max_btn_section_width ||
        btn_height > max_btn_section_height) {
        // It may happen that this way the button will leave no 
        // room for spacing between it and the edge of the section,
        // but that's better than no button at all. 
        return;
    }

    int width_increment = btn_spacing + btn_width;
    int height_increment = btn_spacing + btn_height;

    int curr_btn_section_width = 0;
    int curr_btn_section_height = 0;

    int next_btn_x = start_x;
    int next_btn_y = start_y;

    for (int i = 0; i < btn_count; i++) {        
        if (orientation == HORIZONTAL) {
            next_btn_x = start_x + curr_btn_section_width;

            // If the height limit for this section is reached, no 
            // more buttons can be drawn in it.
            if (curr_btn_section_height > max_btn_section_height) {
                break;
            }

            curr_btn_section_width += width_increment;

            // Adjust the position of the next button to be drawn in
            // case the width limit is reached. Essentially drawing
            // the button on the next "column".
            if (curr_btn_section_width > max_btn_section_width) {
                curr_btn_section_width = 0;
                curr_btn_section_height += height_increment;

                next_btn_x = start_x;
                next_btn_y = start_y + curr_btn_section_height;
            }
        }
        else {
            next_btn_y = start_y + curr_btn_section_height;
            
            // If the width limit for this section is reached, no 
            // more buttons can be drawn in it.
            if (curr_btn_section_width >= max_btn_section_width) {
                break;
            }

            curr_btn_section_height += height_increment;

            // Adjust the position of the next button to be drawn in
            // case the height limit is reached. Essentially drawing
            // the button on the next "column".
            if (curr_btn_section_height >= max_btn_section_height) {
                curr_btn_section_height = 0;
                curr_btn_section_width += width_increment;
                
                next_btn_x = start_x + curr_btn_section_width;
                next_btn_y = start_y;
            }
        }

        Button* btn = create_custom_button(next_btn_x, next_btn_y,
            btn_width, btn_height, btn_names[i], 20, test_action);
        draw_button(btn);
        clear_button(btn);
    }
}


void test_action(char* btn_name)
{
    printf("Button pressed: %s\n", btn_name);
}