#include <raylib.h>
#include <stdio.h>


/**
 * @mainpage TouchAndDie
 * @brief writing the game in one file for now later it will be divided in multiple files 
 */



/** @name Window
 * The window everything is drawin in 
 * @{
 */
#define SCREEN_WIDTH  800
#define SCREEN_HEIGHT 800
#define TARGET_FPS    60
#define GAME_TITLE    "Touch And Die"
#define GAME_ICON     
/** @} */

/** @name Player
 * Player Size , color , speed, constant position of it
 */ 

#define PLAYER_SIZE       50
#define PLAYER_SPEED      300.0f
#define PLAYER_COLOR      RED
#define PLAYER_Y_POSITION (SCREEN_HEIGHT - PLAYER_SIZE)

/**
 *  maximum a player can move to the player_max_x position  to the right side
 */
#define PLAYER_MAX_X (SCREEN_WIDTH - PLAYER_SIZE)
/** @} */


/** @name dodge objects
 * @{
 */
#define OBJECT_SIZE     30 
#define OBJECT_COLOR    LIGHTGRAY
#define OBJECT_SPEED    300 //< will change the decision of variable object speed later
#define OBJECT_MAX      10
/**@}*/



// Data Definitions 
/**
 * @brief player is the x position of the player 
 * @code{.c}
 * ??? fn_for_player(player p){
 *   return ... p.x;
 * }
 * @endcode
 * Examples:
 * Player P1 = {.x = SCREEN_WIDTH / 2 } ;; Middle of the screen 
 * Player P2 = {.x = 0} ;; left side of the screen 
 * Player P3 = {.x = PLAYER_MAX_X } ;; max right side of the screen 
 */

typedef struct{
  float x;
}player;


/**
 * @brief struct to check which key is pressed and which is not 
 * @code{.c}
 * ??? fn_for_player_input(player_input pi){
 *  return ... pi.left, 
 *             pi.right;
 * }
 * Examples:
 * player_input PI1 = {.left = true , .right = false } ;; Player wants to move left
 * player_input PI1 = {.left = false , .right = true } ;; Player wants to move right
 * player_input PI1 = {.left = true , .right = true } ;; No movement because both keys are pressed
 */
typedef struct {
  bool left;
  bool right; 
}player_input;


/** @brief Object that player has to dodge 
 * object is (x)float is the x position of the object ,(y)float  y position of the float
 * Template: 
 * @code{.c}
 * ??? fn_for_object(Object o){
 *  return ... o.x,
 *             o.y;
 *}
 * @endcode
 */
typedef struct {
  float x;
  float y;
}Object;

/** @brief keeps the count of the objects
 * @code{.c}
 * ??? fn_for_object_count(object_count oc){
 * for(int i = 0; i < oc.count; i++){
 *   ... fn_for_object(t.cars[i]);
 * } 
 *}
 * @endcode
 */
typedef struct{
  Object o[OBJECT_MAX];
  int count;
}object_count;





// Function Definition 




/**
 * @brief Reads the input from the keyboard
 * By using the raylib provided KEYS and updates the player_input 
 * @param void 
 * @return player_input 
 * <use template from player_input data definition>  
 */
player_input read_input(){
  return (player_input){ .left = IsKeyDown(KEY_LEFT), 
			 .right = IsKeyDown(KEY_RIGHT)};
}




/**
 * @brief it takes the x position of the player and return
 *        - 0 if the player is getting out of left side limit
 *        - PLAYER_MAX_X if player is trying to get outside the right x limit
 *        - x itself if it in the bound of limits  
 */
float out_of_bound(float x){
  if(x < 0){return 0;} 
  else if(x > PLAYER_MAX_X){ return PLAYER_MAX_X;}
  return x;
}


/**
 * @brief this function takes read_input() data and return int negative or positive according to the key input that player has given  
 * @param player_input , this to check which input is true so that i we can give direction
 * @return int , -1 if p.left is true and 1 if p.right is true if nothing is true then 0 is given 
 */
int direction(player_input p){
  if(p.left){ return -1; }
  if(p.right) {return 1; }

  return 0;
} 

/**
 * @brief based on the given input by read_input() we will increase or descrese the x position of the player 
 * @param player
 * @param dir  
 * @param delta_time
 * @return player
 */

player move(player pl , player_input pi, float delta_time){
  float distance = PLAYER_SPEED * direction(pi) * delta_time ;
  float new_x = pl.x + distance;
  return (player) {.x = out_of_bound(new_x) };

}

/** @brief moves one object at a time
 * it should take object and DT to increase the y axis of the object  , it should return the updated object 
 */
Object move_object(Object o, float dt){
  return (Object){ .x = o.x , .y = OBJECT_SPEED * dt + o.y };
}

// we are trying to move all the  object we have , object_count keeps the count of the object and put them in
// so i guess we will need to use object count here somehow 

object_count move_all(object_count oc, float dt){
  for(int i = 0; i < oc.count; i++){
    oc.o[i] = move_object(oc.o[i], dt);
  }
  printf(" %d " , oc.count);
  return oc;
} 


void draw_objects(object_count t){
    for (int i = 0; i < t.count; i++) {
        DrawRectangle((int)t.o[i].x, (int)t.o[i].y, 60, 30, BLUE);
    }
}



int main(void){
  InitWindow(SCREEN_WIDTH , SCREEN_HEIGHT, GAME_TITLE);
  player p;
  p.x = 100;

  object_count oc;
  oc.count = OBJECT_MAX;

  while(!WindowShouldClose()){
    player_input in = read_input();  // on key 
    p = move(p,in,GetFrameTime()); 

    oc = move_all(oc,GetFrameTime());


    BeginDrawing();
    ClearBackground(RAYWHITE);

    draw_objects(oc);

    DrawRectangle(p.x, PLAYER_Y_POSITION, PLAYER_SIZE, PLAYER_SIZE, PLAYER_COLOR);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
