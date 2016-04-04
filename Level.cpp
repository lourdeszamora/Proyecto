#include "Level.h"
#include <string>
#include <cstring>

using std::string;

Level::Level(string name, string background, int zombiesDefeated, int cantidadZombies):name(name), background(background), zombiesDefeated(zombiesDefeated), cantidadZombies(cantidadZombies)
{
    //ctor
}

Level::~Level()
{
    //dtor
}

void Level::wave(){

}

void Level::gameOver(ALLEGRO_DISPLAY *display){
    al_show_native_message_box(NULL, "Error!", "GAME OVER!!!", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
}

void Level::win(){

}
