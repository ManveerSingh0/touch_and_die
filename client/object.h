#ifndef OBJECT_H
#define OBJECT_H




/** @name dodge objects
 * @{
 */
#define OBJECT_SIZE     30 
#define OBJECT_COLOR    LIGHTGRAY
#define OBJECT_SPEED    300 //< will change the decision of variable object speed later
#define OBJECT_MAX      10
/**@}*/


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



#endif // OBJECT_H
