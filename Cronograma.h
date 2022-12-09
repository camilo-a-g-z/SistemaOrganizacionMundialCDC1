#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct partido{
    int idEstadio;
    int idEquipo1;
    int idEquipo2;
    String fecha;
    String hora;
    String etapa;//eliminacion, cuartos....final
    String seccion;//Grupo A,Grupo B ....
    int golesEquipo1;
    int golesEquipo2;
    int suplementario1;
    int suplementario2;
    int penales1;
    int penales2;
    int posEnLista;
}

class Cronograma
{
	private:
        Lista<partido> partidos;
        int tam;
	public:
        //constructor
        Cronograma(){
            tam=0;
        }
        void insertar(int idEstadio, int idEquipo1, int idEquipo2, String fecha, String etapa, String seccion);
        Lista<partido> obtenerPartidosPorEtapa(String etapa);
        Lista<partido> obtenerPartidosPorEquipo(int idEquipo);
        Lista<partido> obtenerPartidosPorEstadio(int idEstadio);
        Lista<partido> obtenerPartidosPorEtapaYSeccion(String etapa, String seccion);
        Lista<partido> obtenerPartidosPorFecha(String fecha);
        void modificarPartido(int posEnLista, partido partido);
        //destructor
        ~Cronograma(){
            partidos.~Lista();
        }
        
};

void Cronograma::insertar(int idEstadio, int idEquipo1, int idEquipo2, String fecha, String etapa, String seccion){
    partido partido;
    partido.idEstadio=idEstadio;
    partido.idEquipo1=idEquipo1;
    partido.idEquipo2=idEquipo2;
    partido.fecha=fecha;
    partido.etapa=etapa;
    partido.seccion=seccion;
    partido.golesEquipo1=0;
    partido.golesEquipo2=0;
    partido.suplementario1=0;
    partido.suplementario2=0;
    partido.penales1=0;
    partido.penales2=0;
    partido.posEnLista=tam;
    partidos.Insertar(partido);
    tam++;
}

Lista<partido> Cronograma::obtenerPartidosPorEtapa(String etapa){
    Lista<partido> partidosEtapa;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.obtenerPorPosicion(i);
        if(partido.etapa==etapa){
            partidosEtapa.Insertar(partido);
        }
    }
    return partidosEtapa;
}
//metodo para obtener una lista de los partidos de un equipo
Lista<partido> Cronograma::obtenerPartidosPorEquipo(int idEquipo){
    Lista<partido> partidosEquipo;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.obtenerPorPosicion(i);
        if(partido.idEquipo1==idEquipo || partido.idEquipo2==idEquipo){
            partidosEquipo.Insertar(partido);
        }
    }
    return partidosEquipo;
}
//metodo para obtener una lista de los partidos de un estadio
Lista<partido> Cronograma::obtenerPartidosPorEstadio(int idEstadio){
    Lista<partido> partidosEstadio;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.obtenerPorPosicion(i);
        if(partido.idEstadio==idEstadio){
            partidosEstadio.Insertar(partido);
        }
    }
    return partidosEstadio;
}
//metodo para obtener una lista de partidos de una etapa y seccion
Lista<partido> Cronograma::obtenerPartidosPorEtapaYSeccion(String etapa, String seccion){
    Lista<partido> partidosEtapaSeccion;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.obtenerPorPosicion(i);
        if(partido.etapa==etapa && partido.seccion==seccion){
            partidosEtapaSeccion.Insertar(partido);
        }
    }
    return partidosEtapaSeccion;
}
//metodo para obtener una lista de partidos de una fecha
Lista<partido> Cronograma::obtenerPartidosPorFecha(String fecha){
    Lista<partido> partidosFecha;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.obtenerPorPosicion(i);
        if(partido.fecha==fecha){
            partidosFecha.Insertar(partido);
        }
    }
    return partidosFecha;
}
//metodo para modificar un partido
void Cronograma::modificarPartido(int posEnLista, partido partido){
    partidos.modificarPorPosicion(posEnLista,partido);
}

#endif