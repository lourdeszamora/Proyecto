#include "Level.h"

Level::Level(int zombies, int plants, int defeated)
{
    //ctor
}
void Level::addBackground(ALLEGRO_BITMAP *background, int selected){

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
    }
            al_draw_bitmap(background, 0, 0, 0);
}

Level::~Level()
{
    //dtor
}
