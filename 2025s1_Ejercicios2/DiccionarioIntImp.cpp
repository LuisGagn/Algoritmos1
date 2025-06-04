#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

//Si necestita otra estructura se puede definir aqui

int hash(int i, int cota){
	return i%cota;
		}

struct NodoHash{
	int dato;
	NodoHash* sig;
};

struct _representacionDiccionarioInt {
	NodoHash** tabla;
	int cantidad;
	int cota;
};

DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt d = new _representacionDiccionarioInt;
 	d->tabla = new NodoHash* [esperados];
 	for (int i=0; i<esperados; i++){ 
		d->tabla[i]=NULL
	};
 		d->cantidad = 0;
 		d->cota = esperados;
 	return d;
}

void agregar(DiccionarioInt& d, int e) {
	
}

void borrar(DiccionarioInt& d, int e) {
	// NO IMPLEMENTADO
}

bool pertenece(DiccionarioInt d, int e) {
	// NO IMPLEMENTADO
	return false;
}

int elemento(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return 0;
}

bool esVacio(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return 0;
}

DiccionarioInt clon(DiccionarioInt d) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(DiccionarioInt& d) {
	// NO IMPLEMENTADO
}


#endif
