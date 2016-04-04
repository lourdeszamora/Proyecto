#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>

using std::string;

<<<<<<< HEAD
class Character
{
    public:
        int attack,life,x,y;
        char type[];
        Character(int attack, int life, int x, int y, char type[]);
        virtual ~Character();
=======

class Character{
	int attack,life,x,y;
    string type;
public:
    Character();
    Character(int attack, int life, int x, int y, string type);
    virtual ~Character();
    virtual void logic();
    virtual void draw();
>>>>>>> 1a704a9f858f1590d5e2765e2ed534c54e38cd36
    protected:
    private:
};
