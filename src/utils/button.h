#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../structs/data.h"

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
    void (*select_action)(char*);

    void (*insert_action)(data*);
    void (*update_action)(data*);
    void (*remove_action)(data*);
} ButtonAction;

typedef struct Button {
    int x;
    int y;
    int width;
    int height;
    ButtonType type;
    ButtonState state;
    int activate_action; // TODO: maybe use bool here instead.
    ButtonAction action;
    char* text;
    int font_size;
} Button;


/**
 * @brief Create a select button with the default values for width, height
 * and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_default_select_button(int x, int y, char* text, void (*action)(char*));

/**
 * @brief Create an insert button with the default values for width, height
 * and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_default_insert_button(int x, int y, char* text, void (*action)(data*));

/**
 * @brief Create an update button with the default values for width, height
 * and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_default_update_button(int x, int y, char* text, void (*action)(data*));

/**
 * @brief Create a remove button with the default values for width, height
 * and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_default_remove_button(int x, int y, char* text, void (*action)(data*));

/**
 * @brief Create a select button with the given width, height and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_custom_select_button(int x, int y, int width, int height, char* text, int font_size, void (*action)(char*));

/**
 * @brief Create an insert button with the given width, height and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_custom_insert_button(int x, int y, int width, int height, char* text, int font_size, void (*action)(data*));

/**
 * @brief Create an update button with the given width, height and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_custom_update_button(int x, int y, int width, int height, char* text, int font_size, void (*action)(data*));

/**
 * @brief Create a remove button with the given width, height and font size.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @param action The action to be performed when the button is clicked.
 * @return A pointer to the created button.
 */
Button* create_custom_remove_button(int x, int y, int width, int height, char* text, int font_size, void (*action)(data*));

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