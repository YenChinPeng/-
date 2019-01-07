#include <stdio.h>
#include <stdlib.h>
#define UP_RIGHT 0
#define UP_LEFT 1
#define DOWN_RIGHT 2
#define DOWN_LEFT 3

void moveBall(int direction, int ball_x, int ball_y) /* moves the ball */
{
    switch ( direction )
   {
      case UP_RIGHT:
         ball_x = ball_x +1;
         ball_y = ball_y -1;
         break;
      case UP_LEFT:
         ball_x = ball_x -1;
         ball_y = ball_y -1;
         break;
      case DOWN_RIGHT:
         ball_x = ball_x +1; /* move the ball to the right */
         ball_y = ball_y +1; /* move the ball down */
         break;
      case DOWN_LEFT:
         ball_x = ball_x -1; /* move the ball to the left */
         ball_y = ball_y +1; /* move the ball down */
         break;
   }

}
