#include "render.h"
#include "player.h"
#include "raylib.h"
#include "input.h"


/**
 * @brief Return the first movement key currently held.
 * @return A key code, or 0 if none is held.
 */
int get_held_key(void)
{
    const int keys[] = { KEY_W, KEY_A, KEY_S, KEY_D };
    for (int i = 0; i < 4; i++) {
        if (IsKeyDown(keys[i])) return keys[i];
    }
    return 0;
}


void render (){
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,"Touch and Die");
  SetTargetFPS(60);

  m_vec2 player_position = {100,100};

  while (!WindowShouldClose()) {
    player_position = moves(get_held_key(), player_position);

    BeginDrawing();
    ClearBackground(RAYWHITE);

    DrawRectangle(player_position.x,player_position.y, PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_COLOR);

    EndDrawing();
  }
}
