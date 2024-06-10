#include <stdio.h>
#include <stdlib.h>

#include "structs/data.h"
#include "structs/hash-map/hash_map.h"
#include "structs/tree-map/tree_map.h"

#include <raylib.h>
#include "screens/screen.h"

#define WINDOW_TITLE "Structualizer"
#define RES_FACTOR 80
#define RES_WIDTH 16
#define RES_HEIGHT 9
#define TARGET_FPS 60

int main() {

    InitWindow(RES_WIDTH*RES_FACTOR, RES_HEIGHT*RES_FACTOR, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);
    SetExitKey(KEY_NULL);
    
    int test = 1;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 20, 20, 20, BLACK);
        EndDrawing();
        
        if (test) {
            char** names = get_struct_names("structs");
            for (int i = 0; names[i] != NULL; i++) {
                printf("%s\n", names[i]);
            }
            free(names);
            test = 0;
        }
    }

    CloseWindow();
    
    return 0;
}
