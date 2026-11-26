#include "window.h"








void play(){
  InitWindow(WINDOW_WIDTH , WINDOW_HEIGHT, WINDOW_TITLE);
  SetTargetFPS(FPS);



  while(!WindowShouldClose()){


    ClearBackground(RAYWHITE);
    BeginDrawing();


    EndDrawing();
  }

  CloseWindow();
}
