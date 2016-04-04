#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_native_dialog.h>

#include "Menu.h"
#include "Level.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

enum LevelD { MENUD, LEVEL1D, LEVEL2D, TUTORIALD};

int tamano_registro=44;
//REVISAR ESTA FUNCION
Player searchUser (Player jugador)
    {
        ifstream leer("Jugadores");
        leer.seekg(0,ios::end);
        int tam=leer.tellg();
        leer.seekg(0);
        char usern[20];
        char password[20];
        while (leer.tellg()<tam)
        {
            leer.read(usern,20);
            leer.read(password,20);
            leer.seekg(4,ios::cur);
            if(usern==jugador.username){
                return Player(usern,password);
            }
        }
        leer.close();
        return Player((char*)"",(char*)"");
    }

    bool crearUsuario (Player jugador, int pos)
    {

        if(searchUser(jugador).username == "")
        {
            ofstream guardar("Jugadores", ios::in);
            if(!guardar.is_open())
            {
                guardar.open("Jugadores");
            }
            guardar.seekp(pos*tamano_registro);
            guardar.write(jugador.username.c_str(),20);
            guardar.write(jugador.password.c_str(),20);
            guardar.write((char*)&jugador.pts,4);
            guardar.close();
            return true;
        }
        else
            return false;
    }

    bool iniciarSesion (Player jugador)
    {
        if(searchUser(jugador).username == jugador.username)
        {
            return true;
        }

        else
            return false;
    }
//http://es.tldp.org/Tutoriales/doc-programacion-algoritmos-ordenacion/alg_orden.pdf
    void intercambiar (int * A, int i, int j)
    {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
    void ordenacion_seleccion (int * A, int N)
    {
        int i, j, k;
        for (i = 0; i < N - 1; i++)
        {
            for (k = i, j = i + 1; j < N; j++)
                if (A[j] < A[k])
                    k = j;
                    if (k != i)
                        intercambiar (A, i, k);
        }
    }


    list<int> ranking ()
    {
        ifstream leer("Jugadores");
        leer.seekg(0,ios::end);
        int tam=leer.tellg();
        leer.seekg(0);
        int contador_registros=0;
        int puntos;
        int cant_registros = tam/tamano_registro;
        int *ranking=new int[cant_registros];
        list<int> ordenado;
        for(int i=0;i<cant_registros;i++)
        {
            leer.seekg(40, ios::cur);
            leer.read((char*)&puntos,4);
            ranking[i] = puntos;

        }
        leer.close();
        ordenacion_seleccion(ranking,cant_registros);
        for(int i=0;i<cant_registros;i++)
        {
            ordenado.push_back(ranking[i]);
        }
        ordenado.reverse();
        return ordenado;
    }


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
    if(!al_install_mouse()) {
		printf("Error installing mouse.\n");
		return -1;
	}

    return 1;

}
Menu *m= new Menu();
Level *level1= new Level(3,1,0);
Level *tutorial= new Level(0,0,0);

//Level *level2= new Level();
//Level *level3= new Level();
//Level *level4= new Level();
//Level *level5= new Level();
//Level *level6= new Level();

int main()
{
    LevelD display = MENUD;
    ALLEGRO_DISPLAY *Screen = NULL;
    ALLEGRO_EVENT_QUEUE *EventQueue = NULL;
    ALLEGRO_EVENT Event;
    ALLEGRO_BITMAP *Background=NULL, *Tutorial=NULL;
    ALLEGRO_SAMPLE *sample=NULL;
    ALLEGRO_TIMER *timer;
    int select=0;

    //animaciones


    bool Exit = false, Playing = false;
    Player jug("A","123");
    jug.pts=950;
    bool sepudo = crearUsuario(jug,0);
    list<int> mi_lista = ranking();

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

    Tutorial=al_load_bitmap("tutorial.png");



    al_play_sample(sample, 1.0, 0.0,1.0,ALLEGRO_PLAYMODE_LOOP,NULL);
    timer = al_create_timer(1.0/ 5);


    while(Exit == false)
    {

        if(display==MENUD)
            m->addBackground(Background,select);
        else if(display==LEVEL1D)
            level1->addBackground(Screen,Background,0);



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
                    level1->addBackground(Screen,Background,3);
                    level1->addEvents(Screen,EventQueue,timer);
                break;
                case 1:
                    Playing = false;
                    display=TUTORIALD;
                    al_clear_to_color(al_map_rgb(255, 97, 255));
                    if(Tutorial==NULL){
                        printf("No reconoce la imagen .l.");
                    }
                    else
                        al_draw_bitmap(Tutorial,0,0,0);

                    select=3;
                break;
                case 2:
                    for(list<int>::iterator temp=mi_lista.begin(); temp!=mi_lista.end();temp++){
                        cout<<"Puntuacion de Usuario: "<<*temp<<endl;
                    }
                    Exit = true;
                break;
                case 3:
                    printf("Opcion 3");
                    m->addBackground(Background,0);
                break;

                }
            }

            if (Event.type == ALLEGRO_EVENT_TIMER)
            {



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
