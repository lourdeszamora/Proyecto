#pragma once
#include <string>

using std::string;


class Character{
	int attack,life,x,y;
    string type;
public:
    Character(int attack, int life, int x, int y, string type);
    ~Character();
    protected:
    private:
};