#include <stdio.h>
#include <stdlib.h>


#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
struct A{
  int photo;
  int number;
};
int SwagBall(struct A **C,int step,int DISPLAY_WIDTH,int DISPLAY_HEIGHT);
int load_blocks( struct A **B,int step,int round,int width, int height)
{
    int i,j;

    ALLEGRO_EVENT alEvent;
    ALLEGRO_EVENT_QUEUE* alEventQueue = NULL;
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_BITMAP* bitmap = NULL;

    al_init();
    al_init_primitives_addon();
    al_install_keyboard();
    al_init_image_addon();

    if (round==0){
    display = al_create_display(width,height);
    if(display == NULL)
    {
        printf("Failed to create Allegro display!\n");
        return -1;
    }
    }
    alEventQueue = al_create_event_queue();
    if(alEventQueue == NULL)
    {
        printf("Failed to create event queue!\n");
        return -1;
    }

    al_register_event_source(alEventQueue, al_get_keyboard_event_source());

    for(i=1; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(B[i][j].number==0)
            {
                bitmap = al_load_bitmap("./no.jpg");;
            }
            else if(B[i][j].number==1)
            {
                bitmap = al_load_bitmap("./1.jpg");
            }
            else if(B[i][j].number==2)
            {
                bitmap = al_load_bitmap("./2.jpg");
            }

            else if(B[i][j].number==3)
            {
                bitmap = al_load_bitmap("./3.jpg");
            }


            else if(B[i][j].number==4)
            {
                bitmap = al_load_bitmap("./4.jpg");

            }

              al_draw_bitmap(bitmap, 30+80*j, 30+80*i, 0);
              al_flip_display();
        }
    }

    launch_ball();
    SwagBall(B,step,width,height);

    al_wait_for_event(alEventQueue, &alEvent);

    al_destroy_display(display);
    al_destroy_bitmap(bitmap);
    }

