#include <stdio.h>
#include <stdlib.h>

#include "screen_controller.h"
#include "main-screen/main_screen.h"


ScreenController* create_screen_controller(int screen_width, int screen_height)
{
    ScreenController* screen_controller = (ScreenController*) malloc(sizeof(ScreenController));

    screen_controller->screen_width = screen_width;
    screen_controller->screen_height = screen_height;
    screen_controller->current_screen = MAIN_SCREEN;

    return screen_controller;
}

void update_screen(ScreenController* screen_controller, DataStructure** data_structures, int data_structure_count)
{
    switch (screen_controller->current_screen) {
        case MAIN_SCREEN:
            update_main_screen(screen_controller, data_structures, data_structure_count);
            break;
    }
}
