#ifndef PLAYER_H
#define PLAYER_H
/**
 * @file player.h
 * @brief Defines the player 
 */



#define PLAYER_WIDTH 200
#define PLAYER_HEIGHT 200


#define PLAYER_COLOR RED




/**
 * @brief player's position
 */

typedef struct {
  float x;  /**< player's x position*/
  float y;  /**< player's y position*/
} m_vec2;


/**
 * !!!
 * @brief Updated the player's position using a struct
 * This function should return updated value of struct
 * @param 
 * @return 
 */

m_vec2 set_the_player_position(m_vec2 player_position);


#endif // PLAYER_H
