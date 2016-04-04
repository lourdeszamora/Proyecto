#include "Zombie.h"

Zombie::Zombie(int attack, int life, int x, int y, char type[],int maxFrame,int curFrame,int frameCount,int frameDelay,int frameWidth,int frameHeight)
{


}

void Zombie::drawZombie(char imagen[],int curFrame,int frameWidth,int frameHeight, int x, int y){
 /*   if(++frameCount>=frameDelay){
                if(++curFrame>= maxFrame){
                     curFrame=0;

                }
                frameCount=0;*/
   // }

  /*  ALLEGRO_BITMAP *imagenb=al_load_bitmap(imagen);
    al_draw_bitmap_region(imagenb,curFrame*frameWidth,0,frameWidth,frameHeight,x,y,0);*/


}

Zombie::~Zombie()
{
    //dtor
}
