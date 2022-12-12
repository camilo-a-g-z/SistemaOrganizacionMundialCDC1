#ifndef ESTADIOS_H
#define ESTADIOS_H
#include <iostream>
#include "Lista.h"

using namespace std;

struct Estadio{
    string nombre;
    string ciudad;
    int capacidad;
    int idEstadio;
    int numEnLista;
};

class Estadios
{
	private:
        Lista<Estadio> estadios;
        int tam;
        int idEstadioActual;
	public:
        //constructor
        Estadios(){
            tam=0;
            idEstadioActual=0;
        }
        int insertar(string nombre, string ciudad, int capacidad);
        void insertarEstadioArchivo(string nombre, string ciudad, int capacidad, int idEstadio, int numEnLista);
        Estadio obtenerEstadio(int id);
        Estadio obtenerEstadioPorPosicion(int pos);
        void guardarEstadiosArchivo(string nombreArchivo);
        void leerEstadiosArchivo(string nombreArchivo);
        void modificarEstadio(int id, Estadio estadio);
        int getTam(){return tam;}
        
        
};

int Estadios::insertar(string nombre, string ciudad, int capacidad){
    Estadio estadio;
    estadio.nombre=nombre;
    estadio.ciudad=ciudad;
    estadio.capacidad=capacidad;
    estadio.idEstadio=idEstadioActual;
    estadio.numEnLista=tam;
    estadios.Insertar(estadio);
    idEstadioActual++;
    tam++;
    //impresion de toda la estructura para testeo
    cout<<"nombre de Estadio: "<<estadio.nombre<<endl;
    cout<<"ciudad de Estadio: "<<estadio.ciudad<<endl;
    cout<<"capacidad de Estadio: "<<estadio.capacidad<<endl;
    cout<<"id de Estadio: "<<estadio.idEstadio<<endl;
    cout<<"numero en lista de Estadio: "<<estadio.numEnLista<<endl;
    return estadio.numEnLista;
}
//metodo para obtener un estadio por su id
Estadio Estadios::obtenerEstadio(int id){
    Estadio estadio;
    for(int i=1;i<=tam;i++){
        estadio=estadios.ObtenerDatos(i);
        if(estadio.idEstadio==id){
            return estadio;
        }
    }
    return estadio;
}
//metodo para obtener un estadio por su posicion en la lista
Estadio Estadios::obtenerEstadioPorPosicion(int pos){
    Estadio estadio;
    for(int i=1;i<=tam;i++){
        estadio=estadios.ObtenerDatos(i);
        if(estadio.numEnLista==pos){
            return estadio;
        }
    }
    return estadio;
}
//metodo para modificar un estadio
void Estadios::modificarEstadio(int id, Estadio estadio){
    estadios.modificar(id, estadio);
}


void Estadios::insertarEstadioArchivo(string nombre, string ciudad, int capacidad, int idEstadio, int numEnLista){
    Estadio estadio;
    estadio.nombre=nombre;
    estadio.ciudad=ciudad;
    estadio.capacidad=capacidad;
    estadio.idEstadio=idEstadio;
    estadio.numEnLista=tam+1;
    estadios.Insertar(estadio);
    idEstadioActual++;
    tam++;
}

//Funcion para guardar los estadios en el archivo
void Estadios::guardarEstadiosArchivo(string nombreArchivo){
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
        Estadio e = estadios.ObtenerDatos(i);
        fr << i-1 <<"*" << e.nombre << "*" << e.ciudad << "*" <<e.capacidad << "*"<< e.idEstadio << "*" << e.numEnLista;
        frase = fr.str();
        cout<<frase;
        if(i==tam){
        	archivo<<frase;
		}else{
			archivo<<frase<<endl;  
		}
                 
    }
    Estadios();
        
    
    archivo.close(); //Cerramos el archivo

}

//Funcion para leer los estadios del archivo y guardarlos en estadios
void Estadios::leerEstadiosArchivo(string nombreArchivo){ //Nombre o ubiacion del archivo o fichiero
    ifstream archivo;
    string texto, T;
    
    
    archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){ //mientras no sea final del archivo
        getline(archivo,texto);
        string nombre, ciudad;
    	int capacidad, idEstadio, numEnLista;
        
        stringstream X(texto); // X is an object of stringstream that references the S string  
        int i=0;
        // use while loop to check the getline() function condition  
        while (getline(X, T, '*')) {  
            /* X represents to read the string from stringstream, T use for store the token string and, 
            '-' - represents to split the string where - is found. */  
            
            switch(i)
            {
                case 0: //posicion en la multilista
                    sscanf(T.c_str(), "%d", &numEnLista); 
                    
                case 1:  //nombre
                    nombre = T;
                   
                break;
                case 2: //ciudad
                    ciudad = T;
                    
                break;
                case 3: //capacidad
                	sscanf(T.c_str(), "%d", &capacidad);  
                                  
                break;
                case 4: //idEstadio
                	sscanf(T.c_str(), "%d", &idEstadio);
                   
                break;
            }
            
            i++; 
        }  
        //cout<<nombre<<endl;
            cout<<"linea: "<< nombre<<ciudad<< capacidad<< idEstadio<<numEnLista<<endl;
            
            insertarEstadioArchivo(nombre, ciudad, capacidad, idEstadio, numEnLista);
    }	
    archivo.close(); //Cerramos el archivo
}
#endif
