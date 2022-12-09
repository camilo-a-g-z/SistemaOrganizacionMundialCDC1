//multilista.h
#ifndef MULTILISTA_H
#define MULTILISTA_H
#include "Lista.h"

using namespace std;

//Estructura para el manejo de la Multilista
struct futbolista {
	string nombre, pos;
	int edad, numCamiseta;
	int cantGoles;
    int sigCantGoles;
    int sigCompañero;
};

//Creaci?n de la clase Multilista
class Multilista{
	private:
		//Atributos de la Multilista 
		int *cabeceras;
		futbolista *datos;
		int tam;
		
	public:
		//Metodo Constructor (inicializacion de los atributos de la Multilista)
		Multilista(){
			cabeceras=new int[50];
			/*
			* 0: equipo/pais 1
			* 1: equipo/pais 2
			* ...
			* 31: equipo/pais 32
			* 32: cantidad de goles 1
			*/
            datos=new futbolista[835];
			tam=0;

            for(int i=0; i<50; i++){
                cabeceras[i]=-1;
            }
			for(int i=0; i<835; i++){
                datos[i].nombre="";
                datos[i].edad=0;
                datos[i].numCamiseta=0;
                datos[i].cantGoles=0;
                datos[i].pos="";
                datos[i].sigCantGoles=-1;
                datos[i].sigCompañero=-1;
            }
		}
		
		//Destructor
		~Multilista(){
			delete[] datos;
			delete[] cabeceras;
		}
		
		//Metodos (acciones) de la Multilista
		bool insertar(string nombre, string edad, int numCamiseta, int cantGoles, string pos, int equipo);
		bool eliminar(int pos);
		bool multilistaLLena();
		bool multilistaVacia();
		Lista<jugadores> mostrarEquipo(int equipo);
		Lista<jugadores> mostrarGolesPorEquipo(int equipo);
		Lista<jugadores> mostrarGolesGlobal();
		futbolista getFutbolista(int pos);
		void insertarDatosArchivo(string nombre, string edad, int numCamiseta, int cantGoles, string pos, int equipo, int sigCantGoles, int sigCompañero);
};

bool Multilista :: multilistaVacia(){
	return tam==0;
}

bool Multilista :: multilistaLLena(){
	return tam==835;
}

bool Multilista :: insertar(string nombre, string edad, int numCamiseta, int cantGoles, string pos, int equipo){
	if(multilistaLLena()) return false;
	
	futbolista f;
    f.nombre=nombre;
    f.edad=edad;
    f.numCamiseta=numCamiseta;
    f.cantGoles=cantGoles;
    f.pos=pos;

	int k;
	int i=0;
	while(datos[i].nombre != "" && i<835){
		i++;
	}

	//insertar en la lista de datos
	datos[i]=f;
	//insertar en la lista de cabeceras a partir de la posicion del equipo
	if(cabeceras[equipo]==-1){
		cabeceras[equipo]=i;
	}
	else{
		k=cabeceras[equipo];
		while(datos[k].sigCompañero != -1){
			k=datos[k].sigCompañero;
		}
		datos[k].sigCompañero=i;
	}
	//insertar en la lista de cabeceras a partir de la posicion de la cantidad de goles en orden ascendente
	if(cabeceras[32]==-1){
		cabeceras[32]=i;
	}
	else{
		k=cabeceras[32];
		cantGoles=datos[k].cantGoles;
		while(datos[k].sigCantGoles != -1 && datos[k].cantGoles < cantGoles){
			k=datos[k].sigCantGoles;
		}
		datos[i].sigCantGoles=datos[k].sigCantGoles;
		datos[k].sigCantGoles=i;
	}
	tam++;
	return true;
}
Lista<jugadores> Multilista::mostrarEquipo(int equipo){
	Lista l;
	int k=cabeceras[equipo];
	while(k!=-1){
		l.Insertar(datos[k].nombre);
		k=datos[k].sigCompañero;
	}
	return l;
}
//crear un metodo que muestre los jugadores de un equipo en orden ascendente de goles
Lista<jugadores> Multilista::mostrarGolesPorEquipo(int equipo){
	Lista l;
	int k=cabeceras[equipo];
	while(k!=-1){
		l.Insertar(datos[k].cantGoles);
		k=datos[k].sigCantGoles;
	}
	return l;
}
//crear un metodo que muestre todos los jugadores en orden ascendente de goles
Lista<jugadores> Multilista::mostrarGolesGlobal(){
	Lista l;
	int k=cabeceras[32];
	while(k!=-1){
		l.Insertar(datos[k].cantGoles);
		k=datos[k].sigCantGoles;
	}
	return l;
}
//se crea un metodo que retorne la estructura futbolista acorde a la posicion que se le pase
futbolista Multilista::getFutbolista(int pos){
	return datos[pos];
}
//funcion para insertar en la lista de datos de la multilista
void Multilista::insertarDatosArchivo(string nombre, string edad, int numCamiseta, int cantGoles, string pos, int equipo, int sigCantGoles, int sigCompañero){
	futbolista f;
	f.nombre=nombre;
	f.edad=edad;
	f.numCamiseta=numCamiseta;
	f.cantGoles=cantGoles;
	f.pos=pos;
	f.sigCantGoles=sigCantGoles;
	f.sigCompañero=sigCompañero;
	while(datos[tam].nombre != ""){
		tam++;
	}
	datos[tam]=f;
}

#endif