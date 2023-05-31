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
    struct ball_t {
        Vector2 position;
        Color colour;
        float velocity;
    };

    struct ball_t ball;
    ball.position.x = screenWidth/2.0;
    ball.position.y = screenHeight/2.0;
    ball.colour = DARKGRAY;
    ball.velocity = 0.0f;

    // Init mouse tracking vars
    struct line_t {
        Vector2 mouseStartPosition;
        Vector2 mouseCurrentPosition;
        int clicked;
        float magnitude;
    };

    struct line_t line;
    line.clicked = FALSE;
    line.magnitude = 0.0f;
    


    // Actually make the window in raylib
    InitWindow(screenWidth, screenHeight, "golf");
    SetTargetFPS(FPS);
    // =========================================================================

    // Game Loop
    // =========================================================================
    while(!WindowShouldClose()) {
        // Updates
        
        // calculate distance of the line
        line.magnitude = Vector2Distance(line.mouseStartPosition, 
                                             line.mouseCurrentPosition);

        // for ball physics, get magnitude of line vector and multiply this by
        // begin drawing line control
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            line.mouseStartPosition = GetMousePosition();
            ball.velocity = line.magnitude * 0.1;
            line.clicked = !line.clicked;
        } else {
            line.mouseCurrentPosition = GetMousePosition();
        }
        
        // a scaling factor to get an initial velocity for the ball
        // then for each subsequent frame decrease the velocity
        // velocity applied to the ball should be in the opposite direction to 
        // line vector
        //

        if (line.clicked == FALSE && ball.velocity > 0) {
            ball.position.x += ball.velocity;
            ball.velocity -= 5.0f;    
        } else {
            ball.velocity = 0.0f;
        }

        // Drawing
        BeginDrawing();

            ClearBackground(RAYWHITE);
            DrawText("golf", 10, 10, 20, DARKGRAY);

            DrawCircleV(ball.position, 50, ball.colour);
            
            if (line.clicked == TRUE) {
                // draw the line from initial click point to end mouse point
                DrawLine(line.mouseStartPosition.x, line.mouseStartPosition.y,
                        line.mouseCurrentPosition.x, line.mouseCurrentPosition.y, BLACK);
                DrawText(TextFormat("Line Distance: %.2f", line.magnitude),
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
