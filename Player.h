#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;
class Player
{
    public:
        string username;
        string password;
        int pts;
        Player(string username, string password);
        virtual ~Player();
};

#endif // PLAYER_H
