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
    particle.velocity_x = 1;
    particle.velocity_y = 1;

    InitWindow(800, 450, "2D Particle Simulator");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        particle.x += particle.velocity_x;
        particle.y += particle.velocity_y;

        if (particle.x > 800 || particle.x < 0){
            particle.velocity_x = -particle.velocity_x;
        }
        if (particle.y > 450 || particle.y < 0){
            particle.velocity_y = -particle.velocity_y;
        }

        DrawCircle(particle.x,particle.y, 20, RED);
        EndDrawing(); 
    }
    CloseWindow();
    return 0;
}