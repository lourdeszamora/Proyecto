
#ifndef LEVEL_H
#define LEVEL_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

class Level
{
    public:
        int zombies;
        int plants;
        int defeated;
        Level(int zombies, int plants, int defeated);
        void addBackground(ALLEGRO_DISPLAY *Screen,ALLEGRO_BITMAP *background, int selected);
        void addEvents(ALLEGRO_DISPLAY *Screen,ALLEGRO_EVENT_QUEUE *EventQueue,ALLEGRO_TIMER *timer);
        void drawLevel();
//        int maxFrame,int curFrame,int frameCount,int frameDelay,int maxFrame,int curFrame,int frameCount,int frameDelay
        virtual ~Level();
    protected:
    private:
};

#endif // LEVEL_H
