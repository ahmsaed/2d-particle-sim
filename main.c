#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "Particle Simulator");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircle(400, 225, 20, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}