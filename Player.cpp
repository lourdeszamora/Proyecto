#include "Player.h"

Player::Player(string username, string password)
{
    this->username=username;
    this->password=password;
    pts=0;
}

Player::~Player()
{
    //dtor
}
