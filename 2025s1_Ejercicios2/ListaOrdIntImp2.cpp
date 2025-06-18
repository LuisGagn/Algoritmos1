#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2
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


// PRE: Nodo no es vacio
// POS: Devuelve el nodo mas chico del arbol.
NodoABBRep* minimoNodo(NodoABBRep* nodo) {
	while (nodo->izq) {
		nodo = nodo->izq;
	}
	return nodo;
}

// PRE:  
// POS: Elimina un nodo existente. 
void borrarNodo(NodoABBRep*& nodo, bool & borrado);

// PRE:  
// POS: Busca el nodo con el dato y lo borra segun corresponda dada la funcion borrarAux
//		Cambia el parametro de borrado a True si lo encuentra.
void borrarNodoEspecifico(NodoABBRep*& nodo, int e, bool destroy, bool& borrado) {
	if (!nodo) return;
	if (e < nodo->dato) {
		borrarNodoEspecifico(nodo->izq, e, destroy, borrado);
	}
	else if (e > nodo->dato) {
		borrarNodoEspecifico(nodo->der, e, destroy, borrado);
	}
	else {
		if (destroy) nodo->cant = 1;
		borrarNodo(nodo, borrado);
		borrado = true;
	}

}

void borrarNodo(NodoABBRep*& nodo, bool& borrado) {
	if (nodo == nullptr) return;


	if (nodo->cant > 1) {
		nodo->cant--;
	} else {

		// Caso hoja simple
	if (!nodo->izq && !nodo->der) {
		delete nodo;
		nodo = nullptr;
		return;
	}
	// Caso solo hijo
	if (!nodo->izq) {
		NodoABBRep* borrar = nodo;
		nodo = nodo->der;
		delete borrar;
		return;
	}
	else if (!nodo->der) {
		NodoABBRep* borrar = nodo;
		nodo = nodo->izq;
		delete borrar;
		return;
	}
	// Caso dos hijos
	else {
		NodoABBRep* min = minimoNodo(nodo->der);
		nodo->dato = min->dato;
		nodo->cant = min->cant;
		borrarNodoEspecifico(nodo->der, nodo->dato, true, borrado);
	}

	}


}


// FUNCIONES PRINCIPALES

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
		int min = minimo(l);
		borrar(l,min);
	}
	
}

void borrarMaximo(ListaOrdInt& l) {
	if (!esVacia(l)) {
		int max = maximo(l);
		borrar(l, max);
	}

}

void borrar(ListaOrdInt& l, int e) {
	if (!esVacia(l)) {
		bool borrado = false;
		borrarNodoEspecifico(l->raiz, e,false, borrado);
		if(borrado)l->cantidadElementos--;
	}
}

int minimo(ListaOrdInt l) {

	NodoABBRep* aux = l->raiz;
	while (aux->izq) {
		aux = aux->izq;
	}
	return aux->dato;
}

int maximo(ListaOrdInt l) {
	NodoABBRep* aux = l->raiz;
	while (aux->der) {
		aux = aux->der;
	}

	return aux->dato;
}

bool existe(ListaOrdInt l, int e) {
	if (esVacia(l)) return false;
	bool encontrado = false;
	NodoABBRep* aux = l->raiz;
	while (aux&& !encontrado) {
		if (aux->dato == e) {
			encontrado = true;
		}
		 else if (aux->dato > e) {
			aux = aux->izq;
		}
		else {
			aux = aux->der;
		}
	}
	return encontrado;
}

bool esVacia(ListaOrdInt l) {
	return l->cantidadElementos==0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->cantidadElementos;
}

// PRE: Lista no es nullptr
// POS: agrega los nodos a la lista.
void auxAgregar(NodoABBRep* nodo, ListaOrdInt& l) {
	
	if (!nodo) return;

	for(int i = 0; i<nodo->cant; i++){
		agregar(l, nodo->dato);
	}
	auxAgregar(nodo->izq, l);
	auxAgregar(nodo->der, l);
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt nueva = crearListaOrdInt();

	if (!esVacia(l)) {
		auxAgregar(l->raiz, nueva);
	}
	return nueva;
}

// PRE: - 
// POS: Elimina todos los nodos.
void destruirABB(NodoABBRep*& nodo) {
	if (!nodo) return;
	destruirABB(nodo->der);
	destruirABB(nodo->izq);
	delete nodo;
	nodo = nullptr;
}

void destruir(ListaOrdInt& l) {

	if (!esVacia(l)) {
		destruirABB(l->raiz);
	}
	delete l;
	l = nullptr;

}



#endif