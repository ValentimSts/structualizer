#include <stdio.h>
#include <stdlib.h>

#include "structs/data.h"
#include "structs/hash-map/hash_map.h"
#include "structs/tree-map/tree_map.h"

#include <raylib.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib basic window");
    SetTargetFPS(60);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("It works!", 20, 20, 20, BLACK);
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}
