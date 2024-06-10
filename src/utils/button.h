#ifndef _BUTTON_H_
#define _BUTTON_H_

#define DEFAULT_BTN_WIDTH 100
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

Button* create_button(int x, int y, char* text, int font_size);
void draw_button(Button* btn);
void clear_button(Button* btn);

#endif // _BUTTON_H_