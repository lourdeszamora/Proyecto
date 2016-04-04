#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>
#include "Character.h"

class Zombie: public Character
{
    public:
        Zombie(int attack, int life, int x, int y, char type[],int maxFrame,int curFrame,int frameCount,int frameDelay,int frameWidth,int frameHeight);
        void drawZombie(char imagen[],int curFrame,int frameWidth,int frameHeight, int x, int y);
        virtual ~Zombie();
    protected:
    private:
};

#endif // ZOMBIE_H
