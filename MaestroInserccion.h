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
        string posEquipos[32];
        int grupoEquipos[32];//del 0 al 3 grupo A, del 4 al 7 grupo B, del 8 al 11 grupo C, del 12 al 15 grupo D, del 16 al 19 grupo E, del 20 al 23 grupo F, del 24 al 27 grupo G, del 28 al 31 grupo H
	public:
        //constructor
        MaestroInserccion(){
        }
        void insertarEquipos();
        void insertarJugadores();
        void insertarEstadios();
        void insertarCronograma();
        void insertarDesdeCero();
        //getters
        Multilista getJugadores(){return jugadores;}
        Estadios getEstadios(){return estadios;}
        Equipos getEquipos(){return equipos;}
        Cronograma getCronograma(){return cronograma;}
        string *getPosEquipos(){return posEquipos;}
        int *getGrupoEquipos(){return grupoEquipos;}
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
        switch(i/4){
            case 0:
                cout<<"Ingrese los datos del equipo del grupo A"<<endl;
                break;
            case 1:
                cout<<"Ingrese los datos del equipo del grupo B"<<endl;
                break;
            case 2:
                cout<<"Ingrese los datos del equipo del grupo C"<<endl;
                break;
            case 3:
                cout<<"Ingrese los datos del equipo del grupo D"<<endl;
                break;
            case 4:
                cout<<"Ingrese los datos del equipo del grupo E"<<endl;
                break;
            case 5:
                cout<<"Ingrese los datos del equipo del grupo F"<<endl;
                break;
            case 6:
                cout<<"Ingrese los datos del equipo del grupo G"<<endl;
                break;
            case 7:
                cout<<"Ingrese los datos del equipo del grupo H"<<endl;
                break;
        }
        //ingreso de datos normal
        /*cout<<"Equipo "<<i+1<<" a insertar"<<endl;
        cout<<"Ingrese el nombre del equipo: ";cin>>e.nombre;
        cout<<"Ingrese la confederacion a la que pertenece: ";cin>>e.confederacion;
        cout<<"Ingrese el nombre del entrenador: ";cin>>e.nombreEntrenador;
        cout<<"Ingrese el apellido del entrenador: ";cin>>e.apellidoEntrenador;
        cout<<"Ingrese la nacionalidad del entrenador: ";cin>>e.nacionalidadEntrenador;*/
        //ingreso de datos para testeo
        cout<<"Equipo "<<i+1<<" a insertar"<<endl;
        cout<<"Ingrese el nombre del equipo: "<<endl;e.nombre = "Equipo"+i;
        cout<<"Ingrese la confederacion a la que pertenece: "<<endl;e.confederacion= "Equipo"+i;
        cout<<"Ingrese el nombre del entrenador: "<<endl;e.nombreEntrenador= "Equipo"+i;
        cout<<"Ingrese el apellido del entrenador: "<<endl;e.apellidoEntrenador= "Equipo"+i;
        cout<<"Ingrese la nacionalidad del entrenador: "<<endl;e.nacionalidadEntrenador= "Equipo"+i;
        string grupo;
        grupoEquipos[i]=i;
        posEquipos[i]=e.nombre; 
        int x = equipos.insertar(e);
        cout<<"Equipo insertado con exito"<<endl;
    }
    cout<<"\n\nEquipos insertados con exito\n\n";
}

void MaestroInserccion::insertarJugadores(){
    cout<<"\n\nAhora insertaremos los jugadores de cada equipo\n\n";
    int numJug=0;
    for(int i=0;i<32;i++){
        cout<<"Insertando jugadores del equipo "<<posEquipos[i]<<endl;
        //ingreso de datos normal
        //cout<<"Ingrese el numero de jugadores del equipo: ";cin>>numJug;
        //ingreso de datos para testeo
        cout<<"Ingrese el numero de jugadores del equipo: ";numJug = 12;
        for(int j=0;j<numJug;j++){
            //ingreso de datos normal
            /*string nombre;
            cout<<"Nombre del jugador: ";cin>>nombre;
            int edad;
            cout<<"Edad del jugador: ";cin>>edad;
            int numCamiseta;
            cout<<"Numero de camiseta: ";cin>>numCamiseta;
            int cantGoles = 0;
            string posicion;
            cout<<"Posicion del jugador: ";cin>>posicion;*/
            //ingreso de datos para testeo
            string nombre;
            cout<<"Nombre del jugador: "<<endl;nombre = "jugador"+j;
            int edad;
            cout<<"Edad del jugador: "<<endl;edad = j;
            int numCamiseta;
            cout<<"Numero de camiseta: "<<endl;numCamiseta = j;
            int cantGoles = 0;
            string posicion;
            cout<<"Posicion del jugador: "<<endl;posicion = "posicion"+j;
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
        cout<<"Ingrese la ciudad en la que se encuentra: ";cin>>e.ciudad;
        cout<<"Ingrese la capacidad del estadio: ";cin>>e.capacidad;
    }
}
//getters y setters

#endif
