#include "ColaInt.h"

#ifdef COLA_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoCola{
	int valor;
	NodoCola* sig;
};

struct _representacionColaInt {
	NodoCola* primero;
	NodoCola* ultimo;
	int cantElementos;
};

ColaInt crearColaInt() {
	ColaInt c = new _representacionColaInt;
	c->primero=c->ultimo=nullptr;
	c->cantElementos = 0;
	return c;
}

void encolar(ColaInt& c, int e) {
	NodoCola* nuevo = new NodoCola;
	nuevo->valor = e;
	nuevo->sig = nullptr;
	if(!c->primero){ 
		c->primero = nuevo;
	} else {
		c->ultimo->sig = nuevo;
	}
	c->ultimo = nuevo;
	c->cantElementos++;
}

int principio(ColaInt c) {
	return c->primero->valor;
}

void desencolar(ColaInt& c) {
	NodoCola* temp = c->primero;
	c->primero = c->primero->sig;
	if(!c->primero) c->ultimo = nullptr;
	delete temp;
	c->cantElementos--;
}

bool esVacia(ColaInt c) {
	return c->cantElementos==0;
}

unsigned int cantidadElementos(ColaInt c) {
	return c->cantElementos;
}

ColaInt clon(ColaInt c) {
	ColaInt nueva = crearColaInt();
	NodoCola* temp = c->primero;
	while(temp){
		encolar(nueva,temp->valor);
		temp=temp->sig;
	}

	return nueva;
}

void destruir(ColaInt& c) {
	NodoCola* temp;
	while(c->primero){
		temp=c->primero;
		c->primero = c->primero->sig;
		delete temp;
	}
	delete c;
	c=nullptr;
}

#endif
