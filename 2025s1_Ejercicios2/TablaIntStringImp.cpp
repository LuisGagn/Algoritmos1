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

void rehashingTabla(TablaIntString& t);

static int hashing(int i, int cota){
	return abs(i%cota);
}

TablaIntString crearTablaIntString(unsigned int esperados) {
	TablaIntString nueva = new _representacionTablaIntString;
	nueva->tabla= new NodoHash*[esperados]();
	nueva->cantidad = 0;
	nueva->cota = esperados;
	return nueva;
}

void copyString(char*& dest, const char* org) {
	int i=0;
	while(org[i]!='\0'){
		dest[i] = org[i];
		i++;
	}
	dest[i] = '\0';
}

void agregar(TablaIntString& t, int d, const char* r) {

	if (t->cantidad+1 >= t->cota) {
		rehashingTabla(t);
	}

	int celda = hashing(d, t->cota);
	NodoHash* lista = t->tabla[celda];
	while(lista && lista->dom!=d){
		lista=lista->sig;
	}
	if(!lista){
		NodoHash* nuevo = new NodoHash;
		nuevo->dom = d;
		nuevo->rn = new char[strlen(r) + 1];
		copyString(nuevo->rn, r);
		nuevo->sig = t->tabla[celda];
		t->tabla[celda]=nuevo;
		t->cantidad++;
	} else {
		lista->rn = new char[strlen(r) + 1];
		copyString(lista->rn, r);
	}
}

void rehashingTabla(TablaIntString& t) {
	unsigned int cotaAnterior = t->cota;
	NodoHash** tablaAnterior = t->tabla;
	t->cota = cotaAnterior * 2;
	t->tabla = new NodoHash * [t->cota]();

	for (unsigned int i = 0; i < cotaAnterior; i++) {
		NodoHash* actual = tablaAnterior[i];
		while (actual != NULL) {
			NodoHash* nodoAMover = actual;
			actual = actual->sig;

			int nuevoIndice = hashing(nodoAMover->dom, t->cota);

			nodoAMover->sig = t->tabla[nuevoIndice];
			t->tabla[nuevoIndice] = nodoAMover;
		}
	}
	delete[] tablaAnterior;
}

bool estaDefinida(TablaIntString t, int d) {
	int celda = hashing(d, t->cota);
	NodoHash* lista = t->tabla[celda];
	while(lista && lista->dom!=d){
		lista=lista->sig;
	}
	return lista!=nullptr;
}

const char* recuperar(TablaIntString t, int d) {
	const char* ret="\0";
	int celda = hashing(d, t->cota);
	NodoHash* lista = t->tabla[celda];
	while(lista && lista->dom!=d){
		lista=lista->sig;
	}
	if(lista){
		ret = lista->rn;
	}
	return ret;
}

void borrar(TablaIntString& t, int d) {
	int celda = hashing(d, t->cota);
	NodoHash* lista = t->tabla[celda];
	NodoHash* prev = nullptr;
	while(lista && lista->dom!=d){
		prev = lista;
		lista=lista->sig;
	}
	if(lista){
		NodoHash* borrar = lista;
		if(prev){
			prev->sig=lista->sig;
		} else {
			t->tabla[celda]=lista->sig;
		}
		delete[] lista->rn; 
		delete borrar;
		t->cantidad--;
	}
	
}

int elemento(TablaIntString t) {
	for(int i =0; i < t->cota; i++){
		NodoHash* lista = t->tabla[i];
		if(lista) return lista->dom;
	}
}

bool esVacia(TablaIntString t) {
	return t->cantidad==0;
}

unsigned int cantidadElementos(TablaIntString t) {
	return t->cantidad;
}

void destruirLista(NodoHash* &l){
	if (l) {
		destruirLista(l->sig);
		delete[] l->rn;
		delete l;
		l = nullptr;
	}
}

void destruir(TablaIntString& t) {
	for(int i =0; i < t->cota; i++){
		NodoHash* lista = t->tabla[i];
		destruirLista(lista);
	}
	delete[] t->tabla;
	delete t;
}

void clonarLista(NodoHash* original, NodoHash*&copia){
	if(original){
		clonarLista(original->sig,copia);
		NodoHash* nodo = new NodoHash;
		nodo->dom = original->dom;
		nodo->rn = new char[strlen(original->rn) + 1];
        	copyString(nodo->rn, original->rn);
		nodo->sig = copia;
		copia = nodo;
	}
}

TablaIntString clon(TablaIntString t) {
	TablaIntString nueva = crearTablaIntString(t->cota);
	for(int i =0; i < t->cota; i++){
		NodoHash* lista = t->tabla[i];
		clonarLista(lista, nueva->tabla[i]);
	}
	nueva->cantidad = t->cantidad;
	return nueva;
}

#endif
