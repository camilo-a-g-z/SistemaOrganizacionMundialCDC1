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
    int sigCampoLibre;
};

//Creaci?n de la clase Multilista
class Multilista{
	private:
		//Atributos de la Multilista 
		int *cabeceras;
		futbolista *datos;
		int tam;
		int sigPosLibre;
	public:
		//Metodo Constructor (inicializacion de los atributos de la Multilista)
		Multilista(){
			sigPosLibre = 0;
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
			for(int i=0; i<834; i++){
                datos[i].nombre="";
                datos[i].edad=0;
                datos[i].numCamiseta=0;
                datos[i].cantGoles=0;
                datos[i].pos="";
                datos[i].sigCantGoles=-1;
                datos[i].sigCompanero=-1;
                datos[i].sigCampoLibre=i+1;
            }
            datos[834].nombre="";
            datos[834].edad=0;
            datos[834].numCamiseta=0;
            datos[834].cantGoles=0;
            datos[834].pos="";
            datos[834].sigCantGoles=-1;
            datos[834].sigCompanero=-1;
            datos[834].sigCampoLibre=-1;
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
		void guardarJugadoresArchivo(Lista<futbolista> jugadores, string nombreArchivo);
		void leerJugadoresArchivo(string nombreArchivo);
		Lista<futbolista> mostrarEquipo(int equipo);
		Lista<futbolista> mostrarGolesPorEquipo(int equipo);
		Lista<futbolista> mostrarGolesGlobal();
		Lista<futbolista> sacarEquipo(int equipo);
		futbolista getFutbolista(int pos);
		void insertarDatosArchivo(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int sigCantGoles, int sigCompanero, int sigCampoLibre, int posMulti);
};

//metodo para devolver todos los futbolistas de un equipo y eliminarlos de la multilista
Lista<futbolista> Multilista :: sacarEquipo(int equipo){
	Lista<futbolista> lista;
	int pos=cabeceras[equipo];
	int aux;
	while(pos!=-1){
		lista.Insertar(datos[pos]);
		aux=pos;
		pos=datos[pos].sigCompanero;
		datos[aux].nombre="";
		datos[aux].edad=0;
		datos[aux].numCamiseta=0;
		datos[aux].cantGoles=0;
		datos[aux].pos="";
		datos[aux].sigCantGoles=-1;
		datos[aux].sigCompanero=-1;
		datos[aux].sigCampoLibre=sigPosLibre;
		sigPosLibre=aux;
		tam --;
	}
	if(tam==0){
		cabeceras[32] =-1;
	}
	cabeceras[equipo]=-1;
	return lista;
}


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
    f.sigCompanero =-1;
    f.sigCantGoles =-1;

	int k;
	int i=sigPosLibre;
	sigPosLibre = datos[i].sigCampoLibre;
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
		cantGoles=datos[i].cantGoles;
		int anterior=k;
		while(datos[k].sigCantGoles != -1 && datos[k].cantGoles > cantGoles){
			anterior=k;
			k=datos[k].sigCantGoles;
		}
		if(anterior==k && datos[k].cantGoles <= cantGoles){
			datos[i].sigCantGoles=k;
			cabeceras[32]=i;
		}else if(datos[k].sigCantGoles == -1 && datos[k].cantGoles > cantGoles){
			datos[k].sigCantGoles = i;
		}else{
			datos[i].sigCantGoles=k;
			datos[anterior].sigCantGoles=i;
		}
		 
		
	}
	tam++;
	return true;
}

Lista<futbolista> Multilista::mostrarEquipo(int equipo){
	Lista<futbolista> l;
	int k=cabeceras[equipo];
	while(k!=-1){
		l.Insertar(datos[k]);
		k=datos[k].sigCompanero;
	}
	return l;
}

//crear un metodo que muestre los jugadores de un equipo en orden ascendente de goles
Lista<futbolista> Multilista::mostrarGolesPorEquipo(int equipo){
	Lista<futbolista> l;
	int k=cabeceras[equipo];
	while(k!=-1){
		l.Insertar(datos[k]);
		k=datos[k].sigCantGoles;
	}
	return l;
}
//crear un metodo que muestre todos los jugadores en orden ascendente de goles
Lista<futbolista> Multilista::mostrarGolesGlobal(){
	Lista<futbolista> l;
	int k=cabeceras[32];
	while(k!=-1){
		l.Insertar(datos[k]);
		k=datos[k].sigCantGoles;
	}
	return l;
}
//se crea un metodo que retorne la estructura futbolista acorde a la posicion que se le pase
futbolista Multilista::getFutbolista(int pos){
	return datos[pos];
}
//funcion para insertar en la lista de datos de la multilista
void Multilista::insertarDatosArchivo(string nombre, int edad, int numCamiseta, int cantGoles, string pos, int sigCantGoles, int sigCompanero, int sigCampoLibre, int posMulti){
	futbolista f;
	f.nombre=nombre;
	f.edad=edad;
	f.numCamiseta=numCamiseta;
	f.cantGoles=cantGoles;
	f.pos=pos;
	f.sigCantGoles=sigCantGoles;
	f.sigCompanero=sigCompanero;
	f.sigCampoLibre= sigCampoLibre;
	int i=sigPosLibre;
	sigPosLibre = datos[i].sigCampoLibre;
	datos[posMulti]=f;
	tam++;
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
	while(!archivo.eof()){ //mientras no sea final del archivo
		getline(archivo,texto);
        string nombre, pos;
    	int edad, numCamiseta, cantGoles, equipo, sigCantGoles, sigCompanero, sigCampoLibre, posMulti;
        
        stringstream X(texto); // X is an object of stringstream that references the S string  
        int i=0;
        // use while loop to check the getline() function condition  
        while (getline(X, T, '*')) {  
            /* X represents to read the string from stringstream, T use for store the token string and, 
            '-' - represents to split the string where - is found. */  
            
            switch(i)
            {
				case 0: //posicion en la multilista
					sscanf(T.c_str(), "%d", &posMulti); 
					
                case 1:  //nombre
                    nombre = T;
                   
                break;
                case 2: //posicion
                    pos = T;
                    
                break;
                case 3: //edad
                	sscanf(T.c_str(), "%d", &edad);  
					              
                break;
                case 4: //numero de camiseta
                	sscanf(T.c_str(), "%d", &numCamiseta);
                   
                break;
                case 5: //Cantidad de goles
		            sscanf(T.c_str(), "%d", &cantGoles);
		            
		        break;
		        case 6: //siguiente cantidad de goles
		            sscanf(T.c_str(), "%d", &sigCantGoles);
		             
		        break;
		        case 7: //siguiente companero
		            sscanf(T.c_str(), "%d", &sigCompanero);
		        break;
				case 8: //siguiente campo libre
		            sscanf(T.c_str(), "%d", &sigCampoLibre); 
				break;     
            }
            
            i++; 
        }  
        //cout<<nombre<<endl;
            cout<<"linea: "<< nombre<<pos<< edad<< numCamiseta<<cantGoles<<sigCantGoles<<sigCompanero<<sigCampoLibre<<posMulti<<endl;
            
            insertarDatosArchivo(nombre, edad, numCamiseta, cantGoles, pos, sigCantGoles, sigCompanero, sigCampoLibre, posMulti);
	}	
	archivo.close(); //Cerramos el archivo
}

//Funcion para guardar los jugadores en el archivo
void Multilista::guardarJugadoresArchivo(Lista<futbolista> jugadores, string nombreArchivo){
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
		futbolista f = jugadores.ObtenerDatos(i);
        fr << i-1 <<"*" << f.nombre << "*" << f.pos << "*" <<f.edad << "*"<< f.numCamiseta << "*" << f.cantGoles << "*" << f.sigCantGoles << "*" << f.sigCompanero << "*" << f.sigCampoLibre;
        frase = fr.str();
        cout<<frase;
        archivo<<frase<<endl;           
    }
	Multilista();
		
	
	archivo.close(); //Cerramos el archivo

}
#endif
