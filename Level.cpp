#include "Level.h"
#include <string>
#include <cstring>

using std::string;

Level::Level(string name, string background, int zombiesDefeated):name(name), background(background), zombiesDefeated(zombiesDefeated)
{
    //ctor
}

Level::~Level()
{
    //dtor
}

void Level::wave(){

}

void Level::gameOver(){

}

void Level::win(){

}
