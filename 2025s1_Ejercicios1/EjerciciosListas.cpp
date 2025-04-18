#include "EjerciciosListas.h"



void agregarPrincipio(NodoLista* &lista, int dato) {

	NodoLista* nodo = new NodoLista;
	nodo->dato = dato;
	nodo->sig = lista;
	lista = nodo;
}

int largoLista(NodoLista* &lista) {
	int largo = 0;
	NodoLista* temp = lista;
	while (temp) {
		largo++;
		temp = temp->sig;
	}
	return largo;
	delete[] temp;
}

NodoLista* invertirParcial(NodoLista* l) 
{
	// Caso base: Lista nula o de 1 item
	if (!l || !l->sig) return nullptr;
	NodoLista* listaInvertida = nullptr;
	
	while (l->sig) {
		agregarPrincipio(listaInvertida, l->dato);
		l = l->sig;
	}
		return listaInvertida;
		delete[] listaInvertida;
	}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	
//RECURSIVO: 
	static int count = 0;
	static int countDelta = 0;
	// Count verigica la cantidad de veces que volvio de recursion, ayudandonos a eliminar el correcto.
	// CountDelta lleva la cuenta de cuantas llamadas recursivas quedan en el stack,
	// esto nos ayuda a validar cuando termina la funcion y setear en 0 el count inicial.
	// El uso estatico de las variables es para permitir su permanencia en todo el programa sin re inicializarse entre llamadas. 


	// Caso Base
	if (lista == NULL || n < 1) return;


	countDelta++;
	eliminarNesimoDesdeElFinal(lista->sig, n);
	countDelta--;
	count++;

	// Caso n = largo lista
	if (count == n && countDelta == 0 ) {
		NodoLista* borrar = lista;
		lista = lista->sig;
		delete borrar;
	}

	// Caso n != largo lista 
	if (count == n + 1 ) {
		NodoLista* anterior = lista;
		NodoLista* borrar = anterior->sig;
		anterior->sig = borrar->sig;
		delete borrar;
	}
	
	// Reinicializa variables.
	if (countDelta ==0) {
		count = 0;
		return;
	}

	



/* 
//ITERATIVO: 
	// Caso lista vacia o < 1
	if (lista == nullptr || n < 1) return;

	// Creamos dos nodos
	NodoLista* first = lista;
	NodoLista* sec = lista;

	// Llevamos el primer nodo hasta el final de la lista por ahora seria O(n)
	// Valida asi mismo si n> lista
	for (int i = 0; i < n; ++i) {
		if (first == nullptr) return; 
		first = first->sig;
	}

	// Si el elemento a borrar es el primero de todos (llega hasta n)
	if (first == nullptr) {
		NodoLista* borrar = lista;
		lista = lista->sig; 
		delete borrar;
		return;
	}

	// Ahora movemos hasta llegar al final de la lista, dandonos O(l) que es lo que buscabamos
	// Esto nos deja exactamente uno detras del que queremos eliminar. 
	while (first->sig != nullptr) {
		first = first->sig;
		sec = sec->sig;
	}
	NodoLista* borrar = sec->sig;
	sec->sig = borrar->sig;
	delete borrar;

	*/
}



NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void listaOrdenadaSelectionSort(NodoLista*& l)
{
	// IMPLEMENTAR SOLUCION
}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
