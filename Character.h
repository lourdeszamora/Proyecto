#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>


class Character
{
    public:
        int attack,life,x,y;
        char type[];
        Character();
        virtual ~Character();
    protected:
    private:
};

#endif // CHARACTER_H
