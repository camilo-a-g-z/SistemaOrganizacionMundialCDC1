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
        bool infoArchivo();
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


//Verifica que los archivos no estan vacios
bool MaestroVerificador::infoArchivo() {
    ifstream archivoJugadores("jugadores.txt");
    ifstream archivoPartidos("Cronograma.txt");
    ifstream archivoEstadios("estadios.txt");
    ifstream archivoEquipos("equipos.txt");

    if (archivoJugadores.is_open() && archivoPartidos.is_open() && archivoEstadios.is_open() && archivoEquipos.is_open()) {
        if (archivoJugadores.peek() == std::ifstream::traits_type::eof() || archivoPartidos.peek() == std::ifstream::traits_type::eof() || archivoEstadios.peek() == std::ifstream::traits_type::eof() || archivoEquipos.peek() == std::ifstream::traits_type::eof()) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}




#endif
