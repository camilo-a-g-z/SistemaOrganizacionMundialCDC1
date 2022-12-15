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
        void guardarEquiposArchivo();
        Lista<Equipo> leerEquiposArchivo();
        Equipo obtenerEquipo(int id);
        Equipo obtenerEquipoPorPosicion(int pos);
        void modificarEquipo(int id, Equipo equipo);
        Lista<Equipo> obtenerEquiposPorPuntos();
        int insertar(Equipo e);
        
};
//metodo para devolver la lista de equipos en orden de puntos
Lista<Equipo> Equipos::obtenerEquiposPorPuntos(){
    int mayor = 0, pos=0;
    Lista<Equipo> listaOrdenada;
    Lista<Equipo> listaAuxiliar;
    //se hace copia para no alterar con cambios en la lista original
    for(int i=1; i<=equipos.TamLista(); i++){
        listaAuxiliar.Insertar(equipos.ObtenerDatos(i));
    }
    while(listaAuxiliar.TamLista()>0){
        mayor = 0;
        pos=0;
        for(int i=1; i<=listaAuxiliar.TamLista(); i++){
            if(listaAuxiliar.ObtenerDatos(i).puntos>mayor){
                mayor = listaAuxiliar.ObtenerDatos(i).puntos;
                pos=i;
            }
        }
        listaOrdenada.Insertar(listaAuxiliar.ObtenerDatos(pos));
        listaAuxiliar.Eliminar(pos);
    }
    return listaOrdenada;
}

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
    /*
    cout<<"nombre: "<<e.nombre<<endl;
    cout<<"confederacion: "<<e.confederacion<<endl;
    cout<<"nombreEntrenador: "<<e.nombreEntrenador<<endl;
    cout<<"apellidoEntrenador: "<<e.apellidoEntrenador<<endl;
    cout<<"nacionalidadEntrenador: "<<e.nacionalidadEntrenador<<endl;
    cout<<"idEquipo: "<<e.idEquipo<<endl;
    cout<<"numEnLista: "<<e.numEnLista<<endl;*/

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
    /*
    cout<<"nombre: "<<equipo.nombre<<endl;
    cout<<"confederacion: "<<equipo.confederacion<<endl;
    cout<<"nombreEntrenador: "<<equipo.nombreEntrenador<<endl;
    cout<<"apellidoEntrenador: "<<equipo.apellidoEntrenador<<endl;
    cout<<"nacionalidadEntrenador: "<<equipo.nacionalidadEntrenador<<endl;
    cout<<"idEquipo: "<<equipo.idEquipo<<endl;
    cout<<"numEnLista: "<<equipo.numEnLista<<endl;*/
    
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
            cout<<"modificando equipo: "<<equipos.ObtenerDatos(i).idEquipo<<" id:"<<id<<endl;
            equipos.modificar(i,equipo);
            cout<<"2modificando equipo: "<<equipos.ObtenerDatos(i).idEquipo<<" id:"<<id<<endl;
            break;
        }
    }
}
 
void Equipos::insertarEquipoArchivo(string nombre, string confederacion, string nombreEntrenador, string apellidoEntrenador, string nacionalidadEntrenador, int puntos, int partidosJugados, int partidosGanados, int partidosEmpatados, int partidosPerdidos, int golesFavor, int golesContra, int tarjetasAmarillas, int tarjetasRojas, int idEquipo, int numEnLista){
    
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
void Equipos::guardarEquiposArchivo(){
    string nombreArchivo="equipos.txt";
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
        //cout<<frase;
        if(i==tam){
            archivo<<frase;
        }else{
            archivo<<frase<<endl;  
        }           
    }
	Equipos();
	

	
	archivo.close(); //Cerramos el archivo

}


//Funcion para leer los equipos del archivo y guardarlos en equipos
Lista<Equipo> Equipos::leerEquiposArchivo(){ //Nombre o ubiacion del archivo o fichiero
    string nombreArchivo="equipos.txt";
    ifstream archivo;
    string texto, T;
    
    
    archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){ //mientras no sea final del archivo
        getline(archivo,texto);
        string nombre, confederacion, nombreEntrenador, apellidoEntrenador, nacionalidadEntrenador;
    	int puntos, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, golesFavor, golesContra, tarjetasAmarillas, tarjetasRojas, idEquipo, numEnLista;
        
        stringstream X(texto); // X is an object of stringstream that references the S string  
        int i=0;
        Equipos();
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
                case 2: //confederacion
                    confederacion = T;
                    
                break;
                case 3: //nombre entrenador
                	nombreEntrenador = T;  
                                  
                break;
                case 4: //apellido entrenador
                	apellidoEntrenador = T;
                   
                break;
                case 5: //nacionalidad entrenador
                    nacionalidadEntrenador = T;
                    
                break;
                case 6: //puntos
                    sscanf(T.c_str(), "%d", &puntos);
                     
                break;
                case 7: //partidos jugados
                    sscanf(T.c_str(), "%d", &partidosJugados);
                break;
                case 8: //partidos ganados
                    sscanf(T.c_str(), "%d", &partidosGanados);
                break;
                case 9: //partidos empatados
                    sscanf(T.c_str(), "%d", &partidosEmpatados);
                break;
                case 10: //partidos perdidos
                    sscanf(T.c_str(), "%d", &partidosPerdidos);
                break;
                case 11: //goles a favor
                    sscanf(T.c_str(), "%d", &golesFavor);
                break;
                case 12: //goles en contra
                    sscanf(T.c_str(), "%d", &golesContra);
                break;
                case 13: //tarjetas amarillas
                    sscanf(T.c_str(), "%d", &tarjetasAmarillas);
                break;
                case 14: //tarjetas rojas
                    sscanf(T.c_str(), "%d", &tarjetasRojas);
                break;
                case 15: //id equipo
                    sscanf(T.c_str(), "%d", &idEquipo);
                break;
            }
             i++; 
        }  
            insertarEquipoArchivo(nombre, confederacion, nombreEntrenador, apellidoEntrenador, nacionalidadEntrenador, puntos, partidosJugados, partidosGanados, partidosEmpatados, partidosPerdidos, golesFavor, golesContra, tarjetasAmarillas, tarjetasRojas, idEquipo, numEnLista);
	}	
	archivo.close(); //Cerramos el archivo
    return equipos;
}
#endif
