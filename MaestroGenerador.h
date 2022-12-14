#ifndef M_GENERADOR_H
#define M_GENERADOR_H
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include "Lista.h"
#include "multiLista.h"
#include "Estadios.h"
#include "Equipos.h"
#include "Cronograma.h"
using namespace std;


class MaestroGenerador
{
	private:
        Cronograma cronograma;
	public:
        //constructor
        MaestroGenerador(){}
        //metodo para recivir una fecha y estadios y generar un cronograma y lo guarda en cronograma
        void generarCronograma(Estadios estadios, Equipos equipos, int grupoEquipos[]);
        randomEstadio(Estadios estadios);
        //getter
        Cronograma getCronograma(){return cronograma;}
        
};

void MaestroGenerador::generarCronograma(Estadios estadios, Equipos equipos, int *grupoEquipos){
    //se deben generar 64 partidos donde 48 son de eliminacion, 8 de octavos, 4 de cuartos, 2 de semifinales, 1 de final y 1 de tercer puesto
    //primeramente se debe generar los partidos de eliminacion
    cout<<"Entro a generar cronograma"<<endl;
    int dia = 0;
    for(int i = 0; i<32; i= i+4){
        string grupo;
        switch(i/4){
            case 0:
                grupo = "A";
                break;
            case 1:
                grupo = "B";
                break;
            case 2:
                grupo = "C";
                break;
            case 3:
                grupo = "D";
                break;
            case 4:
                grupo = "E";
                break;
            case 5:
                grupo = "F";
                break;
            case 6:
                grupo = "G";
                break;
            case 7:
                grupo = "H";
                break;
        }
        //por dia es un partido
        cronograma.insertar(0,i,i+1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora","""Eliminacion",grupo);
        cronograma.insertar(1,i+2,i+3,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora","Eliminacion",grupo);
        dia++;
        cronograma.insertar(2,i,i+2,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Eliminacion",grupo);
        cronograma.insertar(3,i+1,i+3,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Eliminacion",grupo);
        dia++;
        cronograma.insertar(4,i,i+3,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Eliminacion",grupo);
        cronograma.insertar(5,i+1,i+2,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Eliminacion",grupo);
        dia++;
    }
    //los -1 a continuacion son para indicar que no hay equipo definido en ese partido
    //luego se deben generar los partidos de octavos
    string seccion;
    for(int i = 48; i<56; i++){
        switch(i){
            case 48:
                seccion = "A";
                break;
            case 49:
                seccion = "B";
                break;
            case 50:
                seccion = "C";
                break;
            case 51:
                seccion = "D";
                break;
            case 52:
                seccion = "E";
                break;
            case 53:
                seccion = "F";
                break;
            case 54:
                seccion = "G";
                break;
            case 55:
                seccion = "H";
                break;
        }
        cronograma.insertar(i-48,-1,-1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Octavos",seccion);
        dia++;
    }
    //luego se deben generar los partidos de cuartos
    for(int i = 56; i<60; i++){
        switch(i){
            case 56:
                seccion = "A";
                break;
            case 57:
                seccion = "B";
                break;
            case 58:
                seccion = "C";
                break;
            case 59:
                seccion = "D";
                break;
        }
        cronograma.insertar(i-56,-1,-1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(),"Hora", "Cuartos",seccion);
        dia++;
    }
    //luego se deben generar los partidos de semifinales
    for(int i = 60; i<62; i++){
        switch(i){
            case 60:
                seccion = "A";
                break;
            case 61:
                seccion = "B";
                break;
        }
        cronograma.insertar(i-60,-1,-1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(), "Hora", "Semifinales",seccion);
        dia++;
    }
    //luego se debe generar el partido de tercer puesto
    cronograma.insertar(0,-1,-1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(), "Hora", "Tercer puesto","A");
    dia++;
    //luego se debe generar el partido de final
    cronograma.insertar(1,-1,-1,static_cast<ostringstream*>( &(ostringstream() << dia) )->str(), "Hora", "Final","A");
    //guardar en cronograma
}
#endif
