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
	// Inicializa y caso Nulo o 1 solo
	if (!l || !l->sig) return nullptr;
	NodoLista* listaInvertida = nullptr;

	// Total de elementos
	int longitud = largoLista(l);
	NodoLista* temp = l;

	// Itera hasta el penultimo y los agrega de a uno al comienzo de la nueva lista.
	for (int i = 0; i < longitud - 1; ++i) {
		agregarPrincipio(listaInvertida, temp->dato);
		temp = temp->sig;
	}
		return listaInvertida;
	}


void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	// IMPLEMENTAR SOLUCION
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
