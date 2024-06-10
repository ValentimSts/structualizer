#include <stdlib.h>
#include <raylib.h>

#include "button.h"

#define BTN_TEXT_PADDING 5

Button* create_button(int x, int y, char* text, int font_size)
{
    Button* btn = (Button*) malloc(sizeof(Button));
    btn->x = x;
    btn->y = y;
    btn->width = DEFAULT_BTN_WIDTH;
    btn->height = DEFAULT_BTN_HEIGHT;
    btn->activate_action = false;
    btn->state = BUTTON_IDLE;
    btn->text = text;
    btn->font_size = font_size;

    return btn;
}


void draw_button(Button* btn)
{
    Vector2 mouse_point = GetMousePosition();
    Rectangle btn_bounds = { btn->x, btn->y, btn->width, btn->height };

    // Check button state
    if (CheckCollisionPointRec(mouse_point, btn_bounds)) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            btn->state = BUTTON_PRESSED;
        }
        else {
            btn->state = BUTTON_HOVER;
        }

        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            btn->activate_action = 1;
        }
    }
    else {
        btn->state = BUTTON_IDLE;
    }

    Color color = LIGHTGRAY;
    switch (btn->state) {
        case BUTTON_IDLE:
            color = LIGHTGRAY;
            break;

        case BUTTON_HOVER:
            color = GRAY;
            break;

        case BUTTON_PRESSED:
            color = DARKGRAY;
            break;
    }

    DrawRectangle(btn->x, btn->y, btn->width, btn->height, color);
    DrawText(btn->text, btn->x + BTN_TEXT_PADDING, btn->y + BTN_TEXT_PADDING, 20, BLACK);

    if (btn->activate_action) {
        // TODO: call the button callback
    }
}


void clear_button(Button* btn)
{
    free(btn->text);
    free(btn);
}