#include <raylib.h>
#include <stdlib.h>

struct Particle{
    float x;
    float y;
    int velocity_x;
    int velocity_y;
};


int main(void){

    struct Particle particle[100];

    for (int i=0; i<100; i++){
        particle[i].x = rand() % 800;
        particle[i].y = rand() % 450;
        particle[i].velocity_y = (rand() % 5) - 2;
        particle[i].velocity_x = (rand() % 5) - 2;
 
    };

    InitWindow(800, 450, "2D Particle Simulator");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i=0; i<100; i++){
        particle[i].x += particle[i].velocity_x;
        particle[i].y += particle[i].velocity_y;

        if (particle[i].x > 800 || particle[i].x < 0){
            particle[i].velocity_x = -particle[i].velocity_x;
        }
        if (particle[i].y > 450 || particle[i].y < 0){
            particle[i].velocity_y = -particle[i].velocity_y;
        }

        DrawCircle(particle[i].x,particle[i].y, 20, RED);

    }
        EndDrawing(); 
    }
    CloseWindow();
    return 0;
}