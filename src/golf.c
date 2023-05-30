#include "../lib/raylib.h"
#include "../lib/raymath.h"
#include <stdio.h>


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
    int speed = 0;

    // Init mouse tracking vars
    Vector2 mouseStartPosition;
    Vector2 mouseCurrentPosition;
    int clicked = FALSE;
    int drawnLineDistance = 0;
    
    // Actually make the window in raylib
    InitWindow(screenWidth, screenHeight, "golf");
    SetTargetFPS(FPS);
    // =========================================================================

    // Game Loop
    // =========================================================================
    while(!WindowShouldClose()) {
        // Updates
        
        // calculate distance of the line
        drawnLineDistance = Vector2Distance(mouseStartPosition, 
                                             mouseCurrentPosition);

        // for ball physics, get magnitude of line vector and multiply this by
        // begin drawing line control
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            mouseStartPosition = GetMousePosition();
            speed = drawnLineDistance * 0.1;
            clicked = !clicked;
        } else {
            mouseCurrentPosition = GetMousePosition();
        }
        
        // a scaling factor to get an initial velocity for the ball
        // then for each subsequent frame decrease the velocity
        // velocity applied to the ball should be in the opposite direction to 
        // line vector
        //

        if (clicked == FALSE && speed > 0) {
            ballPosition.x += speed;
            speed -= 5;    
        } else {
            speed = 0;
        }

        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("golf", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, ballColour);
            
            if (clicked == TRUE) {
                // draw the line from initial click point to end mouse point
                DrawLine(mouseStartPosition.x, mouseStartPosition.y,
                        mouseCurrentPosition.x, mouseCurrentPosition.y, BLACK);
                DrawText(TextFormat("Line Distance: %d", drawnLineDistance),
                            10, 30, 20, DARKGRAY);
            }

        EndDrawing();
    }
    // =========================================================================

    // Cleanup
    // =========================================================================
    CloseWindow();

    return 0;
}
