#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../structs/data.h"
#include "../structs/struct.h"


typedef enum ButtonType {
    SELECT = 0,
    INSERT = 1,
    UPDATE = 2,
    REMOVE = 3
} ButtonType;

typedef enum ButtonState {
    BUTTON_IDLE = 0,
    BUTTON_HOVER = 1,
    BUTTON_PRESSED = 2
} ButtonState;

typedef struct ButtonAction {
    void (*select_action)(Struct*);

    void (*insert_action)(Struct*);
    void (*update_action)(Struct*);
    void (*remove_action)(Struct*);
} ButtonAction;

typedef struct Button {
    int x;
    int y;
    int width;
    int height;
    ButtonType type;
    ButtonState state;
    Struct* btn_struct;
    int activate_action; // TODO: maybe use bool here instead.
    ButtonAction action;
    char* text;
    int font_size;
} Button;


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
Button* create_default_button(int x, int y, char* text, ButtonType type,
    Struct* btn_struct);

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
Button* create_custom_button(int x, int y, int width, int height, char* text,
    int font_size, ButtonType type, Struct* btn_struct);

/**
 * @brief Draws the given button on the screen.
 * 
 * @param btn The button to be drawn.
 */
void draw_button(Button* btn);

/**
 * @brief Clears the button's memory.
 * 
 * @param btn The button to be cleared.
 */
void clear_button(Button* btn);

#endif // _BUTTON_H_