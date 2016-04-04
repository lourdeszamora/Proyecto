#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
class Menu
{
    public:
        Menu();
        virtual ~Menu();
        ALLEGRO_BITMAP *menu_selected,*menu_start,*menu_exit,*menu_tutorial;
        ALLEGRO_BITMAP *mostrar(int selected);
    protected:
    private:
};



#endif // MENU_H_INCLUDED
