#include "Menu.h"

Menu::Menu()
{
    //ctor
}

void Menu::addBackground(ALLEGRO_BITMAP *background, int selected){

     switch(selected){
        case 0:
            background=al_load_bitmap("menustart.png");

        break;
        case 1:
            background=al_load_bitmap("menututorial.png");

        break;
        case 2:
            background=al_load_bitmap("menuexit.png");
        break;
    }
            al_draw_bitmap(background, 0, 0, 0);
}

Menu::~Menu()
{
    //dtor
}

