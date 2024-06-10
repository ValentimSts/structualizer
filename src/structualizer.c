#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "structs/data.h"
#include "structs/hash-map/hash_map.h"
#include "structs/tree-map/tree_map.h"
#include "screens/screen.h"
#include "utils/button.h"

#include <raylib.h>

#define WINDOW_TITLE "Structualizer"
#define RES_FACTOR 80
#define RES_WIDTH 16
#define RES_HEIGHT 9
#define TARGET_FPS 60

char** get_struct_names(char* structs_dir); 

int main()
{
    InitWindow(RES_WIDTH*RES_FACTOR, RES_HEIGHT*RES_FACTOR, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);
    
    char** struct_names = get_struct_names("structs");

    int struct_count = 0;
    for (int i = 0; struct_names[i] != NULL; i++) {
        printf("%s\n", struct_names[i]);
        struct_count++;
    }

    Button** buttons = (Button**) malloc(struct_count * sizeof(Button*));
    for (int i = 0; i < struct_count; i++) {
        buttons[i] = create_button(70, 70 + 100*i, struct_names[i], 20);
    }

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 20, 20, 20, BLACK);
        for (int i = 0; i < struct_count; i++) {
            draw_button(buttons[i]);
        }
        EndDrawing();
    }

    for (int i = 0; i < struct_count; i++) {
        clear_button(buttons[i]);
    }

    for (int i = 0; struct_names[i] != NULL; i++) {
        free(struct_names[i]);
    }
    free(struct_names);
    CloseWindow();
    
    return 0;
}


// retrieve the names of all sub directories of the ../strcuts directory
// and store them in the given array
char** get_struct_names(char* structs_dir)
{
    DIR* dir = opendir(structs_dir);
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