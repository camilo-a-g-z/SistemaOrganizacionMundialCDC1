#ifndef M_PRINCIPAL_H
#define M_PRINCIPAL_H
#include <iostream>
#include "Lista.h"
#include "multiLista.h"
#include "Estadios.h"
#include "Equipos.h"
#include "Cronograma.h"
#include "MaestroGenerador.h"
#include "MaestroInserccion.h"
using namespace std;


class MaestroPrincipal
{
	private:
        
	public:
        //constructor
        MaestroPrincipal(){}
        
        //metodo para iniciar el programa
        void inicio();
        //getter
        
        //destructor
        ~MaestroPrincipal(){}
};

void MaestroPrincipal::inicio(){
    //intentamos rescatar los archivos de datos, en caso de estar vacios se dirige a maestro insercion
    if(false){

    }else{
        MaestroInserccion mI;
        mI.insertarDesdeCero();;
    }
}

#endif