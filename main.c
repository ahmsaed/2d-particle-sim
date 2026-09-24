#include <raylib.h>
#include <stdlib.h>
#include <time.h>

const int particle_count = 100;

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
        p->y += p->gravity;

        if (p->x > 800 || p->x < 0){
            p->velocity_x = -p->velocity_x;
        }
        if (p->y > 450 || p->y < 0){
            p->velocity_y = -p->velocity_y;
        }
}

void setup(struct Particle *p){
        p->x = rand() % 800;
        p->y = rand() % 450;
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

    InitWindow(800, 450, "2D Particle Simulator");

    while(!WindowShouldClose()){

        for (int i=0; i<particle_count; i++){
        update_particle(&particle[i]);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i=0; i<particle_count; i++){
        DrawCircle(particle[i].x, particle[i].y, 10, RED);
        }
        EndDrawing(); 

}
    CloseWindow();
    free(particle);
    return 0;
}