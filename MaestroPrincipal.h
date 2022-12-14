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
        string *posEquipos;
	public:
        //constructor
        MaestroPrincipal(){}
        
        //metodo para iniciar el programa
        void inicio();
        void menu();
        void verEquipos();
        void verJugadores();
        void verEstadios();
        void verCronograma();
        void ponerResultadoPartido();
        void modificarFecha(partido pM, Lista<partido> p);
        void modificarEquipo();
        void modificarJugador();
        void modificarJugadorPorFecha(int opcion);
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
        jugadores=mI.getJugadores();
        posEquipos = mI.getPosEquipos();
        cout<<"Se ha insertado desde cero"<<endl;
		MaestroGenerador mG;
		mG.generarCronograma(mI.getEstadios(),mI.getEquipos(),mI.getGrupoEquipos());
        cronograma = mG.getCronograma();

        //se guardan los archivos
        estadios.guardarEstadiosArchivo();
        equipos.guardarEquiposArchivo();
        jugadores.guardarJugadoresArchivo();
        cronograma.guardarPartidosArchivo();
        
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
            menu();
            break;
        case 2:
            verJugadores();
            menu();
            break;
        case 3:
            verEstadios();
            menu();
            break;
        case 4:
            verCronograma();
            menu();
            break;
        case 5:
            ponerResultadoPartido();
            //se guardan los archivos todo menos estadios
            menu();
            break;
        case 6:
            modificarEquipo();
            //se guardan los archivos todo menos estadios, cronograma
            menu();
            break;
        case 7:
            modificarJugador();
            //se guardan los archivos equipo
            menu();
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

void MaestroPrincipal::modificarJugador(){
    Lista<futbolista> jugadoresEquipo;
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
    }
    cout<<"Ingrese el numero del jugador que desea modificar: ";
    int num;
    cin>>num;
    futbolista jugador = jugadoresEquipo.ObtenerDatos(num);
    fflush(stdin);
    cout<<"Ingrese el nombre del jugador: ";
    getline(cin,jugador.nombre);
    cout<<"Ingrese la posicion del jugador: ";
    getline(cin,jugador.pos);
    cout<<"Ingrese el numero de camiseta del jugador: ";
    cin>>jugador.numCamiseta;
    cout<<"Ingrese la edad del jugador: ";
    cin>>jugador.edad;
    //para testeo
    //cout<<"Ingrese goles anotados: ";
    //cin>>jugador.cantGoles;

    jugadores.modificarFutbolista(jugador,opcion-1);
}


void MaestroPrincipal::modificarEquipo(){
    //system("cls");
    Equipo e;
    cout<<"\n\nEquipos participantes en el mundial\n\n";
    for(int i=0;i<32;i++){
        e = equipos.obtenerEquipo(i);
        cout<<i+1<<". Nombre del equipo: "<<e.nombre<<endl;
    }
    cout<<"Ingrese el numero del equipo que desea modificar: ";
    int num;
    cin>>num;
    e = equipos.obtenerEquipo(num-1);
    fflush(stdin);
    cout<<"Ingrese el nombre del equipo: ";
    getline(cin,e.nombre);
    cout<<"Ingrese la confederacion: ";
    getline(cin,e.confederacion);
    cout<<"Ingrese el nombre del entrenador: ";
    getline(cin,e.nombreEntrenador);
    cout<<"Ingrese el apellido del entrenador: ";
    getline(cin,e.apellidoEntrenador);
    cout<<"Ingrese la nacionalidad del entrenador: ";
    getline(cin,e.nacionalidadEntrenador);

    equipos.modificarEquipo(num-1,e);
}

void MaestroPrincipal::ponerResultadoPartido(){
    //system("cls");
    Lista<partido> p;
    string eD, sD;

    cout<<"\n\nCronograma del mundial\n\n";
    cout<<"1. Ver todos los partidos.\n";
    cout<<"2. Ver los partidos de un equipo.\n";
    cout<<"3. Ver los partidos de un estadio.\n";
    cout<<"4. Ver los partidos, por etapa y seccion.\n";
    cout<<"Seleccione la opcion que desea: ";
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            p = cronograma.obtenerPartidos();
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 2:
            cout<<"Ingrese el numero del equipo del cual desea ver los partidos: "<<endl;
            for(int i=0;i<32;i++){
                cout<<i+1<<". Nombre del equipo: "<<equipos.obtenerEquipo(i).nombre<<endl;
            }
            cout<<"Ingrese el numero del equipo del cual desea ver los partidos: "<<endl;
            int equipoD;
            cin>>equipoD;
            p = cronograma.obtenerPartidosPorEquipo(equipoD-1);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 3:
            cout<<"Ingrese el numero del estadio del cual desea ver los partidos: ";
            for(int i=0;i<estadios.getTam();i++){
                cout<<i+1<<". Nombre del estadio: "<<estadios.obtenerEstadio(i).nombre<<endl;
            }
            int estadioD;
            cin>>estadioD;
            p = cronograma.obtenerPartidosPorEstadio(estadioD-1);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 4:
            cout<<"Ingrese la etapa deseada: ";
            cout<<"\tEliminacion \tOctavos \tCuartos \tSemifinal \tFinal"<<endl;
            cin>>eD;
            cout<<"Ingrese la seccion deseada: ";
            cout<<"\tA \tB \tC \tD \tE \tF \tG \tH"<<endl;
            cin>>sD;
            p = cronograma.obtenerPartidosPorEtapaYSeccion(eD,sD);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            menu();
            break;
    }
    cout<<"Digite cual fecha desea modificar: ";
    int fecha;
    cin>>fecha;
    partido p3 = p.ObtenerDatos(fecha);
    if(p3.idEquipo1==-1 || p3.idEquipo2==-1){
        cout<<"No se puede modificar un partido que no tiene equipos"<<endl;
        menu();
    }else{
        modificarFecha(p3, p);
    }
    
    
}

void MaestroPrincipal::modificarFecha(partido pM, Lista<partido> p){
    Equipo equipo1, equipo2, equipo3, equipo4;
    partido np;
    if(pM.etapa == "Eliminacion"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            if(pM.golesEquipo1>pM.golesEquipo2){
                equipo1.puntos-=3;
                equipo1.partidosGanados--;
                equipo2.partidosPerdidos--;
                //se quitan los goles
            }else if(pM.golesEquipo1<pM.golesEquipo2){
                equipo2.puntos-=3;
                equipo2.partidosGanados--;
                equipo1.partidosPerdidos--;
            }else{
                equipo1.puntos--;
                equipo2.puntos--;
                equipo1.partidosEmpatados--;
                equipo2.partidosEmpatados--;
            }
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        if(pM.golesEquipo1>pM.golesEquipo2){
            equipo1.puntos+=3;
            equipo1.partidosGanados++;
            equipo2.partidosPerdidos++;
        }else if(pM.golesEquipo1<pM.golesEquipo2){
            equipo2.puntos+=3;
            equipo2.partidosGanados++;
            equipo1.partidosPerdidos++;
        }else{
            equipo1.puntos++;
            equipo2.puntos++;
            equipo1.partidosEmpatados++;
            equipo2.partidosEmpatados++;
        }
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista +1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        if(equipo1.partidosJugados==3){
            //en caso de que cada equipo complete los 3 partidos de la etapa se genera cronograma
            int posgrupo = equipo1.idEquipo/4;
            posgrupo = posgrupo*4;
            for(int i=posgrupo;i<posgrupo+4;i++){
                if(equipo1.idEquipo != i && equipo2.idEquipo != i){
                    equipo3 = equipos.obtenerEquipo(i);
                    break;
                }
            }
            for(int i=posgrupo;i<posgrupo+4;i++){
                if(equipo1.idEquipo != i && equipo2.idEquipo != i && equipo3.idEquipo != i){
                    equipo4 = equipos.obtenerEquipo(i);
                    break;
                }
            }
            if(equipo1.partidosJugados == 3 && equipo2.partidosJugados == 3 && equipo3.partidosJugados == 3 && equipo4.partidosJugados == 3){
                //se escoge los 2 mejores equipos de cada grupo
                int mayor=0,segundo=0, id, id2;
                if(equipo1.puntos>mayor){
                    mayor = equipo1.puntos;
                    id = equipo1.idEquipo;
                }
                if(equipo2.puntos>mayor){
                    mayor = equipo2.puntos;
                    id = equipo2.idEquipo;
                }
                if(equipo3.puntos>mayor){
                    mayor = equipo3.puntos;
                    id = equipo3.idEquipo;
                }
                if(equipo4.puntos>mayor){
                    mayor = equipo4.puntos;
                    id = equipo4.idEquipo;
                }
                //revisamos si hay un empate de puntos
                bool empate=false;
                if(equipo1.puntos==mayor && equipo1.idEquipo!=id){
                    empate = true;
                    id2 = equipo1.idEquipo;
                }
                if(equipo2.puntos==mayor && equipo2.idEquipo!=id){
                    empate = true;
                    id2 = equipo2.idEquipo;
                }
                if(equipo3.puntos==mayor && equipo3.idEquipo!=id){
                    empate = true;
                    id2 = equipo3.idEquipo;
                }
                if(equipo4.puntos==mayor && equipo4.idEquipo!=id){
                    empate = true;
                    id2 = equipo4.idEquipo;
                }
                if(!empate){
                    if(equipo1.puntos>segundo && equipo1.puntos<mayor){//como no hay empate se revisa el segundo
                        segundo = equipo1.puntos;
                        id2 = equipo1.idEquipo;
                    }
                    if(equipo2.puntos>segundo && equipo2.puntos<mayor){
                        segundo = equipo2.puntos;
                        id2 = equipo2.idEquipo;
                    }
                    if(equipo3.puntos>segundo && equipo3.puntos<mayor){
                        segundo = equipo3.puntos;
                        id2 = equipo3.idEquipo;
                    }
                    if(equipo4.puntos>segundo && equipo4.puntos<mayor){
                        segundo = equipo4.puntos;
                        id2 = equipo4.idEquipo;
                    }
                }
                //si hay empate se revisa quien tiene mas goles a favor
                equipo1 = equipos.obtenerEquipo(id);
                equipo2 = equipos.obtenerEquipo(id2);
                if(empate){
                    if(equipo1.golesFavor>equipo2.golesFavor){
                        id = equipo1.idEquipo;
                    }else if(equipo1.golesFavor<equipo2.golesFavor){
                        id = equipo2.idEquipo;
                    }else{
                        //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                        if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                            id = equipo1.idEquipo;
                        }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                            id = equipo2.idEquipo;
                        }else{
                            //si hay empate, se revisan tarjetas amaillas
                            if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                                id = equipo1.idEquipo;
                            }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                                id = equipo2.idEquipo;
                            }
                        }
                    }
                    if(id==id2){
                        equipo2 = equipo1;
                        equipo1 = equipos.obtenerEquipo(id2);
                    }
                }  
                cout<<"El equipo 1 es: "<<equipo1.nombre<<endl;
                cout<<"El equipo 2 es: "<<equipo2.nombre<<endl;
                //se genera cronograma de octavos de final
                if((equipo1.idEquipo /4)==0){
                    np = cronograma.obtenerPartidoPorPosEnLista(48);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(49);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==1){
                    np = cronograma.obtenerPartidoPorPosEnLista(48);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(49);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                } else if((equipo1.idEquipo /4)==2){
                    np = cronograma.obtenerPartidoPorPosEnLista(51);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(52);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==3){
                    np = cronograma.obtenerPartidoPorPosEnLista(51);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(52);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==4){
                    np = cronograma.obtenerPartidoPorPosEnLista(53);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(54);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==5){
                    np = cronograma.obtenerPartidoPorPosEnLista(53);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(54);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==6){
                    np = cronograma.obtenerPartidoPorPosEnLista(55);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(56);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }else if((equipo1.idEquipo /4)==7){
                    np = cronograma.obtenerPartidoPorPosEnLista(55);
                    np.idEquipo2 = equipo2.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                    np = cronograma.obtenerPartidoPorPosEnLista(56);
                    np.idEquipo1 = equipo1.idEquipo;
                    cronograma.modificarPartido(np.posEnLista+1,np);
                }
                
            }
        }
    }else if(pM.etapa == "Octavos"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista+1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        bool empate = false;
        int id = 0, id2 = 0;
        if(pM.golesEquipo1 == pM.golesEquipo2){
            id = pM.idEquipo1;
            id2 = pM.idEquipo2;
            empate = true;
        }
        if(empate){
            if(equipo1.golesFavor>equipo2.golesFavor){
                id = equipo1.idEquipo;
            }else if(equipo1.golesFavor<equipo2.golesFavor){
                id = equipo2.idEquipo;
            }else{
                //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                    id = equipo1.idEquipo;
                }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                    id = equipo2.idEquipo;
                }else{
                    //si hay empate, se revisan tarjetas amaillas
                    if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                        id = equipo1.idEquipo;
                    }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                        id = equipo2.idEquipo;
                    }
                }
            }
            if(id==id2){
                equipo2 = equipo1;
                equipo1 = equipos.obtenerEquipo(id2);
            }
        } 
        //se generan los partidos de cuartos
        //revisar si disminuyendo 1 se arregla el error
        cout<<"Estoy configurando la seccion: "<<pM.seccion<<endl;
        if(pM.seccion=="A"){
            np = cronograma.obtenerPartidoPorPosEnLista(57);
            cout<<"Estoy configurando la seccion: "<<np.seccion<<endl;
            np.idEquipo1 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="B"){
            np = cronograma.obtenerPartidoPorPosEnLista(58);
            cout<<"Estoy configurando la seccion: "<<np.seccion<<endl;
            np.idEquipo1 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="C"){
            np = cronograma.obtenerPartidoPorPosEnLista(57);
            np.idEquipo2 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="D"){
            np = cronograma.obtenerPartidoPorPosEnLista(58);
            np.idEquipo2 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="E"){
            np = cronograma.obtenerPartidoPorPosEnLista(59);
            np.idEquipo1 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="F"){
            np = cronograma.obtenerPartidoPorPosEnLista(60);
            np.idEquipo1 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="G"){
            np = cronograma.obtenerPartidoPorPosEnLista(59);
            np.idEquipo2 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="H"){
            np = cronograma.obtenerPartidoPorPosEnLista(60);
            np.idEquipo2 = equipo1.idEquipo;
            cronograma.modificarPartido(np.posEnLista,np);
        }
    }else if(pM.etapa == "Cuartos"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista+1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        bool empate = false;
        int id = 0, id2 = 0;
        if(pM.golesEquipo1 == pM.golesEquipo2){
            id = pM.idEquipo1;
            id2 = pM.idEquipo2;
            empate = true;
        }
        if(empate){
            if(equipo1.golesFavor>equipo2.golesFavor){
                id = equipo1.idEquipo;
            }else if(equipo1.golesFavor<equipo2.golesFavor){
                id = equipo2.idEquipo;
            }else{
                //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                    id = equipo1.idEquipo;
                }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                    id = equipo2.idEquipo;
                }else{
                    //si hay empate, se revisan tarjetas amaillas
                    if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                        id = equipo1.idEquipo;
                    }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                        id = equipo2.idEquipo;
                    }
                }
            }
            if(id==id2){
                equipo2 = equipo1;
                equipo1 = equipos.obtenerEquipo(id2);
            }
        }
        //se genera el partido de semifinal
        if(pM.seccion=="A"){
            np = cronograma.obtenerPartidoPorPosEnLista(61);
            np.idEquipo1 = id;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="B"){
            np = cronograma.obtenerPartidoPorPosEnLista(61);
            np.idEquipo2 = id2;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="C"){
            np = cronograma.obtenerPartidoPorPosEnLista(62);
            np.idEquipo1 = id;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="D"){
            np = cronograma.obtenerPartidoPorPosEnLista(62);
            np.idEquipo2 = id2;
            cronograma.modificarPartido(np.posEnLista,np);
        }
    }else if(pM.etapa == "Semifinales"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista+1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        bool empate = false;
        int id = 0, id2 = 0;
        if(pM.golesEquipo1 == pM.golesEquipo2){
            id = pM.idEquipo1;
            id2 = pM.idEquipo2;
            empate = true;
        }
        if(empate){
            if(equipo1.golesFavor>equipo2.golesFavor){
                id = equipo1.idEquipo;
            }else if(equipo1.golesFavor<equipo2.golesFavor){
                id = equipo2.idEquipo;
            }else{
                //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                    id = equipo1.idEquipo;
                }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                    id = equipo2.idEquipo;
                }else{
                    //si hay empate, se revisan tarjetas amaillas
                    if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                        id = equipo1.idEquipo;
                    }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                        id = equipo2.idEquipo;
                    }
                }
            }
            if(id==id2){
                equipo2 = equipo1;
                equipo1 = equipos.obtenerEquipo(id2);
            }
        }
        //se genera el partido de la final y tercer puesto
        if(pM.seccion=="A"){
            np = cronograma.obtenerPartidoPorPosEnLista(64);
            np.idEquipo1 = id;
            cronograma.modificarPartido(np.posEnLista,np);
            np = cronograma.obtenerPartidoPorPosEnLista(63);
            np.idEquipo1 = id2;
            cronograma.modificarPartido(np.posEnLista,np);
        }else if(pM.seccion=="B"){
            np = cronograma.obtenerPartidoPorPosEnLista(64);
            np.idEquipo2 = id;
            cronograma.modificarPartido(np.posEnLista,np);
            np = cronograma.obtenerPartidoPorPosEnLista(63);
            np.idEquipo2 = id2;
            cronograma.modificarPartido(np.posEnLista,np);
        }
    }else if(pM.etapa == "Tercer puesto"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista+1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        bool empate = false;
        int id = 0, id2 = 0;
        if(pM.golesEquipo1 == pM.golesEquipo2){
            id = pM.idEquipo1;
            id2 = pM.idEquipo2;
            empate = true;
        }
        if(empate){
            if(equipo1.golesFavor>equipo2.golesFavor){
                id = equipo1.idEquipo;
            }else if(equipo1.golesFavor<equipo2.golesFavor){
                id = equipo2.idEquipo;
            }else{
                //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                    id = equipo1.idEquipo;
                }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                    id = equipo2.idEquipo;
                }else{
                    //si hay empate, se revisan tarjetas amaillas
                    if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                        id = equipo1.idEquipo;
                    }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                        id = equipo2.idEquipo;
                    }
                }
            }
            if(id==id2){
                equipo2 = equipo1;
                equipo1 = equipos.obtenerEquipo(id2);
            }
        }
        //Se felicita al ganador del tercer lugar y se imprime premio
        system("cls");
        cout<<"\n\nFelicitaciones equipo "<<equipo1.nombre<<" por ganar el tercer puesto del mundial\n\n";
        cout<<"\n\n"<<endl;
        cout<<"\n\nFelicitaciones equipo "<<equipo2.nombre<<" por ganar el cuarto puesto del mundial\n\n";
        system("pause");
    } else if(pM.etapa == "Final"){
        if(pM.jugado){
            cout<<"\nEl partido ya fue jugado tenga esto en cuenta para editar.\n"<<endl;
            //se quitan los puntos de los equipos
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
            equipo1.partidosJugados--;
            equipo2.partidosJugados--;
            //se quitan los goles
            equipo1.golesFavor-=pM.golesEquipo1;
            equipo1.golesContra-=pM.golesEquipo2;
            equipo2.golesFavor-=pM.golesEquipo2;
            equipo2.golesContra-=pM.golesEquipo1;
        }
        cout<<"Ingrese el nuevo goles equipo 1: ";
        cin>>pM.golesEquipo1;
        cout<<"Ingrese el nuevo goles equipo 2: ";
        cin>>pM.golesEquipo2;
        cout<<"Ingrese el nuevo suplementario 1: ";
        cin>>pM.suplementario1;
        cout<<"Ingrese el nuevo suplementario 2: ";
        cin>>pM.suplementario2;
        cout<<"Ingrese el nuevo penales 1: ";
        cin>>pM.penales1;
        cout<<"Ingrese el nuevo penales 2: ";
        cin>>pM.penales2;
        if(!pM.jugado){
            equipo1 = equipos.obtenerEquipo(pM.idEquipo1);
            equipo2 = equipos.obtenerEquipo(pM.idEquipo2);
        }
        pM.jugado = true;
        equipo1.partidosJugados++;
        equipo2.partidosJugados++;
        //se suman los goles
        equipo1.golesFavor+=pM.golesEquipo1;
        equipo1.golesContra+=pM.golesEquipo2;
        equipo2.golesFavor+=pM.golesEquipo2;
        equipo2.golesContra+=pM.golesEquipo1;
        cronograma.modificarPartido(pM.posEnLista+1,pM);
        equipos.modificarEquipo(equipo1.idEquipo,equipo1);
        equipos.modificarEquipo(equipo2.idEquipo,equipo2);
        bool empate = false;
        int id = 0, id2 = 0;
        if(pM.golesEquipo1 == pM.golesEquipo2){
            id = pM.idEquipo1;
            id2 = pM.idEquipo2;
            empate = true;
        }
        if(empate){
            if(equipo1.golesFavor>equipo2.golesFavor){
                id = equipo1.idEquipo;
            }else if(equipo1.golesFavor<equipo2.golesFavor){
                id = equipo2.idEquipo;
            }else{
                //si hay empate en goles a favor se revisa quien tiene menos tarjetas rojas
                if(equipo1.tarjetasRojas<equipo2.tarjetasRojas){
                    id = equipo1.idEquipo;
                }else if(equipo1.tarjetasRojas>equipo2.tarjetasRojas){  
                    id = equipo2.idEquipo;
                }else{
                    //si hay empate, se revisan tarjetas amaillas
                    if(equipo1.tarjetasAmarillas<equipo2.tarjetasAmarillas){
                        id = equipo1.idEquipo;
                    }else if(equipo1.tarjetasAmarillas>equipo2.tarjetasAmarillas){
                        id = equipo2.idEquipo;
                    }
                }
            }
            if(id==id2){
                equipo2 = equipo1;
                equipo1 = equipos.obtenerEquipo(id2);
            }
        }
        //Se felicita al ganador del tercer lugar y se imprime premio
        system("cls");
        cout<<"\n\nFelicitaciones equipo "<<equipo1.nombre<<" por ganar el primer puesto del mundial\n\n";
        cout<<"\n\n"<<endl;
        cout<<"\n\nFelicitaciones equipo "<<equipo2.nombre<<" por ganar el segundo puesto del mundial\n\n";
        system("pause");
    }
}

void MaestroPrincipal::modificarJugadorPorFecha(int opcion){
    Lista<futbolista> jugadoresEquipo=jugadores.mostrarEquipo(opcion);
    //system("cls");
    for(int i=1;i<=jugadoresEquipo.TamLista();i++){
        futbolista jugador = jugadoresEquipo.ObtenerDatos(i);
        cout<<i<<". Nombre: "<<jugador.nombre<<endl;
    }
    cout<<"Ingrese el numero del jugador que anoto el gol: ";
    int num;
    cin>>num;
    futbolista jugador = jugadoresEquipo.ObtenerDatos(num);
    jugador.cantGoles++;
    jugadores.modificarFutbolista(jugador,opcion);
}

void MaestroPrincipal::verEquipos(){
    //system("cls");
    Equipo eM;
    cout<<"\n\nEquipos participantes en el mundial\n\n";
    for(int i=0;i<32;i++){
        eM = equipos.obtenerEquipo(i);
        cout<<i+1<<". Nombre del equipo: "<<eM.nombre<<endl;
        cout<<"   Confederacion: "<<eM.confederacion<<endl;
        cout<<"   Puntos: "<<eM.puntos<<endl;
        cout<<"   Partidos jugados: "<<eM.partidosJugados<<endl;
        cout<<"   Partidos ganados: "<<eM.partidosGanados<<endl;
        cout<<"   Partidos empatados: "<<eM.partidosEmpatados<<endl;
        cout<<"   Partidos perdidos: "<<eM.partidosPerdidos<<endl;
        cout<<"   Goles a favor: "<<eM.golesFavor<<endl;
        cout<<"   Goles en contra: "<<eM.golesContra<<endl;
        cout<<"   Tarjetas amarillas: "<<eM.tarjetasAmarillas<<endl;
        cout<<"   Tarjetas rojas: "<<eM.tarjetasRojas<<endl;
        cout<<"   Nombre del entrenador: "<<eM.nombreEntrenador<<endl;
        cout<<"   Apellido del entrenador: "<<eM.apellidoEntrenador<<endl;
        cout<<"   Nacionalidad del entrenador: "<<eM.nacionalidadEntrenador<<endl;
    }
}

void MaestroPrincipal::verJugadores(){
    Lista<futbolista> jugadoresEquipo;
    //system("cls");
    cout<<"\n\nJugadores participantes en el mundial\n\n";
    cout<<"1. Ver por goleadores.\n";
    cout<<"2. Ver por equipos.\n";
    cout<<"Escoja una opcion: ";
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            jugadoresEquipo=jugadores.mostrarGolesGlobal();
            for(int i=1;i<=jugadoresEquipo.TamLista();i++){
                futbolista jugador = jugadoresEquipo.ObtenerDatos(i);
                cout<<i<<". Nombre: "<<jugador.nombre<<endl;
                cout<<"   Posicion: "<<jugador.pos<<endl;
                cout<<"   Numero de camiseta: "<<jugador.numCamiseta<<endl;
                cout<<"   Goles: "<<jugador.cantGoles<<endl;
            }
            break;
        case 2:
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
            break;
    }
    system("pause");
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
}

void MaestroPrincipal::verCronograma(){
    //system("cls");
    Lista<partido> p;
    string eD, sD;

    cout<<"\n\nCronograma del mundial\n\n";
    cout<<"1. Ver todos los partidos.\n";
    cout<<"2. Ver los partidos de un equipo.\n";
    cout<<"3. Ver los partidos de un estadio.\n";
    cout<<"4. Ver los partidos, por etapa y seccion.\n";
    cout<<"Seleccione la opcion que desea: ";
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            p = cronograma.obtenerPartidos();
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 2:
            cout<<"Ingrese el numero del equipo del cual desea ver los partidos: ";
            for(int i=0;i<32;i++){
                cout<<i+1<<". Nombre del equipo: "<<equipos.obtenerEquipo(i).nombre<<endl;
            }
            int equipoD;
            cin>>equipoD;
            p = cronograma.obtenerPartidosPorEquipo(equipoD-1);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 3:
            cout<<"Ingrese el numero del estadio del cual desea ver los partidos: ";
            for(int i=0;i<estadios.getTam();i++){
                cout<<i+1<<". Nombre del estadio: "<<estadios.obtenerEstadio(i).nombre<<endl;
            }
            int estadioD;
            cin>>estadioD;
            p = cronograma.obtenerPartidosPorEstadio(estadioD-1);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        case 4:
            cout<<"Ingrese la etapa deseada: ";
            cout<<"\tEliminacion \tOctavos \tCuartos \tSemifinal \tFinal"<<endl;
            cin>>eD;
            cout<<"Ingrese la seccion deseada: ";
            cout<<"\tA \tB \tC \tD \tE \tF \tG \tH"<<endl;
            cin>>sD;
            p = cronograma.obtenerPartidosPorEtapaYSeccion(eD,sD);
            for(int i=1;i<=p.TamLista();i++){
                partido p2 = p.ObtenerDatos(i);
                if(p2.jugado){
                    cout<<i<<". Fecha: "<<p2.fecha<<"\t El partido ya fue jugado"<<endl;
                }else{
                    cout<<i<<". Fecha: "<<p2.fecha<<endl;
                }
                cout<<"   Hora: "<<p2.hora<<endl;
                cout<<"   Estadio: ";
                for(int i=0;i<estadios.getTam();i++){
                    Estadio estadio = estadios.obtenerEstadio(i);
                    if(p2.idEstadio==estadio.idEstadio){
                        cout<<estadio.nombre<<endl;
                        break;
                    }
                }
                cout<<"   Equipo 1: ";
                if(p2.idEquipo1!= -1){
                    cout<<posEquipos[p2.idEquipo1]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Equipo 2: ";
                if(p2.idEquipo2!= -1){
                    cout<<posEquipos[p2.idEquipo2]<<endl;
                }else{
                    cout<<"No hay equipo"<<endl;
                }
                cout<<"   Etapa: "<<p2.etapa<<endl;
                cout<<"   Seccion: "<<p2.seccion<<endl;
                cout<<"   Goles equipo 1: "<<p2.golesEquipo1<<endl;
                cout<<"   Goles equipo 2: "<<p2.golesEquipo2<<endl;
                cout<<"   Suplementario 1: "<<p2.suplementario1<<endl;
                cout<<"   Suplementario 2: "<<p2.suplementario2<<endl;
                cout<<"   Penales 1: "<<p2.penales1<<endl;
                cout<<"   Penales 2: "<<p2.penales2<<endl;
            }
            break;
        default:
            cout<<"Opcion no valida"<<endl;
            menu();
            break;
    }
    system("pause");
}
#endif
