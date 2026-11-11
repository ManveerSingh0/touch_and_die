#include "input.h"
#include "raylib.h"
#include <stdio.h>

bool check_if_pressed(int key_pressed) {
  if (IsKeyPressed(key_pressed)) {
    return true;
  }
  return false;
}



m_vec2 moves(int key , m_vec2 current_position) {
  if (key == KEY_A) {
    current_position.x -= 10;
    current_position.y -= 0;
  }
  else if (key == KEY_D) {
    current_position.x += 10;
    current_position.y += 0;
  }
  else if (key == KEY_W) {
    current_position.x += 0;
    current_position.y -= 10;
  }
  else if (key == KEY_S) {
    current_position.x -= 0;
    current_position.y += 10;
  }
  return (m_vec2){current_position.x , current_position.y};
}
