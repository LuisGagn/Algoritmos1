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
	ListaOrdInt ret = crearListaOrdInt();

	while(!esVacio(m)){
		int dato = elemento(m);
		borrar(m,dato);
		if(pertenece(m,dato)){
		while(pertenece(m,dato)){
			borrar(m,dato);
		}
			agregar(ret,dato);
		}
		
	}
	
	
	return ret;
}


MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{	
	// m1 = 1 2 3 4 4 
	// m2 = 1 1 3 4 
	MultisetInt difm1 = diferenciaConjuntos(m1,m2); // 2 4
	MultisetInt difm2 = diferenciaConjuntos(m2,m1); // 1
	MultisetInt m1m2 = unionConjuntos(difm1, difm2);

	destruir(difm1);
	destruir(difm2);

	return m1m2;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
	
	if (!esVacia(c)) {

	ColaPrioridadInt aux = clon(c);

	int minima=0;

	// Nos da el minimo de prioridad general O(n)
	while (!esVacia(aux)) {
		minima = principioPrioridad(aux);
		desencolar(aux);
	}
	aux = clon(c);
	
	// Borra todos los que son mayores a la minima prioridad O(n)

	while (!esVacia(aux) && principioPrioridad(aux)!=minima) {
		desencolar(aux);
	}
	ColaPrioridadInt nueva = crearColaPrioridadInt(cantidadElementos(aux));


	while (!esVacia(aux)) {
		int dato = principio(aux);
		encolar(nueva, dato, minima);
		desencolar(aux);
	}
	
	return nueva;
	}
	else { 
	
		return crearColaPrioridadInt(0);
	}


}

