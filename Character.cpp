#include "Character.h"

Character::Character(int attack, int life, int x, int y, char type)
{
    this->attack=attack;
    this->life=life;
    this->x=x;
    this->y=y;
    this->type=type;
}

Character::~Character()
{
    //dtor
}

void Character::logic()
{

}

void Character::draw()
{

}

