#include <raylib.h>

/**
 * @file main.c
 * @brief main file has main function   
 */


/** @name Screen Constants
 * Size of the Screen 
 * @{
 */
#define SCREEN_WIDTH  800 ///< Screen Width
#define SCREEN_HEIGHT 800
/** @} */



/**
 * @brief player_role is one of:
 * - CHASER
 * - RUNNER \n
 * interp. Chaser is the player who will be chasing runner  
 *         Runner will be running from the chaser
 * @note no examples are needed: the values themselves are the examples. 
 * 
 * Template: 
 * @code{.c}
 * ??? fn_for_player_role(player_role pr){
 *   switch(pr){
 *     case CHASER:
 *              ...
 *              break;
 *     case RUNNER:
 *              ...
 *              break;
 *   }
 * }
 * @endcode
 */
typedef enum {
  CHASER, 
  RUNNER
} player_role;


/**
 * @brief Returns color based on the role of the player
 * 
 * @param pr
 * @return String The color of the player based on their role
 * @note use template from player_role data definition 
 */
Color color_based_on_player(player_role pr){
  switch(pr){
  case CHASER:
    return GREEN;
    break;
  case RUNNER:
    return RED;
    break;
  }
  return BLACK;
}



typedef struct{
  float x; /**< stores the x position of the player*/ 
  float y; /**< stores the y position of the player*/
}player_position;



///< Examples of the player position
const player_position PR1 = { .x = 100 , .y = 100 };
const player_position PR2 = { .x = 200 , .y = 200 };






/**
 * @brief Runs the world
 * @return 0 if the program exit correctly 
 */

int main(void) {
  
}
