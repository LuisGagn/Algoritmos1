#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP
// ABB CON NODO PARTIDO CANTIDAD Y DATO

struct NodoABBRep {
	int dato;
	int cant;
	NodoABBRep* izq;
	NodoABBRep* der;

};

struct _representacionListaOrdInt {
	NodoABBRep* raiz;
	unsigned int cantidadElementos;
};

ListaOrdInt crearListaOrdInt() {
	ListaOrdInt nueva = new _representacionListaOrdInt;
	nueva->raiz = nullptr;
	nueva->cantidadElementos = 0;
	return nueva;
}
//PRE: - 
//POS: Agrega el nodo en la posicion correcta, en caso de existir, suma 1 a la cantidad.
void agregarEnNodo(NodoABBRep*& raiz, int e) {
	if (!raiz) {
		NodoABBRep* nodo = new NodoABBRep;
		nodo->dato = e;
		nodo->cant = 1;
		nodo->izq = nullptr;
		nodo->der = nullptr;
		raiz = nodo;
		return;
	}

	if (raiz->dato == e) {
		raiz->cant++;
		return;
	} 

	if (raiz->dato > e) {
		agregarEnNodo(raiz->izq, e);
	}
	else {
		agregarEnNodo(raiz->der, e);
	}

}

void agregar(ListaOrdInt& l, int e) {
	agregarEnNodo(l->raiz, e);
	l->cantidadElementos++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (!esVacia(l)) {
		NodoABBRep *aux = l->raiz;
		while (aux->izq) {
			aux = aux->izq;
		}
		borrar(aux);
		if(aux->cant==1){
			delete aux;
			aux = nullptr;
		}
		else {
			aux->cant--;
		}
	}
}

void borrarMaximo(ListaOrdInt& l) {
	if (!esVacia(l)) {
		NodoABBRep* aux = l->raiz;
		while (aux->der) {
			aux = aux->der;
		}
		if (aux->cant == 1) {
			delete aux;
			aux = nullptr;
		}
		else {
			aux->cant--;
		}
	}
}

void borrar(ListaOrdInt& l, int e) {
	if (!esVacia(l)) {





	}
}

int minimo(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

int maximo(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

bool existe(ListaOrdInt l, int e) {
	// NO IMPLEMENTADO
	return false;
}

bool esVacia(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return 0;
}

ListaOrdInt clon(ListaOrdInt l) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ListaOrdInt& l) {
	// NO IMPLEMENTADO
}



#endif