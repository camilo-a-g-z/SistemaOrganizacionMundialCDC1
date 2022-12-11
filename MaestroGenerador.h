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
    //se deben generar 64 partidos
    
    //guardar en cronograma
}

#endif