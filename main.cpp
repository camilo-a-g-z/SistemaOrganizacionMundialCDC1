#include<iostream>
#include"multiLista.h"
#include"Lista.h"

using namespace std;

int main(){
	Multilista jugadores;
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
	cout<<l2.TamLista();
	jugadores.guardarJugadoresArchivo(l2, "jugadores.txt");

	/*
	cout<<"Ahora le vamos a pedir que nos vuelva a mostrar: "<<endl;
	Lista<futbolista> l = jugadores.mostrarGolesGlobal();
	for(int i = 1; i<=l.TamLista();i++){
		futbolista f = l.ObtenerDatos(i);
		cout<<"cant goles: "<<f.cantGoles<<endl;
	}*/
	return 0;
}
