#ifndef _SCREEN_CONTROLLER_H_
#define _SCREEN_CONTROLLER_H_

typedef enum ScreenDir {
    MAIN_SCREEN = 0
} ScreenId;

typedef struct ScreenController {
    int screen_width;
    int screen_height;
    ScreenId current_screen;
} ScreenController;


/**
 * @brief Create a screen controller struct for the given 
 * parameters.
 * 
 * @param screen_width The width of the screen.
 * @param screen_height The height of the screen.
 * @return A pointer to the created screen controller.
 */
ScreenController* create_screen_controller(int screen_width, int screen_height);

/**
 * @brief Draws the current screen as dictated by the screen
 * controller.
 * 
 * @param screen_controller The screen controller.
 * @param btn_names The names of the buttons to be displayed.
 * @param btn_count The number of buttons to be displayed.
 */
void update_screen(ScreenController* screen_controller, char** btn_names, int btn_count);

#endif // _SCREEN_CONTROLLER_H_