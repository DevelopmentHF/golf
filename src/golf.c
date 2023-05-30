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
    Color ballColour = DARKGRAY;
    
    // Init mouse tracking vars
    Vector2 mouseStartPosition;
    Vector2 mouseCurrentPosition; 

    // Actually make the window in raylib
    InitWindow(screenWidth, screenHeight, "golf");
    SetTargetFPS(FPS);
    // =========================================================================

    // Game Loop
    // =========================================================================
    while(!WindowShouldClose()) {
        // Updates
        
        // begin drawing line control
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseStartPosition = GetMousePosition();
        } else {
            mouseCurrentPosition = GetMousePosition();
        }

        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("golf", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, ballColour);

            DrawLine(mouseStartPosition.x, mouseStartPosition.y,
                        mouseCurrentPosition.x, mouseCurrentPosition.y, BLACK);

        EndDrawing();
    }
    // =========================================================================

    // Cleanup
    // =========================================================================
    CloseWindow();

    return 0;
}
