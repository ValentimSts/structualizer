#include <stdlib.h>

#include "raylib.h"

#include "button.h"
#include "../styles.h"


Button* create_default_button(int x, int y, char* text, ButtonType type,
    DataStructure* btn_data_structure)
{
    Button* btn = (Button*) malloc(sizeof(Button));
    btn->x = x;
    btn->y = y;
    btn->width = DEFAULT_BTN_WIDTH;
    btn->height = DEFAULT_BTN_HEIGHT;
    btn->type = type;
    btn->state = BUTTON_IDLE;
    btn->btn_data_structure = btn_data_structure;
    btn->activate_action = false;

    ButtonAction btn_action = { 0 };
    switch (type) {
        case SELECT:
            btn_action.select_action = select_data_structure;
            break;
        
        case INSERT:
            btn_action.insert_action = insert_data_structure_data;
            break;

        case UPDATE:
            btn_action.update_action = update_data_structure_data;
            break;

        case REMOVE:
            btn_action.remove_action = clear_data_structure_data;
            break;

        default:
            break;
    }

    btn->action = btn_action;
    btn->text = text;
    btn->font_size = DEFAULT_FONT_SIZE;

    return btn;
}

Button* create_custom_button(int x, int y, int width, int height, char* text,
    int font_size, ButtonType type, DataStructure* btn_data_structure)
{
    Button* btn = (Button*) malloc(sizeof(Button));
    btn->x = x;
    btn->y = y;
    btn->width = width;
    btn->height = height;
    btn->type = type;
    btn->state = BUTTON_IDLE;
    btn->btn_data_structure = btn_data_structure;
    btn->activate_action = false;

    ButtonAction btn_action = { 0 };
    switch (type) {
        case SELECT:
            btn_action.select_action = select_data_structure;
            break;
        
        case INSERT:
            btn_action.insert_action = insert_data_structure_data;
            break;

        case UPDATE:
            btn_action.update_action = update_data_structure_data;
            break;

        case REMOVE:
            btn_action.remove_action = clear_data_structure_data;
            break;

        default:
            break;
    }

    btn->action = btn_action;
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
                btn->action.select_action(btn->btn_data_structure);
                break;
            
            case INSERT:
                btn->action.insert_action(btn->btn_data_structure);
                break;

            case UPDATE:
                btn->action.update_action(btn->btn_data_structure);
                break;

            case REMOVE:
                btn->action.remove_action(btn->btn_data_structure);
                break;

            default:
                break;
        }

        btn->activate_action = 1;
    }
}

void perform_button_action(Button* btn)
{
    btn->activate_action = 1;
}

void clear_button(Button* btn)
{
    free(btn);
}
