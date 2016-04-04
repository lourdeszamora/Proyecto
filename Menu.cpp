#include "Menu.h"

Menu::Menu(){

    Menu::menu_exit=al_load_bitmap("menuexit.png");
    Menu::menu_start=al_load_bitmap("menustart.png");
    Menu::menu_tutorial=al_load_bitmap("menututorial.png");


}

ALLEGRO_BITMAP* Menu::mostrar(int selected){

    switch(selected){
            case 0:
               return Menu::menu_start;

            break;
            case 1:
                 return Menu::menu_tutorial;
                //al_clear_to_color(al_map_rgb_f(0, 0, 0));
                //return al_load_bitmap("menututorial.png");
            break;
            case 2:
                 return Menu::menu_exit;
                //return al_load_bitmap("menuexit.png");
            break;
            default:
                return false;
            break;

            }
}
Menu::~Menu(){


}
