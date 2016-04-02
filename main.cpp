using namespace std;

#include <stdio.h>

#include "Menu.h"
Menu* m;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;
ALLEGRO_BITMAP *menu_start,*menu_exit,*menu_tutorial,*menu_selected;

enum LEVEL { MENU, LEVEL1, LEVEL2 };
LEVEL level= MENU;

int main()
{


    int redraw=1;
    al_init();
    al_init_image_addon();
    al_install_keyboard();

    menu_exit=al_load_bitmap("menuexit.png");
    menu_start=al_load_bitmap("menustart.png");
    menu_tutorial=al_load_bitmap("menututorial.png");

    display = al_create_display(1080, 680);

    event_queue = al_create_event_queue();

    timer = al_create_timer(1.0 / 60);


    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_start_timer(timer);
    int select=0;
    ALLEGRO_EVENT event;
    ALLEGRO_TIMEOUT timeout;
    al_init_timeout(&timeout, 0.06);
    while (1)
    {


        bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);

        if(get_event && event.type == ALLEGRO_EVENT_KEY_DOWN) ///look for keyboard events
        {
            if (event.keyboard.keycode == ALLEGRO_KEY_UP){
                select--;

            }

            if (event.keyboard.keycode == ALLEGRO_KEY_DOWN){
                select++;
            }

        }

        if (select>2)
            select=0;
        if (select<0)
            select=2;

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;


            switch(select){
            case 0:
                menu_selected=menu_start;


            break;
            case 1:
                menu_selected=menu_tutorial;

            break;
            case 2:
                menu_selected=menu_exit;
            break;



        }
        al_draw_bitmap(menu_selected, 0, 0, 0);
        al_flip_display();






    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_bitmap(menu_selected);
    al_destroy_bitmap(menu_exit);
    al_destroy_bitmap(menu_start);
    al_destroy_bitmap(menu_tutorial);

    return 0;
}


