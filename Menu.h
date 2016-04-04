
#ifndef MENU_H
#define MENU_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>


class Menu
{
    public:
        Menu();

        void addBackground(ALLEGRO_BITMAP *background, int selected);
        virtual ~Menu();

    protected:
    private:
};

#endif // MENU_H



