#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoHash {
	int dom;
	char* rn;
	NodoHash* sig;
};

struct _representacionTablaIntString {
	NodoHash** tabla;
	unsigned int cantidad;
	unsigned int cota;
};


int hashing(int i; int cota){
	return abs(i%cota);
}

TablaIntString crearTablaIntString(unsigned int esperados) {
	TablaIntString nueva = new _representacionTablaIntString;
	nueva->cantidad = 0;
	nueva->cota = esperados;
	return NULL;
}


void agregar(TablaIntString& t, int d, const char* r) {
	int celda = hashing(d, t->cota);
	NodoHash* lista = t->tabla[celda];
	while(lista && lista->dom!=d){
		lista=lista->sig;
	}
	if(!lista){
		NodoHash* nuevo = new NodoHash;
		nuevo->dom = d;
		nuevo->rn = r;
		nuevo->sig = t->tabla[celda];
		t->tabla[celda]=nuevo;
		t->cantidad++;
	} else {
		lista->rn =r;
	}
}

bool estaDefinida(TablaIntString t, int d) {
	// NO IMPLEMENTADO
	return NULL;
}

const char* recuperar(TablaIntString t, int d) {
	// NO IMPLEMENTADO
	return "";
}

void borrar(TablaIntString& t, int d) {
	// NO IMPLEMENTADO
}

int elemento(TablaIntString t) {
	// NO IMPLEMENTADO
	return 0;
}

bool esVacia(TablaIntString t) {
	// NO IMPLEMENTADO
	return t->cantidad==0;
}

unsigned int cantidadElementos(TablaIntString t) {
	// NO IMPLEMENTADO
	return t->cantidad;;
}

void destruir(TablaIntString& t) {
	// NO IMPLEMENTADO
}

TablaIntString clon(TablaIntString t) {
	// NO IMPLEMENTADO
	return NULL;
}

#endif
