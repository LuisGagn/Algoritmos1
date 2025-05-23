#include "PilaInt.h"

#ifdef PILA_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoPilaInt {
	int dato;
	NodoPilaInt* sig;
};

struct _representacionPilaInt {
	NodoPilaInt* ultimo;
	unsigned int cant;
};



PilaInt crearPilaInt() {
	PilaInt nuevaPila = new _representacionPilaInt;
	nuevaPila->ultimo = nullptr;
	nuevaPila->cant = 0;
	return nuevaPila;
}

void push(PilaInt& p, int e) {
	NodoPilaInt* nodo = new NodoPilaInt;

	nodo->dato = e;
	nodo->sig = p->ultimo;
	p->ultimo = nodo;
	p->cant += 1;

}

int top(PilaInt p) {
	//if (esVacia(p)) return NULL;
	return p->ultimo->dato;;
}

void pop(PilaInt& p) {
	
	if(!esVacia){

	NodoPilaInt* borrar = p->ultimo;
	p->ultimo = p->ultimo->sig;
	p->cant -= 1;
	delete borrar;
	}
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cant;
}

bool esVacia(PilaInt p) {
	
	return p->cant!=0;
}

PilaInt clon(PilaInt p) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(PilaInt& p) {
	int i = p->cant;
	for (int j = 0;j < i;j++) {
		pop(p);
	}
}


#endif