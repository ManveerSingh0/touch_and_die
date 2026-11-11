#include <raylib.h>

/**
 * @file main.c
 */


/** @name Screen Constants
 * Size of the Screen 
 * @{
 */
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800
/** @} */


/** @name Runner Constants
 * Runner's Width , Height and Color
 * @{
 */
#define RUNNER_WIDTH 100 
#define RUNNER_HEIGHT 100 
#define RUNNER_COLOR RED 
/** @} */


/** @name Chaser Constants
 * Chaser's Width , Height and Color
 * @{
 */
#define CHASER_WIDTH 100
#define CHASER_HEIGHT 100
#define CHASER_COLOR GREEN
/** @} */



/**
 * @brief Player position is the position of the player on x and y coordinates \n
 * Template: 
 * @code{.c}
 * ??? fn_for_player_position(player_position pp){
 *    return ...  pp.x    // float
 *                pp.y    // float
 * }
 * @endcode
 */

typedef struct{
  float x; /**< stores the x position of the player*/ 
  float y; /**< stores the y position of the player*/
}player_position;

/* Examples of the player position */ 
const player_position PP1 = { .x = 100 , .y = 100 };
const player_position PP2 = { .x = 200 , .y = 200 };



int main(void) {
  
}
