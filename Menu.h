<<<<<<< HEAD
#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

=======
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <iostream>
>>>>>>> 774cc51a68d5726d235303e8a72d093655e6d6d1
class Menu
{
    public:
        Menu();
<<<<<<< HEAD
        void addBackground(ALLEGRO_BITMAP *background, int selected);
        virtual ~Menu();
=======
        virtual ~Menu();
        ALLEGRO_BITMAP *menu_selected,*menu_start,*menu_exit,*menu_tutorial;
        ALLEGRO_BITMAP *mostrar(int selected);
>>>>>>> 774cc51a68d5726d235303e8a72d093655e6d6d1
    protected:
    private:
};

<<<<<<< HEAD
#endif // MENU_H
=======


#endif // MENU_H_INCLUDED
>>>>>>> 774cc51a68d5726d235303e8a72d093655e6d6d1
