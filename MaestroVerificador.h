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
        Multilista jugadores;
    	Estadios estadios;
        Equipos equipos;
        Cronograma partidos;

    public: 
        void recuperarDatos();
        bool infoArchivo();
        //getters
        Multilista getJugadores(){return jugadores;}
        Estadios getEstadios(){return estadios;}
        Equipos getEquipos(){return equipos;}
        Cronograma getPartidos(){return partidos;}
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
    ifstream archivoPartidos("partidos.txt");
    ifstream archivoEstadios("estadios.txt");
    ifstream archivoEquipos("equipos.txt");
    ifstream archivoCabeceras("cabeceras.txt");
    ifstream archivoEstadiosIDS("estadiosIDS.txt");
    ifstream archivoGrupoEquipos("grupoEquipos.txt");
    ifstream archivoPosEquipos("posEquipos.txt");
   
    if (archivoJugadores.is_open() && archivoPartidos.is_open() && archivoEstadios.is_open() && archivoEquipos.is_open() && archivoCabeceras.is_open() && archivoEstadiosIDS.is_open() && archivoGrupoEquipos.is_open() && archivoPosEquipos.is_open()) {
        if (archivoJugadores.peek() == std::ifstream::traits_type::eof() || archivoPartidos.peek() == std::ifstream::traits_type::eof() || archivoEstadios.peek() == std::ifstream::traits_type::eof() || archivoEquipos.peek() == std::ifstream::traits_type::eof() || archivoCabeceras.peek() == std::ifstream::traits_type::eof() || archivoEstadiosIDS.peek() == std::ifstream::traits_type::eof() || archivoGrupoEquipos.peek() == std::ifstream::traits_type::eof() || archivoPosEquipos.peek() == std::ifstream::traits_type::eof()) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}




#endif
