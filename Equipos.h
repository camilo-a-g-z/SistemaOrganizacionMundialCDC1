#ifndef EQUIPOS_H
#define EQUIPOS_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct Equipo{
    //datos del equipo
    string nombre;//pais
    string confederacion;
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
};

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
        void insertarEquipoArchivo(string nombre, string confederacion, string nombreEntrenador, string apellidoEntrenador, string nacionalidadEntrenador, int puntos, int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int idEquipo, int numEnLista);
        void guardarEquiposArchivo(string nombreArchivo);
        Equipo obtenerEquipo(int id);
        Equipo obtenerEquipoPorPosicion(int pos);
        void modificarEquipo(int id, Equipo equipo);
        int insertar(Equipo e);
        
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
    equipos.Insertar(e);
    tam++;
    //impresion de toda la estructura para testeo
    cout<<"nombre: "<<e.nombre<<endl;
    cout<<"confederacion: "<<e.confederacion<<endl;
    cout<<"nombreEntrenador: "<<e.nombreEntrenador<<endl;
    cout<<"apellidoEntrenador: "<<e.apellidoEntrenador<<endl;
    cout<<"nacionalidadEntrenador: "<<e.nacionalidadEntrenador<<endl;
    cout<<"idEquipo: "<<e.idEquipo<<endl;
    cout<<"numEnLista: "<<e.numEnLista<<endl;

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
    //impresion de toda la estructura para testeo
    cout<<"nombre: "<<equipo.nombre<<endl;
    cout<<"confederacion: "<<equipo.confederacion<<endl;
    cout<<"nombreEntrenador: "<<equipo.nombreEntrenador<<endl;
    cout<<"apellidoEntrenador: "<<equipo.apellidoEntrenador<<endl;
    cout<<"nacionalidadEntrenador: "<<equipo.nacionalidadEntrenador<<endl;
    cout<<"idEquipo: "<<equipo.idEquipo<<endl;
    cout<<"numEnLista: "<<equipo.numEnLista<<endl;
    
    return equipo.idEquipo;
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
 
void Equipos::insertarEquipoArchivo(string nombre, string confederacion, string nombreEntrenador, string apellidoEntrenador, string nacionalidadEntrenador, int puntos, int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int idEquipo, int numEnLista){
    Equipos();
    Equipo equipo;
    equipo.nombre=nombre;
    equipo.confederacion=confederacion;
    equipo.puntos=puntos;
    equipo.partidosJugados=partidosJugados;
    equipo.partidosGanados=partidosGanados;
    equipo.partidosEmpatados=partidosEmpatados;
    equipo.partidosPerdidos=partidosPerdidos;
    equipo.golesFavor=golesFavor;
    equipo.golesContra=golesContra;
    equipo.tarjetasAmarillas=tarjetasAmarillas;
    equipo.tarjetasRojas=tarjetasRojas;
    equipo.nombreEntrenador=nombreEntrenador;
    equipo.apellidoEntrenador=apellidoEntrenador;
    equipo.nacionalidadEntrenador=nacionalidadEntrenador;
    equipo.idEquipo=idEquipo;
    idEquipoActual++;
    equipo.numEnLista=tam+1;
    equipos.Insertar(equipo);
    tam++;
}

//Funcion para guardar los equipos en el archivo
void Equipos::guardarEquiposArchivo(string nombreArchivo){
 	ofstream archivo;
	string frase;
	char rpt;	
	archivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
		
	fflush(stdin);
	
    for(int i=1; i<=tam; i++){
		stringstream fr;
		Equipo e = obtenerEquipoPorPosicion(i);
        
        fr << i-1 <<"*" << e.nombre << "*" << e.confederacion << "*" << e.nombreEntrenador << "*" << e.apellidoEntrenador << "*" << e.nacionalidadEntrenador << "*" << e.puntos << "*" << e.partidosJugados << "*" << e.partidosGanados << "*" << e.partidosEmpatados << "*" << e.partidosPerdidos << "*" << e.golesFavor << "*" << e.golesContra << "*" << e.tarjetasAmarillas << "*" << e.tarjetasRojas << "*" << e.idEquipo << "*" << e.numEnLista;
        frase = fr.str();
        cout<<frase;
        archivo<<frase<<endl;           
    }
	Equipos();
	

	
	archivo.close(); //Cerramos el archivo

}

#endif
