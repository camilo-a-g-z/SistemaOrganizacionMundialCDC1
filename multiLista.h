//multilista.h
#ifndef MULTILISTA_H
#define MULTILISTA_H
#include "Lista.h"
#include<fstream>
#include <sstream>  
#include <iostream>

using namespace std;

//Estructura para el manejo de la Multilista
struct futbolista {
	string nombre, pos;
	int edad, numCamiseta;
	int cantGoles;
    int sigCantGoles;
    int sigCompanero;
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
                datos[i].sigCompanero=-1;
            }
		}
		
		//Destructor
		~Multilista(){
			delete[] datos;
			delete[] cabeceras;
		}
		
		//Metodos (acciones) de la Multilista
		bool insertar(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int equipo);
		bool eliminar(int pos);
		bool multilistaLLena();
		bool multilistaVacia();
		void guardarJugadoresArchivo(string nombreArchivo);
		void leerJugadoresArchivo(string nombreArchivo);
		//Lista<jugadores> mostrarEquipo(int equipo);
		//Lista<jugadores> mostrarGolesPorEquipo(int equipo);
		//Lista<jugadores> mostrarGolesGlobal();
		futbolista getFutbolista(int pos);
		void insertarDatosArchivo(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int equipo, int sigCantGoles, int sigCompanero);
};

bool Multilista :: multilistaVacia(){
	return tam==0;
}

bool Multilista :: multilistaLLena(){
	return tam==835;
}

bool Multilista :: insertar(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int equipo){
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
		while(datos[k].sigCompanero != -1){
			k=datos[k].sigCompanero;
		}
		datos[k].sigCompanero=i;
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
/*
Lista<jugadores> Multilista::mostrarEquipo(int equipo){
	Lista l;
	int k=cabeceras[equipo];
	while(k!=-1){
		l.Insertar(datos[k].nombre);
		k=datos[k].sigCompanero;
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
}*/
//se crea un metodo que retorne la estructura futbolista acorde a la posicion que se le pase
futbolista Multilista::getFutbolista(int pos){
	return datos[pos];
}
//funcion para insertar en la lista de datos de la multilista
void Multilista::insertarDatosArchivo(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int equipo, int sigCantGoles, int sigCompanero){
	futbolista f;
	f.nombre=nombre;
	f.edad=edad;
	f.numCamiseta=numCamiseta;
	f.cantGoles=cantGoles;
	f.pos=pos;
	f.sigCantGoles=sigCantGoles;
	f.sigCompanero=sigCompanero;
	while(datos[tam].nombre != ""){
		tam++;
	}
	datos[tam]=f;
}

//Funci�n para guardar los jugadores en el archivo
void Multilista::guardarJugadoresArchivo(string nombreArchivo){
 	ofstream archivo;
	string frase;
	char rpt;
	
	archivo.open(nombreArchivo.c_str(),ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	
	do{
		
		fflush(stdin);
		
        for(int i=0; i<tam; i++){
			stringstream fr;
            fr << datos[i].nombre << "-" << datos[i].pos << "-" << datos[i].edad << "-"<< datos[i].numCamiseta << "-" << datos[i].cantGoles << "-" << datos[i].sigCantGoles << "-" << datos[i].sigCompanero;
            frase = fr.str();
            archivo<<frase<<endl;           

        }
		
		
		cout<<"\nDesea agregar otra frase(S/N): ";
		cin>>rpt;
	}while((rpt == 'S') || (rpt == 's'));
	
	archivo.close(); //Cerramos el archivo

}

//Funcion para leer los jugadores del archivo y guardarlos en la multilista
void  Multilista::leerJugadoresArchivo(string nombreArchivo){ //Nombre o ubiacion del archivo o fichiero
    ifstream archivo;
	string texto, T;
	
	
	archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	tam=0;
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
        
        
        stringstream X(texto); // X is an object of stringstream that references the S string  
        int i=0;
        // use while loop to check the getline() function condition  
        while (getline(X, T, '-')) {  
            /* X represents to read the string from stringstream, T use for store the token string and, 
            '-' - represents to split the string where - is found. */  
            switch(i)
            {
                case 0: 
                    datos[tam].nombre = T;
                break;
                case 1: 
                    datos[tam].pos = T;
                break;
                case 2: 
                	sscanf(T.c_str(), "%d", &datos[tam].edad);                   
                break;
                case 3: 
                	sscanf(T.c_str(), "%d", &datos[tam].numCamiseta);
                break;
                case 4:
		            sscanf(T.c_str(), "%d", &datos[tam].cantGoles);
		        break;
		        case 5: 
		            sscanf(T.c_str(), "%d", &datos[tam].sigCantGoles);
		        break;
		        case 6: 
		            sscanf(T.c_str(), "%d", &datos[tam].sigCompanero);
		        break;
                
            }
            i++; 
        }  

        tam++;
	}
	
	archivo.close(); //Cerramos el archivo
}
#endif
