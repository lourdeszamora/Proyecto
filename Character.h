#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class Character
{
    public:
        int attack;
        int life;
        int x;
        int y;
        char type;
        Character(int attack, int life, int x, int y, char type);
        virtual ~Character();
        void logic();
        void draw();
    protected:
    private:
};

#endif // CHARACTER_H
