#include <stdio.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdlib.h>

int launch_ball(int ball_x,int ball_y)
{
    int N=0;
    int K;
    ALLEGRO_EVENT alEvent;
    ALLEGRO_EVENT_QUEUE* alEventQueue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* bitmap = NULL;
    ALLEGRO_BITMAP* ball = NULL;
    ALLEGRO_KEYBOARD_STATE KBstate;
    // Initialize Allegro
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();

   while(1){
    al_get_keyboard_state(&KBstate);
        if (al_key_down(&KBstate, ALLEGRO_KEY_DOWN)) break;
    alEventQueue = al_create_event_queue();
    if(alEventQueue == NULL)
    {
        printf("Failed to create event queue!\n");
        return -1;
    }
    K=N;
    if (al_key_down(&KBstate, ALLEGRO_KEY_RIGHT)) N +=1 ;

    if (al_key_down(&KBstate, ALLEGRO_KEY_LEFT)) N -=1 ;

        if(N==0)
                bitmap = al_load_bitmap("./left.jpg");
        else if(N==1)
                bitmap = al_load_bitmap("./45.jpg");
        else if(N==2)
                bitmap = al_load_bitmap("./up.jpg");
        else if(N==3)
                bitmap = al_load_bitmap("./135.jpg");
        else if(N==4)
                bitmap = al_load_bitmap("./right.jpg");
        if(bitmap == NULL)
    {
        printf("Failed to load bitmap!\n");
        al_destroy_event_queue(alEventQueue);
        al_destroy_display(display);
        return -1;
    }
       ball = al_load_bitmap( "ball.jpg");
    // Register keyboard and mouse to event queue
    al_register_event_source(alEventQueue, al_get_keyboard_event_source());

        // Draw bitmap

        al_draw_bitmap(bitmap,400-100-35 , 950-50, 0); //35:²y¥b®|,80:¿j¶ô¥b®|,100,50:½bÀYªº
        al_draw_bitmap(ball, 400-35, 950-35,0);


        // Flip display to show the drawing result
        al_flip_display();
    al_wait_for_event(alEventQueue, &alEvent);
   }
}

