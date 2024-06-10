#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <raylib.h>

#include "main_screen.h"
#include "../../utils/button.h"

#define BTN_PADDING 10


static void draw_default_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height, char** btn_names, int btn_count);
static void draw_custom_buttons(int start_x, int start_y, int btn_section_width, int btn_section_height, int btn_width, int btn_height, char** btn_names, int btn_count);


void update_main_screen(ScreenController* screen_controller, char** btn_names, int btn_count)
{
    ClearBackground(RAYWHITE);
    int width = (screen_controller->screen_width/2) - 10;
    int height = screen_controller->screen_height - 10;

    draw_default_buttons(10, 10, width, height, btn_names, btn_count);
    draw_custom_buttons(width + 10, 10, width, height, 500, 75, btn_names, btn_count);
}


static void draw_default_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height, char** btn_names, int btn_count)
{   
    int curr_btn_section_width = 0;
    int curr_btn_section_height = 0;

    int next_btn_x = start_x;
    int next_btn_y = start_y;

    for (int i = 0; i < btn_count; i++) {
        // Determine the width and height of the button based
        // on the maximum width and height defined for the section.
        if (curr_btn_section_height >= max_btn_section_height) {
            curr_btn_section_height = 0;
            curr_btn_section_width += BTN_PADDING + DEFAULT_BTN_WIDTH;
        }

        curr_btn_section_height += BTN_PADDING + DEFAULT_BTN_HEIGHT;

        if (curr_btn_section_width >= max_btn_section_width) {
            break;
        }

        Button* btn = create_default_button(next_btn_x, next_btn_y, btn_names[i], 20);
        draw_button(btn);
        clear_button(btn);

        next_btn_x = start_x + curr_btn_section_width;
        next_btn_y = start_y + curr_btn_section_height;
    }
}

static void draw_custom_buttons(int start_x, int start_y, int max_btn_section_width, int max_btn_section_height, int btn_width, int btn_height, char** btn_names, int btn_count)
{
    int curr_btn_section_width = 0;
    int curr_btn_section_height = 0;

    int next_btn_x = start_x;
    int next_btn_y = start_y;

    for (int i = 0; i < btn_count; i++) {
        // Determine the width and height of the button based
        // on the maximum width and height defined for the section.
        if (curr_btn_section_height >= max_btn_section_height) {
            curr_btn_section_height = 0;
            curr_btn_section_width += BTN_PADDING + btn_width;
        }

        curr_btn_section_height += BTN_PADDING + btn_height;

        if (curr_btn_section_width >= max_btn_section_width) {
            break;
        }

        Button* btn = create_custom_button(next_btn_x, next_btn_y, btn_width, btn_height, btn_names[i], 20);
        draw_button(btn);
        clear_button(btn);

        next_btn_x = start_x + curr_btn_section_width;
        next_btn_y = start_y + curr_btn_section_height;
    }
    
}
