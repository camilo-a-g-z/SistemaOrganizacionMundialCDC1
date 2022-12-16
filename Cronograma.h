#ifndef CRONOGRAMA_H
#define CRONOGRAMA_H
#include <iostream>
#include "Lista.h"
using namespace std;

struct partido{
    int idEstadio;
    int idEquipo1;
    int idEquipo2;
    string fecha;
    string hora;
    string etapa;//eliminacion, cuartos....final
    string seccion;//Grupo A,Grupo B ....
    int golesEquipo1;
    int golesEquipo2;
    int suplementario1;
    int suplementario2;
    int penales1;
    int penales2;
    int posEnLista;
    bool jugado;
};

class Cronograma
{
	private:
        Lista<partido> partidos;
        int tam;
	public:
        //constructor
        Cronograma(){
            tam=0;
        }
        void insertar(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string hora, string etapa, string seccion);

        void guardarPartidosArchivo();
        void insertarPartidoArchivo(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string hora, string etapa, string seccion, int golesEquipo1, int golesEquipo2, int suplementario1, int suplementario2, int penales1, int penales2, int posEnLista);
        Lista<partido> leerPartidosArchivo();
		Lista<partido> obtenerPartidosPorEtapa(string etapa);
        Lista<partido> obtenerPartidos(){return partidos;}
        Lista<partido> obtenerPartidosPorEquipo(int idEquipo);
        Lista<partido> obtenerPartidosPorEstadio(int idEstadio);
        Lista<partido> obtenerPartidosPorEtapaYSeccion(string etapa, string seccion);
        Lista<partido> obtenerPartidosPorSeccion(string seccion);
        Lista<partido> obtenerPartidosPorFecha(string fecha);
        partido obtenerPartidoPorPosEnLista(int posEnLista);
        int getTam(){return tam;}
        void modificarPartido(int posEnLista, partido partido);
        
        
};
partido Cronograma::obtenerPartidoPorPosEnLista(int posEnLista){
    for(int i = 1; i<=tam; i++){
        if(partidos.ObtenerDatos(i).posEnLista == posEnLista){
            return partidos.ObtenerDatos(i);
        }
    }
}

Lista<partido> Cronograma::obtenerPartidosPorSeccion(string seccion){
    Lista<partido> partidosSeccion;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.seccion==seccion){
            partidosSeccion.Insertar(partido);
        }
    }
    return partidosSeccion;
}

void Cronograma::insertar(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string hora, string etapa, string seccion){
    partido partido;
    partido.idEstadio=idEstadio;
    partido.idEquipo1=idEquipo1;
    partido.idEquipo2=idEquipo2;
    partido.fecha=fecha;
    partido.hora=hora;
    partido.etapa=etapa;
    partido.seccion=seccion;
    partido.golesEquipo1=0;
    partido.golesEquipo2=0;
    partido.suplementario1=0;
    partido.suplementario2=0;
    partido.penales1=0;
    partido.penales2=0;
    partido.posEnLista=tam;
    partido.jugado=false;
    partidos.Insertar(partido);
    tam++;
    //impresion de toda la estructura para testeo
    /*
    cout<<"idEstadio: "<<partido.idEstadio<<endl;
    cout<<"idEquipo1: "<<partido.idEquipo1<<endl;
    cout<<"idEquipo2: "<<partido.idEquipo2<<endl;
    cout<<"fecha: "<<partido.fecha<<endl;
    cout<<"etapa: "<<partido.etapa<<endl;
    cout<<"seccion: "<<partido.seccion<<endl;
    cout<<"posEnLista: "<<partido.posEnLista<<endl;*/

}

Lista<partido> Cronograma::obtenerPartidosPorEtapa(string etapa){
    Lista<partido> partidosEtapa;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.etapa==etapa){
            partidosEtapa.Insertar(partido);
        }
    }
    return partidosEtapa;
}
//metodo para obtener una lista de los partidos de un equipo
Lista<partido> Cronograma::obtenerPartidosPorEquipo(int idEquipo){
    Lista<partido> partidosEquipo;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.idEquipo1==idEquipo || partido.idEquipo2==idEquipo){
            partidosEquipo.Insertar(partido);
        }
    }
    return partidosEquipo;
}
//metodo para obtener una lista de los partidos de un estadio
Lista<partido> Cronograma::obtenerPartidosPorEstadio(int idEstadio){
    Lista<partido> partidosEstadio;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.idEstadio==idEstadio){
            partidosEstadio.Insertar(partido);
        }
    }
    return partidosEstadio;
}
//metodo para obtener una lista de partidos de una etapa y seccion
Lista<partido> Cronograma::obtenerPartidosPorEtapaYSeccion(string etapa, string seccion){
    Lista<partido> partidosEtapaSeccion;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.etapa==etapa && partido.seccion==seccion){
            partidosEtapaSeccion.Insertar(partido);
        }
    }
    return partidosEtapaSeccion;
}
//metodo para obtener una lista de partidos de una fecha
Lista<partido> Cronograma::obtenerPartidosPorFecha(string fecha){
    Lista<partido> partidosFecha;
    partido partido;
    for(int i=1;i<=tam;i++){
        partido=partidos.ObtenerDatos(i);
        if(partido.fecha==fecha){
            partidosFecha.Insertar(partido);
        }
    }
    return partidosFecha;
}
//metodo para modificar un partido
void Cronograma::modificarPartido(int posEnLista, partido partido){
    partidos.modificar(posEnLista,partido);
}


void Cronograma::insertarPartidoArchivo(int idEstadio, int idEquipo1, int idEquipo2, string fecha, string hora, string etapa, string seccion, int golesEquipo1, int golesEquipo2, int suplementario1, int suplementario2, int penales1, int penales2, int posEnLista){
    partido partido;
    partido.idEstadio=idEstadio;
    partido.idEquipo1=idEquipo1;
    partido.idEquipo2=idEquipo2;
    partido.fecha=fecha;
    partido.hora=hora;
    partido.etapa=etapa;
    partido.seccion=seccion;
    partido.golesEquipo1=golesEquipo1;
    partido.golesEquipo2=golesEquipo2;
    partido.suplementario1=suplementario1;
    partido.suplementario2=suplementario2;
    partido.penales1=penales1;
    partido.penales2=penales2;
    partido.posEnLista=posEnLista;
    partidos.Insertar(partido);
    tam++;
}

//Funcion para guardar los partidos en el archivo
void Cronograma::guardarPartidosArchivo(){
    string nombreArchivo="partidos.txt";
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
        partido p = partidos.ObtenerDatos(i);
        
        fr << i-1 <<"*" << p.idEstadio << "*" << p.idEquipo1 << "*" << p.idEquipo2 << "*" << p.fecha << "*"<<p.hora<<"*" << p.etapa << "*" << p.seccion << "*" << p.golesEquipo1 << "*" << p.golesEquipo2 << "*" << p.suplementario1 << "*" << p.suplementario2 << "*" << p.penales1 << "*" << p.penales2 << "*" << p.posEnLista;
        frase = fr.str();
        //cout<<frase;
        if(i==tam){
            archivo<<frase;
        }else{
            archivo<<frase<<endl;  
        }           
    }
    Cronograma();
    
    archivo.close(); //Cerramos el archivo

}

//Funcion para leer los partidos del archivo y guardarlos en equipos
Lista<partido> Cronograma::leerPartidosArchivo(){ //Nombre o ubiacion del archivo o fichiero
    string nombreArchivo="Cronograma.txt";
    ifstream archivo;
    string texto, T;
    
    
    archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura
    
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }
    while(!archivo.eof()){ //mientras no sea final del archivo
        getline(archivo,texto);
        string fecha, hora, etapa, seccion;
    	int idEstadio, idEquipo1, idEquipo2, golesEquipo1, golesEquipo2, suplementario1, suplementario2, penales1, penales2, posEnLista;
        
        stringstream X(texto); // X is an object of stringstream that references the S string  
        int i=0;
        Cronograma();
        // use while loop to check the getline() function condition  
        while (getline(X, T, '*')) {  
            /* X represents to read the string from stringstream, T use for store the token string and, 
            '-' - represents to split the string where - is found. */  
            
            switch(i)
            {
                case 0: //posicion en la multilista
                    sscanf(T.c_str(), "%d", &posEnLista); 
                    
                case 1:  //id estadio
                    sscanf(T.c_str(), "%d", &idEstadio);
                   
                break;
                case 2: //id equipo 1
                    sscanf(T.c_str(), "%d", &idEquipo1);
                    
                break;
                case 3: //id equipo 2
                	sscanf(T.c_str(), "%d", &idEquipo2);  
                                  
                break;
                case 4: //fecha
                	fecha = T;
                   
                break;
                case 5: //hora
                    hora = T;
                    
                break;
                case 6: //etapa
                    etapa = T;
                     
                break;
                case 7: //seccion
                    seccion = T;
                break;
                case 8: //goles equipo 1
                    sscanf(T.c_str(), "%d", &golesEquipo1);
                break;
                case 9: //goles equipo 2
                    sscanf(T.c_str(), "%d", &golesEquipo2);
                break;
                case 10: //suplementario equipo 1
                    sscanf(T.c_str(), "%d", &suplementario1);
                break;
                case 11: //suplementario equipo 2
                    sscanf(T.c_str(), "%d", &suplementario2);
                break;
                case 12: //penales equipo 1
                    sscanf(T.c_str(), "%d", &penales1);
                break;
                case 13: //penales equipo 2
                    sscanf(T.c_str(), "%d", &penales2);
                break;
            }
                i++;
        }
        insertarPartidoArchivo(idEstadio, idEquipo1, idEquipo2, fecha, hora, etapa, seccion, golesEquipo1, golesEquipo2, suplementario1, suplementario2, penales1, penales2, posEnLista);
    }
    archivo.close(); //Cerramos el archivo

    return partidos;
}


#endif
