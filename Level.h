#ifndef LEVEL_H
#define LEVEL_H
#include <stdio.h>
#include <allegro5/allegro.h>
#include <string>

using std::string;

class Level
{
    public:
        string name, background;
        int zombiesDefeated;
        Level(string name, string background, int zombiesDefeated);
        virtual ~Level();
        virtual void wave();
        virtual void gameOver(ALLEGRO_DISPLAY *display);
        virtual void win();
    protected:
    private:
};

#endif // LEVEL_H
