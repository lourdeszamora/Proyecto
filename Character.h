#pragma once
#include <string>
#include <iostream>
#include <map>
#include <fstream>

using std::string;


class Character{
	int attack,life,x,y;
    string type;
public:
    Character(int attack, int life, int x, int y, string type);
    ~Character();
    virtual void logic();
    virtual void draw();
    protected:
    private:
};
