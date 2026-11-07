#include "render.h"



void render (){
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Touch and Die");

  while (!WindowShouldClose()) {
    BeginDrawing();


    EndDrawing();
  }
}
