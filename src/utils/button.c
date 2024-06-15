#include <stdlib.h>

#include "raylib.h"

#include "button.h"
#include "../styles.h"


static Button* create_default_button(int x, int y, char* text, ButtonType type,
    ButtonAction action);

static Button* create_custom_button(int x, int y, int width, int height, char* text,
    int font_size, ButtonType type, ButtonAction action);


Button* create_default_select_button(int x, int y, char* text, void (*action)(char*))
{
    ButtonAction btn_action = { 0 };
    btn_action.select_action = action;

    return create_default_button(x, y, text, SELECT, btn_action);

}

Button* create_default_insert_button(int x, int y, char* text, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.insert_action = action;

    return create_default_button(x, y, text, INSERT, btn_action);
}

Button* create_default_update_button(int x, int y, char* text, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.update_action = action;

    return create_default_button(x, y, text, UPDATE, btn_action);
}

Button* create_default_remove_button(int x, int y, char* text, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.remove_action = action;

    return create_default_button(x, y, text, REMOVE, btn_action);
}

Button* create_custom_select_button(int x, int y, int width, int height, char* text,
    int font_size, void (*action)(char*))
{
    ButtonAction btn_action = { 0 };
    btn_action.select_action = action;

    return create_custom_button(x, y, width, height, text, font_size, SELECT, btn_action);
}

Button* create_custom_insert_button(int x, int y, int width, int height, char* text,
    int font_size, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.insert_action = action;

    return create_custom_button(x, y, width, height, text, font_size, INSERT, btn_action);
}

Button* create_custom_update_button(int x, int y, int width, int height, char* text,
    int font_size, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.update_action = action;

    return create_custom_button(x, y, width, height, text, font_size, UPDATE, btn_action);
}

Button* create_custom_remove_button(int x, int y, int width, int height, char* text,
    int font_size, void (*action)(data*))
{
    ButtonAction btn_action = { 0 };
    btn_action.remove_action = action;

    return create_custom_button(x, y, width, height, text, font_size, REMOVE, btn_action);
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

    Color color = BTN_IDLE_COLOR;
    switch (btn->state) {
        case BUTTON_IDLE:
            color = BTN_IDLE_COLOR;
            break;

        case BUTTON_HOVER:
            color = BTN_HOVER_COLOR;
            break;

        case BUTTON_PRESSED:
            color = BTN_PRESSED_COLOR;
            break;
    }

    Vector2 text_measures = MeasureTextEx(GetFontDefault(), btn->text, btn->font_size, 1);
    int pos_text_x = btn->x + (btn->width - text_measures.x) / 2;
    int pos_text_y = btn->y + (btn->height - text_measures.y) / 2;

    DrawRectangle(btn->x, btn->y, btn->width, btn->height, color);
    DrawText(btn->text, pos_text_x, pos_text_y, btn->font_size, PRIMARY_TEXT_COLOR);

    if (btn->activate_action) {
        switch (btn->type) {
            case SELECT:
                btn->action.select_action(btn->text);
                break;
            
            case INSERT:
                // TODO: implement.
                break;

            case UPDATE:
                // TODO: implement.
                break;

            case REMOVE:
                // TODO: implement.
                break;

            default:
                break;
        }

        btn->activate_action = 0;
    }
}

void clear_button(Button* btn)
{
    free(btn);
}

/**
 * @brief Create a button struct with the default width, height and
 * font size values, and the given parameters.
 * The default width, height and font size values are DEFAULT_BTN_WIDTH,
 * DEFAULT_BTN_HEIGHT and DEFAULT_FONT_SIZE respectively.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @return A pointer to the created button.
 */
static Button* create_default_button(int x, int y, char* text, ButtonType type,
    ButtonAction action)
{
    Button* btn = (Button*) malloc(sizeof(Button));
    btn->x = x;
    btn->y = y;
    btn->width = DEFAULT_BTN_WIDTH;
    btn->height = DEFAULT_BTN_HEIGHT;
    btn->type = type;
    btn->state = BUTTON_IDLE;
    btn->activate_action = false;
    btn->action = action;
    btn->text = text;
    btn->font_size = DEFAULT_FONT_SIZE;

    return btn;
}

/**
 * @brief Create a button struct with a custom width and height values,
 * and the given parameters.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param width The width of the button.
 * @param height The height of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @return A pointer to the created button.
 */
static Button* create_custom_button(int x, int y, int width, int height, char* text,
    int font_size, ButtonType type, ButtonAction action)
{
    Button* btn = (Button*) malloc(sizeof(Button));
    btn->x = x;
    btn->y = y;
    btn->width = width;
    btn->height = height;
    btn->type = type;
    btn->state = BUTTON_IDLE;
    btn->activate_action = false;
    btn->action = action;
    btn->text = text;
    btn->font_size = font_size;

    return btn;
}