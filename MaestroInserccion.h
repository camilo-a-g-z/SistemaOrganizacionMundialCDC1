#ifndef M_INSERCCION_H
#define M_INSERCCION_H
#include <iostream>
#include "Lista.h"
#include "multiLista.h"
#include "Estadios.h"
#include "Equipos.h"
#include "Cronograma.h"
using namespace std;


class MaestroInserccion
{
	private:
        Multilista jugadores;
        Estadios estadios;
        Equipos equipos;
        Cronograma cronograma;
        string posEquipos = new string[32];
        int grupoEquipos = new int[32];//del 0 al 3 grupo A, del 4 al 7 grupo B, del 8 al 11 grupo C, del 12 al 15 grupo D, del 16 al 19 grupo E, del 20 al 23 grupo F, del 24 al 27 grupo G, del 28 al 31 grupo H
	public:
        //constructor
        MaestroInserccion(){
        }
        void insertarEquipos();
        void insertarJugadores();
        void insertarEstadios();
        void insertarCronograma();
        void insertarDesdeCero();
        //destructores
        ~MaestroInserccion(){
            jugadores.~Multilista();
            estadios.~Estadios();
            equipos.~Equipos();
            cronograma.~Cronograma();
        }
        
};

void MaestroInserccion::insertarDesdeCero(){
    insertarEquipos();
    insertarJugadores();
    insertarEstadios();
}

void MaestroInserccion::insertarEquipos(){
    cout<<"\n\nEmpezaremos con la inserccion de los 8 equipos participantes en el mundial\n\n";
    Equipo e;
    for(int i=0;i<32;i++){
        cout<<"Equipo "<<i+1<<" a insertar"<<endl;
        cout<<"Ingrese el nombre del equipo: ";cin>>e.nombre;
        cout<<"Ingrese la confederacion a la que pertenece: ";cin>>e.confederacion;
        cout<<"Ingrese el nombre del entrenador: ";cin>>e.nombreEntrenador;
        cout<<"Ingrese el apellido del entrenador: ";cin>>e.apellidoEntrenador;
        cout<<"Ingrese la nacionalidad del entrenador: ";cin>>e.nacionalidadEntrenador;
        cout<<"Ingrese el grupo al que pertenece: ";cin>>grupoEquipos[i];
        posEquipos[i]=e.nombre; 
        int x = equipos.insertar(e);
        cout<<"Equipo insertado con exito"<<endl;
    }
    cout<<"\n\nEquipos insertados con exito\n\n";
}

void MaestroInserccion::insertarJugadores(){
    cout<<"\n\nAhora insertaremos los jugadores de cada equipo\n\n";
    for(int i=0;i<32;i++){
        cout<<"Insertando jugadores del equipo "<<posEquipos[i]<<endl;
        cout<<"Ingrese el numero de jugadores del equipo: ";cin>>j.numJugadores;
        for(int j=0;j<j.numJugadores;j++){
            string nombre;
            cout<<"Nombre del jugador: ";cin>>nombre;
            int edad;
            cout<<"Edad del jugador: ";cin>>edad;
            int numCamiseta;
            int cantGoles = 0;
            string posicion;
            cout<<"Posicion del jugador: ";cin>>posicion;
            jugadores.insertar(nombre,edad,numCamiseta,cantGoles,posicion,i);
            cout<<"Jugador insertado con exito"<<endl;
        }
    }
    cout<<"\n\nJugadores insertados con exito\n\n";
}

void MaestroInserccion::insertarEstadios(){
    cout<<"\n\nAhora insertaremos los estadios del mundial\n\n";
    Estadio e;
    for(int i=0;i<8;i++){
        cout<<"Estadio "<<i+1<<" a insertar"<<endl;
        cout<<"Ingrese el nombre del estadio: ";cin>>e.nombre;
        cout<<"Ingrese la ciudad en la que se encuentra: ";cin>>e
        cout<<"Ingrese la capacidad del estadio: ";cin>>e.capacidad;
    }
}
#endif