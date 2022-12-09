#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct Equipo{
    //datos del equipo
    string nombre;//pais
    String confederacion;
    int puntos;
    int partidosJugados;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;
    int golesFavor;
    int golesContra;
    int tarjetasAmarillas;
    int tarjetasRojas;
    //datos del entrenador
    string nombreEntrenador;
    string apellidoEntrenador;
    string nacionalidadEntrenador;
    //numero identificador para asociar con multilista
    int idEquipo;
    int numEnLista;
}

class Equipos
{
	private:
		Lista<Equipo> equipos;
        int tam;
        int idEquipoActual;
	public:
        //constructor
        Equipos(){
            tam=0;
            idEquipoActual=0;
        }
        int insertar(string nombre, string confederacion, string nombreEntrenador, string apellidoEntrenador, string nacionalidadEntrenador);
        Equipo obtenerEquipo(int id);
        Equipo obtenerEquipoPorPosicion(int pos);
        void modificarEquipo(int id, Equipo equipo);
        //destructor
        ~Equipos(){
            equipos.~Lista();
        }
};

int Equipos::insertar(Equipo e){
    e.puntos=0;
    e.partidosJugados=0;
    e.partidosGanados=0;
    e.partidosEmpatados=0;
    e.partidosPerdidos=0;
    e.golesFavor=0;
    e.golesContra=0;
    e.tarjetasAmarillas=0;
    e.tarjetasRojas=0;
    e.idEquipo=idEquipoActual;
    idEquipoActual++;
    e.numEnLista=tam+1;
    equipos.insertar(e);
    tam++;
    return e.idEquipo;
}

int Equipos::insertar(string nombre, string confederacion, string nombreEntrenador, string apellidoEntrenador, string nacionalidadEntrenador){
    Equipo equipo;
    equipo.nombre=nombre;
    equipo.confederacion=confederacion;
    equipo.puntos=0;
    equipo.partidosJugados=0;
    equipo.partidosGanados=0;
    equipo.partidosEmpatados=0;
    equipo.partidosPerdidos=0;
    equipo.golesFavor=0;
    equipo.golesContra=0;
    equipo.tarjetasAmarillas=0;
    equipo.tarjetasRojas=0;
    equipo.nombreEntrenador=nombreEntrenador;
    equipo.apellidoEntrenador=apellidoEntrenador;
    equipo.nacionalidadEntrenador=nacionalidadEntrenador;
    equipo.idEquipo=idEquipoActual;
    idEquipoActual++;
    equipo.numEnLista=tam+1;
    equipos.Insertar(equipo);
    tam++;
    retun equipo.idEquipo;
}

//metodo para obtener un equipo por su id
Equipo Equipos::obtenerEquipo(int id){
    Equipo equipo;
    for(int i=1;i<=tam;i++){
        equipo=equipos.ObtenerDatos(i);
        if(equipo.idEquipo==id){
            return equipo;
        }
    }
}

//metodo para obtener un equipo por su posicion en la lista
Equipo Equipos::obtenerEquipoPorPosicion(int pos){
    return equipos.ObtenerDatos(pos);
}

//metodo para modificar un equipo por su id recibiendo un equipo
void Equipos::modificarEquipo(int id, Equipo equipo){
    for(int i=1;i<=tam;i++){
        if(equipos.ObtenerDatos(i).idEquipo==id){
            equipos.modificar(i,equipo);
        }
    }
}

#endif