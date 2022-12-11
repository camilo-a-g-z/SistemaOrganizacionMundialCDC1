#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct partido{
    int idEstadio;
    int idEquipo1;
    int idEquipo2;
    string fecha;
    string hora;
    string etapa;//eliminacion, cuartos....final
    string seccion;//Grupo A,Grupo B ....
    int golesEquipo1;
    int golesEquipo2;
    int suplementario1;
    int suplementario2;
    int penales1;
    int penales2;
    int posEnLista;
};

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
        void insertar(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string etapa, string seccion);
        Lista<partido> obtenerPartidosPorEtapa(string etapa);
        Lista<partido> obtenerPartidosPorEquipo(int idEquipo);
        Lista<partido> obtenerPartidosPorEstadio(int idEstadio);
        Lista<partido> obtenerPartidosPorEtapaYSeccion(string etapa, string seccion);
        Lista<partido> obtenerPartidosPorFecha(string fecha);
        void modificarPartido(int posEnLista, partido partido);
        
        
};

void Cronograma::insertar(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string etapa, string seccion){
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

Lista<partido> Cronograma::obtenerPartidosPorEtapa(string etapa){
    Lista<partido> partidosEtapa;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
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
        partido=partidos.ObtenerDatos(i);
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
        partido=partidos.ObtenerDatos(i);
        if(partido.idEstadio==idEstadio){
            partidosEstadio.Insertar(partido);
        }
    }
    return partidosEstadio;
}
//metodo para obtener una lista de partidos de una etapa y seccion
Lista<partido> Cronograma::obtenerPartidosPorEtapaYSeccion(string etapa, string seccion){
    Lista<partido> partidosEtapaSeccion;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.etapa==etapa && partido.seccion==seccion){
            partidosEtapaSeccion.Insertar(partido);
        }
    }
    return partidosEtapaSeccion;
}
//metodo para obtener una lista de partidos de una fecha
Lista<partido> Cronograma::obtenerPartidosPorFecha(string fecha){
    Lista<partido> partidosFecha;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.fecha==fecha){
            partidosFecha.Insertar(partido);
        }
    }
    return partidosFecha;
}
//metodo para modificar un partido
void Cronograma::modificarPartido(int posEnLista, partido partido){
    partidos.modificar(posEnLista,partido);
}

#endif
