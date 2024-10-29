#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "../structs/data.h"
#include "../structs/data_structure.h"


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
    void (*select_action)(DataStructure*);

    void (*insert_action)(DataStructure*);
    void (*update_action)(DataStructure*);
    void (*remove_action)(DataStructure*);
} ButtonAction;

typedef struct Button {
    int x;
    int y;
    int width;
    int height;
    ButtonType type;
    ButtonState state;
    DataStructure* btn_data_structure;
    int activate_action; // TODO: maybe use bool here instead.
    ButtonAction action;
    char* text;
    int font_size;
} Button;

typedef struct SelectButton {
    Button* btn;
    void (*select_action)(DataStructure* s, int start_x, int start_y, int width, int height);
} SelectButton;

typedef struct InsertButton {
    Button* btn;
    void (*insert_action)(DataStructure*, data* d);
} InsertButton;

typedef struct UpdateButton {
    Button* btn;
    void (*update_action)(DataStructure*, data* d);
} UpdateButton;

typedef struct RemoveButton {
    Button* btn;
    void (*remove_action)(DataStructure*, data* d);
} RemoveButton;


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
    DataStructure* btn_data_structure);

SelectButton* create_default_select_button(int x, int y, char* text, DataStructure* btn_data_structure);

InsertButton* create_default_insert_button(int x, int y, char* text, DataStructure* btn_data_structure);

UpdateButton* create_default_update_button(int x, int y, char* text, DataStructure* btn_data_structure);

RemoveButton* create_default_remove_button(int x, int y, char* text, DataStructure* btn_data_structure);


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
    int font_size, ButtonType type, DataStructure* btn_data_structure);

SelectButton* create_custom_select_button(int x, int y, int width, int height, char* text,
    int font_size, DataStructure* btn_data_structure);

InsertButton* create_custom_insert_button(int x, int y, int width, int height, char* text,
    int font_size, DataStructure* btn_data_structure);

UpdateButton* create_custom_update_button(int x, int y, int width, int height, char* text,
    int font_size, DataStructure* btn_data_structure);

RemoveButton* create_custom_remove_button(int x, int y, int width, int height, char* text,
    int font_size, DataStructure* btn_data_structure);


/**
 * @brief Draws the given button on the screen.
 * 
 * @param btn The button to be drawn.
 */
void draw_button(Button* btn);

void perform_button_action(Button* btn);

/**
 * @brief Clears the button's memory.
 * 
 * @param btn The button to be cleared.
 */
void clear_button(Button* btn);

#endif // _BUTTON_H_