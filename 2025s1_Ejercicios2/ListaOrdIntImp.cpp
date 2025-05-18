#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP

struct NodoListaOrdInt {
	int dato;
	NodoListaOrdInt* sig;
};

struct _representacionListaOrdInt {
	NodoListaOrdInt* ppio;
	unsigned int largo;
};

/* AUXILIARES */

// PRE:
// POS: Agrega el dato ordenado creando un nuevo nodo
void agregar(NodoListaOrdInt*& l, int dato) {
	if (l == NULL) {
		l = new NodoListaOrdInt;
		l->dato = dato;
		l->sig = NULL;
	}
	else if (dato <= l->dato) {
		NodoListaOrdInt* nuevo = new NodoListaOrdInt;
		nuevo->dato = dato;
		nuevo->sig = l;
		l = nuevo;
	}
	else { // if (dato > l->dato)
		agregar(l->sig, dato);
	}
}

// PRE:
// POS: Borra el nodo con el dato maximo
bool borrarMaximo(NodoListaOrdInt*& l) {
	if (l == NULL) {
		return false;
	}
	if (l->sig != NULL) {
		return borrarMaximo(l->sig);
	}
	NodoListaOrdInt* temp = l;
	l = l->sig;
	delete temp;
	return true;
}


// PRE:
// POS: Borra el nodo con el dato
bool borrar(NodoListaOrdInt*& l, int dato) {
	if (l == NULL) return false;
	if (dato > l->dato) {
		return borrar(l->sig, dato);
	}
	if (dato < l->dato) {
		return false;
	}
	NodoListaOrdInt* temp = l;
	l = l->sig;
	delete temp;
	return true;
}

// PRE:
// POS: Borra todos los nodos
void vaciar(NodoListaOrdInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

// PRE:
// POS: Retorna un puntero a la copia de todos los nodos
NodoListaOrdInt* clon(NodoListaOrdInt* l) {
	if (l == NULL) return NULL;
	NodoListaOrdInt* nuevo = new NodoListaOrdInt;
	nuevo->dato = l->dato;
	nuevo->sig = clon(l->sig);
	return nuevo;
}

// PRE:
// POS: Retorna si existe el dato en un nodo
bool existe(NodoListaOrdInt* l, int dato) {
	if (l == NULL) return false;
	if (dato > l->dato) {
		return existe(l->sig, dato);
	}
	if (dato < l->dato) {
		return false;
	}
	return true;
}
/* FIN AUXILIARES */


ListaOrdInt crearListaOrdInt() {
	ListaOrdInt cabezal = new _representacionListaOrdInt;
	cabezal->ppio = NULL;
	cabezal->largo = 0;
	return cabezal;
}

void agregar(ListaOrdInt& l, int e) {
	agregar(l->ppio, e);
	l->largo++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (l->ppio == NULL) return;
	NodoListaOrdInt *borro = l->ppio;
	l->ppio = l->ppio->sig;
	l->largo--;
	delete borro;
}

void borrarMaximo(ListaOrdInt& l) {
	if (borrarMaximo(l->ppio)) l->largo--;
}

void borrar(ListaOrdInt& l, int e) {
	if (borrar(l->ppio, e)) l->largo--;
}

int minimo(ListaOrdInt l) {
	assert(!esVacia(l));
	return l->ppio->dato;
}

int maximo(ListaOrdInt l) {
	assert(!esVacia(l));
	NodoListaOrdInt* aux = l->ppio;
#pragma warning(suppress: 28182) // Con esto evitamos que se muestre el warning 28182 en la siguiente linea
	while (aux->sig != NULL) {
		aux = aux->sig;
	}
	return aux->dato;
}

bool existe(ListaOrdInt l, int e) {
	return existe(l->ppio, e);
}

bool esVacia(ListaOrdInt l) {
	return l->largo == 0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->largo;
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt cabezal = new _representacionListaOrdInt;
	cabezal->ppio = clon(l->ppio);
	cabezal->largo = l->largo;
	return cabezal;
}

void destruir(ListaOrdInt& l) {
	vaciar(l->ppio);
	delete l;
	l = NULL;
}



#endif