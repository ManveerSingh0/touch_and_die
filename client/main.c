#include <raylib.h>

#define SCREEN_HEIGHT 400
#define SCREEN_WIDTH  800



int main(void) {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Touch And Die");

  Vector2 v1 = {0,0};
  Vector2 v2 = {12,-12};
  Vector2 v3 = {24,-24};


  while (!WindowShouldClose()) {
    BeginDrawing();
    DrawRectangle(100,100,50,50,RED);
    EndDrawing();
  }

  CloseWindow();
}
