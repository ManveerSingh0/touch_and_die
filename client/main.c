#include <raylib.h>

/**
 * @mainpage TouchAndDie
 * @brief writing game in one file because i am new to development 
 */


// Constants 
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800
#define FPS           60
#define GAME_TITLE    "Touch And Die"

#define PLAYER_WIDTH      50
#define PLAYER_HEIGHT     50
#define PLAYER_Y_POSITION (SCREEN_HEIGHT - PLAYER_HEIGHT)
#define PLAYER_SPEED


#define OBJECT_WIDTH  20
#define OBJECT_HEIGHT 50 



// Data Definitions 
/**
 * @brief Player on the bord
 * Template:
 * @code{.c}
 * ??? fn_for_player(Player c){
 * return ... player.x
 *            player.y;
 *}
 * @endcode
 * Template rule used:
 * - compound: 2 fields 
 */

typedef struct{
  int x;
  int y;
}Player;


const Player P_LEFT   = {.x = 0, .y = PLAYER_Y_POSITION};  
const Player P_MIDDLE = {.x = SCREEN_WIDTH / 2 , .y = PLAYER_Y_POSITION}; 
const Player P_RIGHT  = {.x = SCREEN_WIDTH , .y = PLAYER_Y_POSITION}; 



/**
 * 
 */


/**
 * @brief PlayerXPosition is Integer
 * interp. Player x position is the x position on the window where
 * 0 <= PlayerXPosition  <= SCREEN_WIDTH 
 * 
 * Template:
 * @code{.c}
 * ??? fn_for_player_x_position(int pxp){
 *    (... pxp)
 * }
 * @endcode
 * Template rule used:
 * atomic distinct: Integer
 */

int P1 = 0;
int P2 = 200;
int p3 = 800;



// Function Definitions 



int main(void){
  InitWindow(SCREEN_WIDTH , SCREEN_HEIGHT, GAME_TITLE);
}
