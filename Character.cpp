#include "Character.h"
#include <string>
#include <cstring>

using std::string;

Character::Character(){

<<<<<<< HEAD
Character::Character(int attack, int life, int x, int y, char type[])
{
    //ctor
=======
>>>>>>> 1a704a9f858f1590d5e2765e2ed534c54e38cd36
}

Character::Character(int attack, int life, int x, int y, string type):attack(attack),life(life),x(x), y(y),type(type){

}

Character::~Character(){

}

void Character::logic(){

}

void Character::draw(){

}

