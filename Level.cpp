#include "Level.h"

Level::Level(int zombies, int plants, int defeated)
{
    //ctor
}
void Level::addBackground(ALLEGRO_DISPLAY *Screen,ALLEGRO_BITMAP *background, int selected){

    if(selected){
        al_destroy_display(Screen);
        Screen = al_create_display(1400, 600);
    }


    switch(selected){
        case 0:
            background=al_load_bitmap("background.jpg");

        break;
        case 1:
            background=al_load_bitmap("background.jpg");

        break;
        case 2:
            background=al_load_bitmap("backgroundNight.jpg");
        break;
        case 3:
            background=al_load_bitmap("backgroundNight.jpg");
        break;
        case 4:
            background=al_load_bitmap("Background5.jpg");
        break;
        case 5:
            background=al_load_bitmap("Background5.jpg");
        break;
        case 6:
            background=al_load_bitmap("tutorial.jpg");
        break;
    }
    al_draw_bitmap(background, 0, 0, 0);

}

void drawLevel(int frameCount, int frameDelay, int maxFrame, int curFrame){
    if(++frameCount>=frameDelay){
        if(++curFrame>= maxFrame){
             curFrame=0;

        }
        frameCount=0;
    }

}
//int maxFrame,int curFrame,int frameCount,int frameDelay,int maxFrame,int curFrame,int frameCount,int frameDelay


void Level::drawLevel(){

}

void Level::addEvents(ALLEGRO_DISPLAY *Screen,ALLEGRO_EVENT_QUEUE *EventQueue,ALLEGRO_TIMER *timer){
    timer = al_create_timer(1.0/ 5);
    al_register_event_source(EventQueue, al_get_display_event_source(Screen));
    al_register_event_source(EventQueue, al_get_mouse_event_source());
    al_register_event_source(EventQueue, al_get_timer_event_source(timer));
    al_start_timer(timer);
}

Level::~Level()
{
    //dtor
}
