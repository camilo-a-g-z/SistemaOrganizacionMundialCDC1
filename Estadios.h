#ifndef ESTADIOS_H
#define ESTADIOS_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct Estadio{
    string nombre;
    string ciudad;
    int capacidad;
    int idEstadio;
    int numEnLista;
};

class Estadios
{
	private:
        Lista<Estadio> estadios;
        int tam;
        int idEstadioActual;
	public:
        //constructor
        Estadios(){
            tam=0;
            idEstadioActual=0;
        }
        int insertar(string nombre, string ciudad, int capacidad);
        Estadio obtenerEstadio(int id);
        Estadio obtenerEstadioPorPosicion(int pos);
        void modificarEstadio(int id, Estadio estadio);
        //destructor
        ~Estadios(){
            estadios.~Lista();
        }
        
};

int Estadios::insertar(string nombre, string ciudad, int capacidad){
    Estadio estadio;
    estadio.nombre=nombre;
    estadio.ciudad=ciudad;
    estadio.capacidad=capacidad;
    estadio.idEstadio=idEstadioActual;
    estadio.numEnLista=tam;
    estadios.Insertar(estadio);
    idEstadioActual++;
    tam++;
    return 0;
}
//metodo para obtener un estadio por su id
Estadio Estadios::obtenerEstadio(int id){
    Estadio estadio;
    for(int i=1;i<=tam;i++){
        estadio=estadios.ObtenerDatos(i);
        if(estadio.idEstadio==id){
            return estadio;
        }
    }
    return estadio;
}
//metodo para obtener un estadio por su posicion en la lista
Estadio Estadios::obtenerEstadioPorPosicion(int pos){
    Estadio estadio;
    for(int i=1;i<=tam;i++){
        estadio=estadios.ObtenerDatos(i);
        if(estadio.numEnLista==pos){
            return estadio;
        }
    }
    return estadio;
}
//metodo para modificar un estadio
void Estadios::modificarEstadio(int id, Estadio estadio){
    estadios.modificar(id, estadio);
}

#endif
