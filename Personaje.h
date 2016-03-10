#ifndef PERSONAJE_H
#define PERSONAJE_H
#include "Sprite.h"
#include "Sprite.h"


class Personaje
{

    public:
        int ataque;
        Sprite sprite;
//        Personaje debilidad;
        int vida;
        int x;
        int y;
        string tipo;
        string nombre;
        Personaje(int ataque, Sprite sprite, Personaje personaje, int vida, int x, int y, string tipo, string nombre);
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
