#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoLInt{
	NodoLint* sig;
	int dato;
	int cant;
}	

struct _representacionMultisetInt {
	NodoLint* primero;
	int cantidad;
};

MultisetInt crearMultisetInt() {
	MultisetInt nueva = new _representacionMultisetInt;
	nueva->primero=nullptr;
	nueva->cantidad = 0;
	return nueva;
}

void agregarRecursivo(NodoLInt* &p,int e, unsigned int oc){
	if(p){
		NodoLInt* aux=nullptr;

		while(p){
		if(p->dato==e){
			p->cant+=oc;
		} else{
			if(p->dato<e){
				aux=p;
				p=p->sig;
			} elseif(p->dato>e){
				NodoLInt* nuevo = new NodoLInt;
				nuevo->dato = e;
				nuevo->cant = oc;
				nuevo->sig = p;
				if(aux){
				aux->sig = nuevo;
				} else {
				p=nuevo;
				
				}
				return;
			}
		}
	}
	}
	if(!p){
	NodoLInt* nuevo = new NodoLInt;
	nuevo->dato = e;
	nuevo->cant = oc;
	nuevo->sig = p;
	p=nuevo;
		return;
	}
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias){
	
}

void borrar(MultisetInt& s, int e) {
	// NO IMPLEMENTADO
}

bool pertenece(MultisetInt s, int e) {
	// NO IMPLEMENTADO
	return false;
}

MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	return NULL;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	return NULL;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	return NULL;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	// NO IMPLEMENTADO
	return false;
}

int elemento(MultisetInt s) {
	// NO IMPLEMENTADO
	return 0;
}

bool esVacio(MultisetInt s) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(MultisetInt s) {
	// NO IMPLEMENTADO
	return 0;
}

void destruir(MultisetInt& s) {
}

MultisetInt clon(MultisetInt s) {
	// NO IMPLEMENTADO
	return NULL;
}

#endif
