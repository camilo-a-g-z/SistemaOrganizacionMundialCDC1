#include<iostream>
#include"multiLista.h"
#include"Lista.h"
#include"Equipos.h"
#include"Estadios.h"
#include "MaestroPrincipal.h"

using namespace std;

int main(){
	MaestroPrincipal mP;
	//mP.inicio();

	Estadios estadios;

	estadios.leerEstadiosArchivo("estadios.txt");

	cout<<estadios.obtenerEstadio(1).nombre<<endl;
	/*
	estadios.insertar("Estadio Monumental","Buenos Aires", 70000);
	estadios.insertar("Estadio Azteca","Mexico", 80000);
	estadios.insertar("Estadio Maracana","Rio de Janeiro", 90000);
	estadios.insertar("Estadio Nacional","Santiago", 100000);

	estadios.guardarEstadiosArchivo("estadios.txt");
	/*Multilista jugadores;
	Equipos equipos;


	equipos.insertar("Argentina","CONMEBOL","Simeone","Diego","Argentina");
	equipos.insertar("Brasil","CONMEBOL","Tite","Adenor","Brasil");
	equipos.insertar("Chile","CONMEBOL","Pizzi","Reinaldo","Chile");
	equipos.insertar("Colombia","CONMEBOL","Pekerman","Jose","Colombia");
	equipos.insertar("Ecuador","CONMEBOL","Ramirez","Ismael","Ecuador");

	equipos.guardarEquiposArchivo("equipos.txt");*/
	//jugadores.leerJugadoresArchivo("jugadores.txt");
	/*
	for(int i=0;i<20;i++){
		jugadores.insertar("pepe",17+i,i,25,"delantero",0);
	}

	
	jugadores.insertar("pepe1",17,1,0,"delantero",0);
	jugadores.insertar("pepe2",17,1,100,"delantero",0);

	
	
	jugadores.insertar("pepe3",17,1,0,"delantero",0);
	jugadores.insertar("pepe4",17,1,100,"delantero",0);

	Lista<futbolista> l2 = jugadores.mostrarEquipo(0);
	for(int i = 1; i<=l2.TamLista();i++){
		futbolista f = l2.ObtenerDatos(i);
		cout<<"cant goles: "<<f.cantGoles<<endl;
	}
	//cout<<l2.TamLista();
	
	jugadores.guardarJugadoresArchivo(l2, "jugadores.txt");*/

	//cout<<"Ahora le vamos a pedir que nos vuelva a mostrar: "<<endl;

	//for(int i = 1; i<=l.TamLista();i++){
	/*
		futbolista f = l.ObtenerDatos(i);
		cout<<"cant goles: "<<f.cantGoles<<endl;
	}*/
	return 0;
}
