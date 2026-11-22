#include <raylib.h>

/**
 * @mainpage TouchAndDie
 * @brief writing game in one file because i am new to development 
 */


// Constants 
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800
#define TARGET_FPS    60
#define GAME_TITLE    "Touch And Die"
#define GAME_ICON     


#define PLAYER_WIDTH      50
#define PLAYER_HEIGHT     50
#define PLAYER_Y_POSITION (SCREEN_HEIGHT - PLAYER_HEIGHT)
#define PLAYER_SPEED      10
#define PLAYER_COLOR      RED


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



/**
 * @brief key_input is one of:
 * - MOVE_LEFT
 * - MOVE_RIGHT
 * interp. MOVE_LEFT and MOVE_RIGHT key moves x position of the player to left or right
 * if pressed at same time they cancel out each other
 *
 * Template: 
 * @code{.c} 
 * ??? fn_for_key_input(key_input k){
 * switch(k){
 *    case MOVE_LEFT:
 *            return ....;
 *    case MOVE_RIGHT:
 *           return  ....;
 *  }
 *}
 * @endcode
 */
typedef enum{
  MOVE_LEFT = KEY_LEFT,
  MOVE_RIGHT = KEY_RIGHT
}key_input;






// Function Definitions 
/**
 * @brief checks if user has pressed key to move the player.
 * @param key_input 
 * @return bool returns true if the key is pressed and false if the key isn't pressed
 */
bool key_pressed(key_input k){
 switch(k){
    case MOVE_LEFT:
      return IsKeyPressed(MOVE_LEFT);
    case MOVE_RIGHT:
      return  sKeyPressed(MOVE_RIGHT);
  }
}


/**
 * @brief checks if player is outside the bounderies
 * @param Player
 * @return boolean   returns true if the player is out of the grid and false if it is not 
 */
bool out_of_bound (Player c){
  if(c.x >=0 && c.x <= SCREEN_WIDTH){
    return false;
  }

  return true;
}

/**
 * @brief Moves the player on x axis by the given input and checks if the player  is out of the grid or not 
 * @param Player
 * @return void 
 */

void move(Player c){
  //it should check if the player is out of bound
  // if it isn't out of bound then it should move the player according to the key the user and input 
}


int main(void){
  InitWindow(SCREEN_WIDTH , SCREEN_HEIGHT, GAME_TITLE);
  SetTargetFPS(TARGET_FPS);
  Player p;
  p.x = 100;
  p.y = PLAYER_Y_POSITION;


  while(!WindowShouldClose()){
    // I wish for a function that checks which key is pressed and return updated position  
 

    BeginDrawing();

    DrawRectangle(p.x,p.y,PLAYER_WIDTH, PLAYER_HEIGHT, PLAYER_COLOR); ///< Player

    EndDrawing();
  }
  CloseWindow();
  return 0;
}
