#ifndef _BUTTON_H_
#define _BUTTON_H_


#define DEFAULT_BTN_WIDTH 150
#define DEFAULT_BTN_HEIGHT 50


typedef enum ButtonState {
    BUTTON_IDLE = 0,
    BUTTON_HOVER = 1,
    BUTTON_PRESSED = 2
} ButtonState;

typedef struct Button {
    int x;
    int y;
    int width;
    int height;
    int activate_action;
    // TODO: create a button action callback
    ButtonState state;
    char* text;
    int font_size;
} Button;


/**
 * @brief Create a button struct with the default width and height
 * values, and the given parameters.
 * The default width and height values are DEFAULT_BTN_WIDTH and
 * DEFAULT_BTN_HEIGHT respectively.
 * 
 * @param x The x position of the button.
 * @param y The y position of the button.
 * @param text The text to be displayed on the button.
 * @param font_size The font size of the text.
 * @return A pointer to the created button.
 */
Button* create_default_button(int x, int y, char* text, int font_size);

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
Button* create_custom_button(int x, int y, int width, int height, char* text, int font_size);

/**
 * @brief Draws the given button on the screen.
 * 
 * @param btn The button to be drawn.
 */
void draw_button(Button* btn);

/**
 * @brief Draws all the buttons in the given array
 * on the screen.
 * 
 * @param btns The array of buttons to be drawn.
 * @param size The size of the array.
 */
void draw_buttons(Button** btns, int size);

/**
 * @brief Clears the button's memory.
 * 
 * @param btn The button to be cleared.
 */
void clear_button(Button* btn);

/**
 * @brief Clears all the given array buttons' memory.
 * 
 * @param btns The array of buttons to be cleared.
 * @param size The size of the array.
 */
void clear_buttons(Button** btns, int size);

#endif // _BUTTON_H_