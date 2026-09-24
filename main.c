#include <raylib.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int particle_count = 10;

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

        if (p->x > WIDTH - particle_rad || p->x < particle_rad){
            p->velocity_x = -p->velocity_x;
        }
        if (p->y > HEIGHT - particle_rad || p->y < particle_rad){
            p->velocity_y = -p->velocity_y;
        }
}

void setup(struct Particle *p){
        p->x = rand() % WIDTH;
        p->y = rand() % HEIGHT;
        p->velocity_x = (float)rand() / RAND_MAX;
        p->velocity_y = (float)rand() / RAND_MAX;
}


int main(void){
    srand(time(NULL));

    struct Particle *particle = malloc(particle_count * sizeof(struct Particle));
    struct Particle *new_part = realloc(particle, 100 * sizeof(struct Particle));

    if (new_part== NULL){
        return 1;
    }

    for (int i=0; i<particle_count; i++){
        setup(&new_part[i]);
   };

    InitWindow(WIDTH, HEIGHT, "2D Particle Simulator");

    while(!WindowShouldClose()){
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            Vector2 mouse_pos = GetMousePosition();
            new_part[particle_count].x = mouse_pos.x;
            new_part[particle_count].y = mouse_pos.y;        
            new_part[particle_count].velocity_x = (float)rand() / RAND_MAX - 0.5f;
            new_part[particle_count].velocity_y = (float)rand() / RAND_MAX - 0.5f;
            particle_count++;
        }
        for (int i=0; i<particle_count; i++){
        update_particle(&new_part[i]);
        }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i=0; i<particle_count; i++){
        DrawCircle(new_part[i].x, new_part[i].y, particle_rad, RED);
        }
        EndDrawing(); 

}
    CloseWindow();
    free(new_part);
    return 0;
}