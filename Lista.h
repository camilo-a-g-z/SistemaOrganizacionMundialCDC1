#include <iostream>
#ifndef LISTA_H
#define LISTA_H
using namespace std;
//TAREA :
//Lista ordenada, imprimirla, eliminar elementos y volver a imprimir en MAIN
template < class T >  
//Estructura a emplear para lista
struct Nodo
{
	T info;
	Nodo<T> *sig;
};
//Template de tipo dato a usar
template < class T >  
class Lista
{
	private:
		Nodo<T> *cab;
		Nodo<T> *cent;
		int tam;
	public:
		Lista()
		{
			cab = new Nodo<T>; 
			tam = 0; 
			cent = new Nodo<T>;
			cab->sig = cent; 
			cent->sig = NULL;	
		};
		//~Lista<T>();
		bool ListaVacia();
		int TamLista();
		bool Insertar(T dato, int pos);
		bool Insertar(T dato);
		bool InsertarFinal(T dato);
		T Eliminar(int pos);
		T ObtenerDatos(int pos);
		void mostrar();
		void modificar(int pos, T dato);
};

template < class T >  
bool Lista<T>::ListaVacia(){return (tam == 0);}

template < class T >  
int Lista<T>::TamLista(){return tam;}

template < class T >  
T Lista<T>::ObtenerDatos(int pos){
	Nodo<T> *aux;
	aux = cab->sig;
	for(int i = 1; i < pos; i++){aux = aux->sig;}
	return aux->info;
}

template < class T >  
T Lista<T>::Eliminar(int pos){
	//en el caso de que estemos pidiendo un lugar que no se puede
	T d;
	if(pos > (tam + 1)){return d;}
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	aux = cab;
	for(int i = 0; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	n_n->info = aux2->info;
	aux->sig = aux2->sig;
	delete aux2;
	tam --;
	return n_n->info;
}

template < class T >  
void Lista<T>::mostrar(){
	Nodo<T> *aux;
	aux = cab->sig;
	while(aux->sig != NULL) 
	{
		cout<<aux->info<<" | ";
		aux = aux->sig;
	}
	cout<<endl;
}

template < class T >  
bool Lista<T>::Insertar(T dato, int pos){
	//en el caso de que estemos pidiendo un lugar que no se puede
	if(pos > tam + 1){return false;}
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	
	n_n->info = dato;
	aux = cab;
	
	for(int i = 0; i < pos-1; i++){aux = aux->sig;}
	aux2 = aux->sig;
	n_n->sig = aux2;
	aux->sig = n_n;
	
	tam++;
	return true;
}

template < class T > 
bool Lista<T>::Insertar(T dato){//insertar al final de la lista
	//se crea nuevo nodo y variables auxiliares necesarias
	Nodo<T> *n_n = new Nodo<T>;
	Nodo<T> *aux, *aux2;
	
	n_n->info = dato;
	aux = cab;
	
	for(int i = 0; i < tam; i++){aux = aux->sig;}
	aux2 = aux->sig;
	n_n->sig = aux2;
	aux->sig = n_n;
	
	tam++;
	return true;
}

//metodo para modificar recibiendo un dato y una posicion
template < class T >
void Lista<T>::modificar(int pos, T dato){
	Nodo<T> *aux;
	aux = cab->sig;
	for(int i = 1; i < pos; i++){aux = aux->sig;}
	aux->info = dato;
}

#endif
