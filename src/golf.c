#include "../lib/raylib.h"
#include "../lib/raymath.h"

#define FPS (60)


int main(void) { 

    // Initialisations
    // =========================================================================
    // Init screen dimensions
    int screenWidth = 800;
    int screenHeight = 450;
    
    // Actually make the window in raylib
    InitWindow(screenWidth, screenHeight, "golf");
    SetTargetFPS(FPS);
    // =========================================================================

    // Game Loop
    // =========================================================================
    while(!WindowShouldClose()) {
        // Updates
        
        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("golf", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }
    // =========================================================================

    // Cleanup
    // =========================================================================
    CloseWindow();

    return 0;
}
