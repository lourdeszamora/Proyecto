#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class Character
{
    public:
        int attack,life,x,y;
        char type[];
        Character(int attack, int life, int x, int y, char type[]);
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
