#include "Ejercicios.h"

//PRE: 
//POS: 
void enlistarAux(NodoABInt* nodo, ListaOrdInt& l) {
	// Inorder inverso, optimizacion.
	if (nodo) {
		enlistarAux(nodo->der, l);
		agregar(l, nodo->dato);
		enlistarAux(nodo->izq, l);
	}

}

ListaOrdInt Enlistar(NodoABInt* a)
{
	//IMPLEMENTAR SOLUCION

	ListaOrdInt lista = crearListaOrdInt();
	enlistarAux(a, lista);
	return lista;
}

ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
	//IMPLEMENTAR SOLUCION
	ListaOrdInt lista = crearListaOrdInt();


		ListaOrdInt l1Clon = clon(l1);
		ListaOrdInt l2Clon = clon(l2);

	while (!esVacia(l2Clon) && !esVacia(l1Clon)) {
		int minl1 = minimo(l1Clon);
		int minl2 = minimo(l2Clon);
		agregar(lista, minl1);
		agregar(lista, minl2);
		borrar(l1Clon, minl1);
		borrar(l2Clon, minl2);
	}

	if (esVacia(l2Clon)) {
		while (!esVacia(l1Clon)) {
			int minl1 = minimo(l1Clon);
			agregar(lista, minl1);
			borrar(l1Clon, minl1);
		}
	}

	if (esVacia(l1Clon)) {
		while (!esVacia(l2Clon)) {
			int minl2 = minimo(l2Clon);
			agregar(lista, minl2);
			borrar(l2Clon, minl2);
		}
	}



	return lista;
}

bool EstaContenida(PilaInt p1, PilaInt p2)
{
	if (esVacia(p1)) return true;

	if (cantidadElementos(p2) < cantidadElementos(p1)) return false;

	PilaInt aux1 = clon(p1);
	PilaInt aux2 = clon(p2);
	bool encontradosP1= true;

	while (!esVacia(aux1) && encontradosP1) {
		int val1 = top(aux1);
		pop(aux1);
		bool encontrado = false;
		PilaInt volverACrear = crearPilaInt();

		while (!esVacia(aux2)) {
			int val2 = top(aux2);
			pop(aux2);

			if (!encontrado && val1 == val2) {
				encontrado = true;
			}
			else {
				push(volverACrear, val2);
			}
		}

		while (!esVacia(volverACrear)) {
			push(aux2, top(volverACrear));
			pop(volverACrear);
		}
		destruir(volverACrear);

		if (!encontrado) {
			encontradosP1 = false;
		}
	}

	destruir(aux1);
	destruir(aux2);

	return encontradosP1;


}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
	//IMPLEMENTAR SOLUCION
	return NULL;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	//IMPLEMENTAR SOLUCION
	return NULL;
}

