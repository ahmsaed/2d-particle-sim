#include <raylib.h>

struct Particle{
    float x;
    float y;
    int velocity_x;
    int velocity_y;
};


int main(void){

    struct Particle particle;

    particle.x = 400;
    particle.y = 200;
    particle.velocity_x = 2;
    particle.velocity_y = -2;

    InitWindow(800, 450, "2D Particle Simulator");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircle(particle.x,particle.y, 20, RED);
        EndDrawing(); 
    }
    CloseWindow();
    return 0;
}