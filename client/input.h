/**
 * @file input.h
 * @brief Handles the input of player
 */


#include <stdbool.h>
#include "player.h"
/**
 * @brief checks if any key is pressed
 * 
 * @param key_pressed  checks if the given key is pressed
 * 
 * @return true if the key is pressed
 * false if key isn't pressed
 */

bool check_if_pressed(int key_pressed);



/**
 * @brief x and y position of the player
 */
typedef struct {
  float x;  /**<x value of the player*/
  float y;  /**<y value of the player*/
}position;

// Move it forward and left
/** 
 * @brief this function moves the rectangles on x and y axis by the given player input
 * @param key the key tells which key is pressed 
 * @param m_vec2 for the current_position i will come up with good way to do this 
 * @returns position updated x and y position of the x
 * !!!
 */


m_vec2 moves(int key, m_vec2 current_position);
