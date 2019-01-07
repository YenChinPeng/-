#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define UP_RIGHT 0
#define UP_LEFT 1
#define DOWN_RIGHT 2
#define DOWN_LEFT 3
#define STOP 4

struct A{
  int photo;
  int number;
};

int SwagBall(struct A **C,int step,int DISPLAY_WIDTH,int DISPLAY_HEIGHT)
{
    ALLEGRO_EVENT alEvent;
    ALLEGRO_EVENT_QUEUE* alEventQueue = NULL;
    ALLEGRO_BITMAP* bitmap = NULL;
    ALLEGRO_KEYBOARD_STATE KBstate;

    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();

    int ball,ball_x,ball_y;
    int direction;

   ball = al_load_bitmap( "ball.jpg");
   ball_x = 400-35;
   ball_y = 950-35-1;
   srand( time( NULL ) );
   direction = rand() % 2;

   while(1)
   {
    al_get_keyboard_state(&KBstate);
    if (al_key_down(&KBstate, ALLEGRO_KEY_ESCAPE)) break;

   // bound_ball_x(C,ball_x,ball_y);

    if ( ball_y <= 0 )
   {
     direction=reverseVerticalDirection(direction);
   }


   if ( ball_x <= 0 || ball_x >= 800-35 )
   {
      direction=reverseHorizontalDirection(direction);
   }
    if ( ball_y >= 950-35 )
   {
     direction=STOP;
   }

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
         ball_x = ball_x +1;
         ball_y = ball_y +1;
         break;
      case DOWN_LEFT:
         ball_x = ball_x -1;
         ball_y = ball_y +1;
         break;
      case STOP:
         ball_x=ball_x;
         ball_y=ball_y;
         break;
   }
   al_draw_bitmap(ball, ball_x, ball_y,0);

   al_rest(0.00001);

   al_flip_display();
   if (direction==STOP)
   {
     step++;
     random (C,step,1,DISPLAY_WIDTH,DISPLAY_HEIGHT);
   }
   }

   al_destroy_bitmap( ball);
   return 0;
}

int reverseVerticalDirection(int direction)
{
    switch ( direction ){
      case DOWN_RIGHT:
         direction = UP_RIGHT;
         break;
      case UP_RIGHT:
         direction = DOWN_RIGHT;
         break;
      case DOWN_LEFT:
         direction = UP_LEFT;
         break;
      case UP_LEFT:
         direction = DOWN_LEFT;
         break;
}
  return direction;
}
int reverseHorizontalDirection(int direction)
{
   switch ( direction ){
      case DOWN_RIGHT:
         direction = DOWN_LEFT;
         break;
      case UP_RIGHT:
         direction = UP_LEFT;
         break;
      case DOWN_LEFT:
         direction = DOWN_RIGHT;
         break;
      case UP_LEFT:
         direction = UP_RIGHT;
         break;
   }
   return direction;
}
