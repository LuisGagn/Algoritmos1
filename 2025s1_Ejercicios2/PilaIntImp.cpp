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
	assert(!esVacia(p));
	return p->ultimo->dato;
}

void pop(PilaInt& p) {
	
	if(!esVacia(p)){
	NodoPilaInt* borrar = p->ultimo;
	p->ultimo = p->ultimo->sig;
	p->cant --;
	delete borrar;
	}
}

unsigned int cantidadElementos(PilaInt p) {
	return p->cant;
}

bool esVacia(PilaInt p) {
	return p->cant==0;
}

PilaInt clon(PilaInt p) {
	PilaInt aux = crearPilaInt();
	int i = 0;
	while (!esVacia(p)) {
		push(aux, top(p));
		pop(p);
	}

	PilaInt clonada = crearPilaInt();
	while (!esVacia(aux)) {
		push(p, top(aux));
		push(clonada, top(aux));
		pop(aux);
	}

	destruir(aux);

	return clonada;
}

void destruir(PilaInt& p) {
	while(!esVacia(p)){
		pop(p);
	}
	delete p;
	p = nullptr;
}


#endif