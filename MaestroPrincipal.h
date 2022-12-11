#ifndef M_PRINCIPAL_H
#define M_PRINCIPAL_H
#include <iostream>
#include<stdlib.h>
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
        Estadios estadios;
        Equipos equipos;
        Cronograma cronograma;
        Multilista jugadores;
	public:
        //constructor
        MaestroPrincipal(){}
        
        //metodo para iniciar el programa
        void inicio();
        void menu();
        void verEquipos();
        void verJugadores();
        void verEstadios();
        //getter
        
        
};

void MaestroPrincipal::inicio(){
    //intentamos rescatar los archivos de datos, en caso de estar vacios se dirige a maestro insercion
    if(false){

    }else{
        MaestroInserccion mI;
        mI.insertarDesdeCero();

        estadios=mI.getEstadios();
        equipos=mI.getEquipos();
        cronograma=mI.getCronograma();
        jugadores=mI.getJugadores();

        cout<<"Se ha insertado desde cero"<<endl;
		MaestroGenerador mG;
		mG.generarCronograma(mI.getEstadios(),mI.getEquipos(),mI.getGrupoEquipos());
    }
    menu();
    
}

void MaestroPrincipal::menu(){
    //system("cls");
    cout<<"\n\nBienvenido al menu principal del mundial de futbol\n\n";
    cout<<"1. Ver equipos.\n";
    cout<<"2. Ver jugadores.\n";
    cout<<"3. Ver estadios.\n";
    cout<<"4. Ver cronograma.\n";
    cout<<"5. Poner el resultado de un partido.\n";
    cout<<"6. Modificar un equipo.\n";
    cout<<"7. Modificar un jugador.\n";
    cout<<"8. Salir.\n";
    cout<<"Ingrese la opcion que desea: ";
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            verEquipos();
            break;
        case 2:
            verJugadores();
            break;
        case 3:
            verEstadios();
            break;
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:
            
            break;
        case 7:
            
            break;
        case 8:
            exit(0);
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            menu();
            break;
    }
}

void MaestroPrincipal::verEquipos(){
    //system("cls");
    cout<<"\n\nEquipos participantes en el mundial\n\n";
    for(int i=0;i<32;i++){
        cout<<i+1<<". Nombre del equipo: "<<equipos.obtenerEquipo(i).nombre<<endl;
        cout<<"   Confederacion: "<<equipos.obtenerEquipo(i).confederacion<<endl;
        cout<<"   Puntos: "<<equipos.obtenerEquipo(i).puntos<<endl;
        cout<<"   Partidos jugados: "<<equipos.obtenerEquipo(i).partidosJugados<<endl;
        cout<<"   Partidos ganados: "<<equipos.obtenerEquipo(i).partidosGanados<<endl;
        cout<<"   Partidos empatados: "<<equipos.obtenerEquipo(i).partidosEmpatados<<endl;
        cout<<"   Partidos perdidos: "<<equipos.obtenerEquipo(i).partidosPerdidos<<endl;
        cout<<"   Goles a favor: "<<equipos.obtenerEquipo(i).golesFavor<<endl;
        cout<<"   Goles en contra: "<<equipos.obtenerEquipo(i).golesContra<<endl;
        cout<<"   Tarjetas amarillas: "<<equipos.obtenerEquipo(i).tarjetasAmarillas<<endl;
        cout<<"   Tarjetas rojas: "<<equipos.obtenerEquipo(i).tarjetasRojas<<endl;
        cout<<"   Nombre del entrenador: "<<equipos.obtenerEquipo(i).nombreEntrenador<<endl;
        cout<<"   Apellido del entrenador: "<<equipos.obtenerEquipo(i).apellidoEntrenador<<endl;
        cout<<"   Nacionalidad del entrenador: "<<equipos.obtenerEquipo(i).nacionalidadEntrenador<<endl;
    }
    system("pause");
    menu();
}

void MaestroPrincipal::verJugadores(){
    Lista<futbolista> jugadoresEquipo;
    //system("cls");
    cout<<"Seleccione el equipo del cual desea ver los jugadores: "<<endl;
    for(int i=0;i<32;i++){
        cout<<i+1<<". "<<equipos.obtenerEquipo(i).nombre<<endl;
    }
    cout<<"Ingrese la opcion que desea: ";
    int opcion;
    cin>>opcion;
    jugadoresEquipo=jugadores.mostrarEquipo(opcion-1);
    //system("cls");
    for(int i=1;i<=jugadoresEquipo.TamLista();i++){
        futbolista jugador = jugadoresEquipo.ObtenerDatos(i);
        cout<<i<<". Nombre: "<<jugador.nombre<<endl;
        cout<<"   Posicion: "<<jugador.pos<<endl;
        cout<<"   Numero de camiseta: "<<jugador.numCamiseta<<endl;
        cout<<"   Goles: "<<jugador.cantGoles<<endl;
    }
    system("pause");
    menu();
}

void MaestroPrincipal::verEstadios(){
    //system("cls");
    cout<<"\n\nEstadios participantes en el mundial\n\n";
    for(int i=0;i<estadios.getTam();i++){
        Estadio estadio = estadios.obtenerEstadio(i);
        cout<<i+1<<". Nombre del estadio: "<<estadio.nombre<<endl;
        cout<<"   Ciudad: "<<estadio.ciudad<<endl;
        cout<<"   Capacidad: "<<estadio.capacidad<<endl;
    }
    system("pause");
    menu();
}
#endif
