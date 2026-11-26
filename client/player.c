#include "player.h"




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
