#include "../lib/raylib.h"
#include "../lib/raymath.h"

#define FPS (60)


int main(void) { 

    // Initialisations
    // =========================================================================
    // Init screen dimensions
    int screenWidth = 800;
    int screenHeight = 450;

    // Init ball
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    
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
            DrawText("golf", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, BLUE);
            
        EndDrawing();
    }
    // =========================================================================

    // Cleanup
    // =========================================================================
    CloseWindow();

    return 0;
}
