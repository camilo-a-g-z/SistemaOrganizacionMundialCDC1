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
        void generarCronograma(string dia, string mes, string anio, Estadios estadios);
        //destructor
        ~MaestroGenerador(){}
};

void MaestroGenerador::generarCronograma(string dia, string mes, string anio,Estadios estadios){
    //se deben generar 64 partidos donde 48 son de eliminacion, 8 de octavos, 4 de cuartos, 2 de semifinales, 1 de final y 1 de tercer puesto
    //primeramente se debe generar los partidos de eliminacion
    bool partidoPorDia = false;
    for(int i = 0; i<48; i++){
        //por dia es un partido
        if(partidoPorDia){
            cronograma.insertar(randomEstadio,-1,-1,""+i,"Eliminacion","Aqui debo meter la seccion pero estoy demaciado cansado para hacerlo ._.");
        }
    }
    
    //guardar en cronograma
}
//metodo para devolver aleatoriamente un estadio
int MaestroGenerador::randomEstadio(Estadios estadios){
    int random = rand() % 8;
    return estadios.obtenerEstadio(random).idEstadio;
}

#endif