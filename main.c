#include <raylib.h>
#include <stdlib.h>
#include <time.h>

const int particle_count = 100;

const int WIDTH = 800;
const int HEIGHT = 450;

const int particle_rad = 10;

struct Particle{
    float x;
    float y;
    float velocity_x;
    float velocity_y;
    float gravity;
};

void update_particle(struct Particle *p){

        p->x += p->velocity_x;
        p->y += p->velocity_y;

        if (p->x > WIDTH - particle_rad || p->x < 0){
            p->velocity_x = -p->velocity_x;
        }
        if (p->y > HEIGHT - particle_rad || p->y < 0){
            p->velocity_y = -p->velocity_y;
        }
}

void setup(struct Particle *p){
        p->x = rand() % WIDTH;
        p->y = rand() % HEIGHT;
        p->velocity_y = (rand() % 5) - 2;
        p->velocity_x = (rand() % 5) - 2;
        p->gravity = 0.1;        
 
}

int main(void){
    srand(time(NULL));

    struct Particle *particle = malloc(particle_count * sizeof(struct Particle));

    if (particle== NULL){
        return 1;
    }

    for (int i=0; i<particle_count; i++){
        setup(&particle[i]);
   };

    InitWindow(WIDTH, HEIGHT, "2D Particle Simulator");

    while(!WindowShouldClose()){

        for (int i=0; i<particle_count; i++){
        update_particle(&particle[i]);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i=0; i<particle_count; i++){
        DrawCircle(particle[i].x, particle[i].y, particle_rad, RED);
        }
        EndDrawing(); 

}
    CloseWindow();
    free(particle);
    return 0;
}