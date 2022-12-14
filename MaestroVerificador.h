#ifndef MAESTROVERIFICADOR_H
#define MAESTROVERIFICADOR_H
#include <iostream>
#include "Lista.h"
#include "multiLista.h"
#include "Estadios.h"
#include "Equipos.h"
#include "Cronograma.h"

using namespace std;

class MaestroVerificador {
    private:
        Lista<futbolista> jugadores;
        Lista<Estadio> estadios;
        Lista<Equipo> equipos;
        Lista<partido> partidos;

    public: 
        void recuperarDatos();
        void infoArchivo();
        //getters
        Lista<futbolista> getJugadores(){return jugadores;}
        Lista<Estadio> getEstadios(){return estadios;}
        Lista<Equipo> getEquipos(){return equipos;}
        Lista<partido> getPartidos(){return partidos;}
};

void MaestroVerificador::recuperarDatos() {
    Multilista m = Multilista();
    Cronograma c = Cronograma();
    Estadios e = Estadios();
    Equipos eq = Equipos();

    jugadores = m.leerJugadoresArchivo();
    partidos = c.leerPartidosArchivo();
    estadios = e.leerEstadiosArchivo();
    equipos = eq.leerEquiposArchivo();

}






#endif