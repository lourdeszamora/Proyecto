#ifndef CHARACTER_H
#define CHARACTER_H
#include "string.h"


class Character
{
    public:
        int attack,life,x,y;
        string type;
        Character(int attack, int life, int x, int y, string type);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
