#include "../lib/raylib.h"
#include "../lib/raymath.h"

#define FPS (60)
#define TRUE (1)
#define FALSE (0)

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
    int clickingFlag = FALSE;

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
            clickingFlag = !clickingFlag;
        } else {
            mouseCurrentPosition = GetMousePosition();
        }

        // for ball physics, get magnitude of line vector and multiply this by
        // a scaling factor to get an initial velocity for the ball
        // then for each subsequent frame decrease the velocity
        // velocity applied to the ball should be in the opposite direction to 
        // line vector

        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("golf", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, ballColour);
            
            if (clickingFlag == TRUE) {
                DrawLine(mouseStartPosition.x, mouseStartPosition.y,
                        mouseCurrentPosition.x, mouseCurrentPosition.y, BLACK);

            }

        EndDrawing();
    }
    // =========================================================================

    // Cleanup
    // =========================================================================
    CloseWindow();

    return 0;
}
