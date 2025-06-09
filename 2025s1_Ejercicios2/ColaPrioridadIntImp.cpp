#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoPrioridad {
	NodoPrioridad* sig;
	NodoPrioridad* same;
	int prio;
	int dato;
};

struct _representacionColaPrioridadInt {
	NodoPrioridad* prim;
	unsigned int cantidad;
	unsigned int cota;
};


ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	ColaPrioridadInt nueva = new _representacionColaPrioridadInt;
	nueva->prim = nullptr;
	nueva->cantidad = 0;
	nueva->cota = cota;
	return nueva;
}

void agregarSegunPrio(NodoPrioridad*& nodo, int e, int p) {

	NodoPrioridad* nuevo = new NodoPrioridad;
	nuevo->sig = nullptr;
	nuevo->same = nullptr;
	nuevo->dato = e;
	nuevo->prio = p;
	NodoPrioridad* actual = nodo;
	NodoPrioridad* prev = nullptr;
	
	while (actual) {
		if (actual->prio == p) {
			while (actual->same) {
				actual = actual->same;
			}
			actual->same= nuevo;
			return;
		}
		else if(actual->prio<p) {
			nuevo->sig = actual;
			if (prev) prev->sig = nuevo;
			else nodo = nuevo;
			return;
		}
		else {
			prev = actual;
			actual = actual->sig;
		}
	}

	if (!actual) {
		if (prev) prev->sig = nuevo;
		else nodo = nuevo;
	}

}

void encolar(ColaPrioridadInt& c, int e, int p) {
	agregarSegunPrio(c->prim, e, p);
	c->cantidad++;
}

int principio(ColaPrioridadInt c) {
	return c->prim->dato;
}

int principioPrioridad(ColaPrioridadInt c) {
	return c->prim->prio;
}


void desencolar(ColaPrioridadInt& c) {
	
	NodoPrioridad* borrar = c->prim;
	c->cantidad--;
	if (borrar->same) {
		c->prim->same->sig= c->prim->sig;
		c->prim = c->prim->same;
		
	}
	else {
		c->prim = c->prim->sig;
	}
	delete borrar;
	
}

bool esVacia(ColaPrioridadInt c) {
	return c->cantidad==0;
}

bool esLlena(ColaPrioridadInt c) {
	return c->cantidad==c->cota;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantidad;
}

NodoPrioridad* clonarSubListaSame(NodoPrioridad* original) {
	if (original == nullptr) {
		return nullptr;
	}

	NodoPrioridad* nuevoNodo = new NodoPrioridad;
	nuevoNodo->dato = original->dato;
	nuevoNodo->prio = original->prio;
	nuevoNodo->sig = nullptr;
	nuevoNodo->same = clonarSubListaSame(original->same);
	return nuevoNodo;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {

	ColaPrioridadInt nueva = crearColaPrioridadInt(c->cota);
	if (esVacia(c)) {
		return nueva;
	}

	NodoPrioridad* actual = c->prim;
	NodoPrioridad* last = nullptr;

	while (actual) {
	
		NodoPrioridad* subLista = clonarSubListaSame(actual);
		if (!last) {
			nueva->prim= subLista;
		}
		else {
			last->sig = subLista;
		}
		last = subLista;
		actual = actual->sig;
	}
	nueva->cantidad = c->cantidad;
	return nueva;
}

void destruirNodos(NodoPrioridad* nodo) {
	if (nodo == nullptr) {
		return;
	}
	destruirNodos(nodo->same);

	destruirNodos(nodo->sig);

	delete nodo;
}

void destruir(ColaPrioridadInt& c) {
	if (c) {
		destruirNodos(c->prim);
		delete c;
		c = nullptr;
	}
}

#endif