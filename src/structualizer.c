#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "raylib.h"

#include "styles.h"
#include "screens/screen_controller.h"
#include "structs/data_structure.h"

// TODO: this function should be moved elsewhere.
static char** get_available_struct_names(char* data_structures_dir); 

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);

    char** struct_names = get_available_struct_names("structs");

    int struct_count = 0;
    for (int i = 0; struct_names[i] != NULL; i++) {
        struct_count++;
    }

    DataStructure** data_structures = create_data_structures(struct_names, &struct_count);
    ScreenController* screen_controller = create_screen_controller(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (!WindowShouldClose()) {
        BeginDrawing();
        update_screen(screen_controller, data_structures, struct_count);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}


/**
 * @brief Retrieves the names of all sub-directories of the given
 * directory.
 * 
 * @param dir The path to the parent directory.
 * @return A char* list of the names of all found sub-directories.
 */
static char** get_available_struct_names(char* dir_name)
{
    DIR* dir = opendir(dir_name);
    if (dir == NULL) return NULL;

    int starting_size = 5;
    char** names = (char**) malloc(starting_size * sizeof(char*));
    for (int i = 0; i < starting_size; i++) {
        names[i] = NULL;
    }
    int struct_count = 0;

    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if (struct_count == starting_size) {
            starting_size *= 2;
            names = (char**) realloc(names, starting_size * sizeof(char*));
            for (int i = struct_count; i < starting_size; i++) {
                names[i] = NULL;
            }
        }

        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            names[struct_count] = (char*) malloc(strlen(entry->d_name) + 1);
            if (names[struct_count] == NULL) return NULL;
            strcpy(names[struct_count], entry->d_name);
            struct_count++;
        }
    }

    closedir(dir);

    return names;
}