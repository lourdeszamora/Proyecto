#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

#include "Menu.h"
#include "Level.h"

using namespace std;

int allegro_init(){

    if(!al_init())
    {
        al_show_native_message_box(NULL, "Error!", "Allegro has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!al_init_image_addon())
    {
        al_show_native_message_box(NULL, "Error!", "Image addon has failed to initialize.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
    }

    if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
    }

    if (!al_reserve_samples(1)){
        fprintf(stderr, "failed to reserve samples!\n");
        return -1;
    }

    return 1;

}
Menu *m= new Menu();
Level *level1= new Level(3,1,0);
//Level *level2= new Level();
//Level *level3= new Level();
//Level *level4= new Level();
//Level *level5= new Level();
//Level *level6= new Level();
enum LEVELD{ MENUD,LEVEL1D,LEVEL2D};
int main()
{
    ALLEGRO_DISPLAY *Screen = NULL, *Level1 = NULL;
    ALLEGRO_EVENT_QUEUE *EventQueue = NULL;
    ALLEGRO_EVENT Event;
    ALLEGRO_BITMAP *Background=NULL;
    ALLEGRO_SAMPLE *sample=NULL;
    LEVELD display= MENUD;
    int select=0;
    bool Exit = false, Playing = false;

    //inicializar allegro

    allegro_init();


    sample = al_load_sample("music.ogg");
    if(sample==NULL){
        printf( "Error al inicializar la musica!\n" );
    }

    Screen = al_create_display(1080, 680);
        if(Screen == NULL)
        {
            al_show_native_message_box(Screen, "Error!", "Failed to create the display.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

    EventQueue = al_create_event_queue();
        if(EventQueue == NULL)
        {
            al_show_native_message_box(Screen, "Error!", "Failed to create the event queue.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
            return -1;
        }

    if(!al_install_keyboard())
    {
        al_show_native_message_box(NULL, "Error!", "Failed to install keyboard.", 0, 0, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    al_register_event_source(EventQueue, al_get_display_event_source(Screen));
    al_register_event_source(EventQueue, al_get_keyboard_event_source());




    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);

   // Background=al_load_bitmap("menustart.png");
    while(Exit == false)
    {
        if(display==MENUD)
            m->addBackground(Background,select);
        else
            level1->addBackground(Background,0);


        al_flip_display();

        al_wait_for_event(EventQueue, &Event);

        if(!Playing && Event.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (Event.keyboard.keycode == ALLEGRO_KEY_UP){
                select--;

            }

            if (Event.keyboard.keycode == ALLEGRO_KEY_DOWN){
                select++;
            }
            if (Event.keyboard.keycode == ALLEGRO_KEY_ENTER){
                switch(select){
                case 0:
                    Playing = true;
                    display=LEVEL1D;
                    al_destroy_display(Screen);
                    Level1 = al_create_display(1400, 600);
                    level1->addBackground(Background,1);
                break;
                case 1:
                break;
                case 2:
                    Exit = true;
                break;
                }
            }
        }
        if (select>2)
            select=0;
        if (select<0)
            select=2;

        if(Event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            Exit = true;
        }
    }

    al_destroy_bitmap(Background);

    al_destroy_event_queue(EventQueue);
    al_destroy_display(Screen);

    return 0;
}
