#ifndef LEVEL_H
#define LEVEL_H
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
        virtual void gameOver();
        virtual void win();
    protected:
    private:
};

#endif // LEVEL_H
