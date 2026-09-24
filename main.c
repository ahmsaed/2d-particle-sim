#include <raylib.h>

struct Particle{
    float x;
    float y;
    int velocity_x;
    int velocity_y;
};


int main(void){

    struct Particle particle[3];

    for (int i=0; i<3; i++){
        if (i == 1){
            particle[i].x = 200;
            particle[i].y = 100;
            particle[i].velocity_y = 2;
            particle[i].velocity_x = 2;
        }
        if (i==2){
        particle[i].x = 280;
        particle[i].y = 140;
        particle[i].velocity_x = 1;
        particle[i].velocity_y = -2;
        }
        if (i==0){
        particle[i].x = 400;
        particle[i].y = 200;
        particle[i].velocity_x = 2;
        particle[i].velocity_y = 1;
        }
    };

    InitWindow(800, 450, "2D Particle Simulator");

    while(!WindowShouldClose()){

        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i=0; i<3; i++){
        particle[i].x += particle[i].velocity_x;
        particle[i].y += particle[i].velocity_y;

        if (particle[i].x > 800 || particle[i].x < 0){
            particle[i].velocity_x = -particle[i].velocity_x;
        }
        if (particle[i].y > 450 || particle[i].y < 0){
            particle[i].velocity_y = -particle[i].velocity_y;
        }

        DrawCircle(particle[i].x,particle[i].y, 20, RED);

        DrawCircle(particle[i].x,particle[i].y, 20, RED);
        DrawCircle(particle[i].x,particle[i].y, 20, RED);
    }
        EndDrawing(); 
    }
    CloseWindow();
    return 0;
}