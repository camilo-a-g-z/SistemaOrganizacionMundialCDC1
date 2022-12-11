#ifndef M_GENERADOR_H
#define M_GENERADOR_H
#include <iostream>
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
        void generarCronograma(Estadios estadios, Equipos equipos);
        //getter
        Cronograma getCronograma(){return cronograma;}
        //destructor
        ~MaestroGenerador(){}
};

void MaestroGenerador::generarCronograma(Estadios estadios, Equipos equipos, int grupoEquipos[]){
    //se deben generar 64 partidos donde 48 son de eliminacion, 8 de octavos, 4 de cuartos, 2 de semifinales, 1 de final y 1 de tercer puesto
    //primeramente se debe generar los partidos de eliminacion
    int dia = 0;
    bool partidoPorDia = false;
    for(int i = 0; i<48; i+=4){
        //por dia es un partido
        cronograma.insertar(randomEstadio(estadios),i,i+1,""+dia,"Eliminacion",grupoEquipos[i]);
        cronograma.insertar(randomEstadio(estadios),i+2,i+3,""+dia,"Eliminacion",grupoEquipos[i]);
        dia++;
        cronograma.insertar(randomEstadio(estadios),i,i+2,""+dia,"Eliminacion",grupoEquipos[i]);
        cronograma.insertar(randomEstadio(estadios),i+1,i+3,""+dia,"Eliminacion",grupoEquipos[i]);
        dia++;
        cronograma.insertar(randomEstadio(estadios),i,i+3,""+dia,"Eliminacion",grupoEquipos[i]);
        cronograma.insertar(randomEstadio(estadios),i+1,i+2,""+dia,"Eliminacion",grupoEquipos[i]);
        dia++;
    }
    //los -1 a continuacion son para indicar que no hay equipo definido en ese partido
    //luego se deben generar los partidos de octavos
    string seccion;
    for(int i = 48; i<56; i+=2){
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
        cronograma.insertar(randomEstadio(estadios),-1,-1,""+dia,"Octavos",seccion);
        dia++;
    }
    //luego se deben generar los partidos de cuartos
    for(int i = 56; i<60; i+=2){
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
        cronograma.insertar(randomEstadio(estadios),-1,-1,""+dia,"Cuartos",seccion);
        dia++;
    }
    //luego se deben generar los partidos de semifinales
    for(int i = 60; i<62; i+=2){
        switch(i){
            case 60:
                seccion = "A";
                break;
            case 61:
                seccion = "B";
                break;
        }
        cronograma.insertar(randomEstadio(estadios),-1,-1,""+dia,"Semifinales",seccion);
        dia++;
    }
    //luego se debe generar el partido de tercer puesto
    cronograma.insertar(randomEstadio(estadios),-1,-1,""+dia,"Tercer puesto","A");
    dia++;
    //luego se debe generar el partido de final
    cronograma.insertar(randomEstadio(estadios),-1,-1,""+dia,"Final","A");
    //guardar en cronograma
}
//metodo para devolver aleatoriamente un estadio
int MaestroGenerador::randomEstadio(Estadios estadios){
    int random = rand() % 8;
    return estadios.obtenerEstadio(random).idEstadio;
}

#endif