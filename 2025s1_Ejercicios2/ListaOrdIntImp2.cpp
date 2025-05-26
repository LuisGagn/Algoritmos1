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




//AUXILIARES FUNCION BORRAR

// PRE: Nodo no es vacio
// POS: Devuelve el nodo mas chico del arbol.
NodoABBRep* minimoNodo(NodoABBRep* nodo) {
	while (nodo->izq) {
		nodo = nodo->izq;
	}
	return nodo;
}

NodoABBRep* maximoNodo(NodoABBRep* nodo) {
	while (nodo->der) {
		nodo = nodo->der;
	}
	return nodo;
}

// PRE: -
// POS: Borra el nodo del arbol adjunto en la lista
void borrarAux(NodoABBRep*& nodo, bool deletefull) {

	if (!nodo) return;

	if (nodo->cant > 1 && !deletefull) {
		nodo->cant--;
	}
	else {
		if (!nodo->izq && !nodo->der) {
			delete nodo;
			nodo = nullptr;
		}
		else {

			if (nodo->izq && nodo->der) {
				NodoABBRep* min = minimoNodo(nodo->der);
				nodo->dato = min->dato;
				nodo->cant = min->cant;
				bool deleteNode = true;
				borrarNodo(nodo->der, min->dato, deleteNode);
				return;
			}

			if (nodo->izq) {
				NodoABBRep* borrar = nodo;
				nodo = nodo->izq;
				delete borrar;
				return;
			}

			if (nodo->der) {
				NodoABBRep* borrar = nodo;
				nodo = nodo->der;
				delete borrar;
				return;
			}
		}
	}
}

// PRE:  
// POS: Busca el nodo con el dato y lo borra segun corresponda dada la funcion borrarAux
//		Cambia el parametro de borrado a True si lo encuentra.
void borrarNodo(NodoABBRep*& nodo, int e, bool& borrado) {
	if (!nodo) return;

	if (nodo->dato == e) {
		// Si borrado es true antes, significa que busca borrar el minimo ya que fue suplantado en alguna parte del arbol.
		if(borrado){
			borrarAux(nodo, true);
		} else {
		borrarAux(nodo,false);
		borrado = true;
		}

	}
	else {
		if (nodo->dato > e) {
			borrarNodo(nodo->izq, e, borrado);
		}
		else {
			borrarNodo(nodo->der, e, borrado);
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
		borrarNodo(l->raiz, e, borrado);
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