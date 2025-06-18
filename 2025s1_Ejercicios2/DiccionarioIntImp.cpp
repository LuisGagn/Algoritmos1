#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoHash{
	int dato;
	NodoHash* sig;
};

struct _representacionDiccionarioInt {
	NodoHash** tabla;
	int cantidad;
	int cota;
};

// PRE: d no es null
// POS: Incrementa el espacio del bucket list del diccionario y reorganiza los elementos
void rehashingDict(DiccionarioInt& d);


// PRE:
// Esta funcion asigna a i en el array en cuestion de 0 -> cota-1 
int hashing(int i, int cota) {
	if (i < 0) i = i * -1;
	return i % cota;
}

// Diccionario tiene que tener un array (Puntero de punteros).  
// Luego se guarda como una lista cadenada en cada puntero.
// Esperados seria la cantidad de objetos(lugares del array, o cota)1
DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
	DiccionarioInt d = new _representacionDiccionarioInt;
 	d->tabla = new NodoHash* [esperados];
	// Creamos el array
 	for (int i=0; i<esperados; i++){ 
		d->tabla[i] = NULL;
	} // Inicializamos en null
	// cantidad de datos actuales = 0, cota = tamaño del array.
 		d->cantidad = 0;
 		d->cota = esperados;
 	return d;
}

void agregar(DiccionarioInt& d, int e) {
	// No hay repetidos, por lo que si existe no lo agregamos
	if (!pertenece(d, e)) {
		if (d->cantidad + 1 >= d->cota) {
			rehashingDict(d);
		}

		// Creamos un nodo (Lista encadenada lo mismo)
		NodoHash* nuevo = new NodoHash;
		nuevo->dato = e;
		nuevo->sig = d->tabla[hashing(e, d->cota)]; // El valor que sigue a nuestro nodo sera el primer puntero en el array en la posicion que nos de el hash.
		d->tabla[hashing(e, d->cota)] = nuevo; // Mandamos nuestro nodo como primer puntero del array en el hash
		d->cantidad++;
	}
}

void rehashingDict(DiccionarioInt& d) {
	int cotaAnterior = d->cota;
	NodoHash** tablaAnterior = d->tabla;
	d->cota = cotaAnterior * 2;
	d->tabla = new NodoHash * [d->cota];
	for (int i = 0; i < d->cota; i++) {
		d->tabla[i] = NULL;
	}

	for (int i = 0; i < cotaAnterior; i++) {
		NodoHash* actual = tablaAnterior[i];
		while (actual) {
			NodoHash* nodoAMover = actual;
			actual = actual->sig;
			int nuevoIndice = hashing(nodoAMover->dato, d->cota);
			nodoAMover->sig = d->tabla[nuevoIndice];
			d->tabla[nuevoIndice] = nodoAMover;
		}
	}
	delete[] tablaAnterior;
}


void borrar(DiccionarioInt& d, int e) {
	if (!esVacio(d)) {
		NodoHash* aux = d->tabla[hashing(e, d->cota)];
		NodoHash* prev = nullptr;
		while (aux) {
			if (aux->dato == e) { // Busca en el puntero de la tabla segun el hashing como si fuera una lista
				NodoHash* borrar = aux;
				if (prev) { // Si no es el primer elemento
					prev->sig = aux->sig;
				}
				else { // Si es el primer elemento
					d->tabla[hashing(e, d->cota)] = aux->sig;
				}
				delete borrar;
				d->cantidad--;
				return;
			}
			prev = aux;
			aux = aux->sig;
		}
	}
}

bool pertenece(DiccionarioInt d, int e) {
	if (!esVacio(d)) {
		NodoHash* aux = d->tabla[hashing(e, d->cota)];
		while (aux) {
			if (aux->dato == e) { // Busca en el puntero de la tabla segun el hashing como si fuera una lista
				return true;
			}
			else {
				aux = aux->sig;
			}
		}
	}
	return false;
}

int elemento(DiccionarioInt d) {
	for (int i = 0; i < d->cota; i++) {
		if (d->tabla[i]) {
			return d->tabla[i]->dato;
		}
	}
}

bool esVacio(DiccionarioInt d) {
	return d->cantidad==0;
}

unsigned int cantidadElementos(DiccionarioInt d) {
	return d->cantidad;
}

DiccionarioInt clon(DiccionarioInt d) {
	DiccionarioInt nuevo = crearDiccionarioInt(d->cota);

	for (int i = 0; i < d->cota; i++) {
		NodoHash* aux = d->tabla[i];
		while (aux) {
			// Agregar tiene orden O(1) asi que lo uso en ves de hacer algo mas avanzado.
			agregar(nuevo, aux->dato);
			aux = aux->sig;
		}
	}
	return nuevo;
}

// PRE: 
// POS: Elimina los nodos dentro del bucket.
void destruirNodosHash(NodoHash*& nodo) {
	if (nodo) {
		destruirNodosHash(nodo->sig);
		delete nodo;
		nodo = nullptr;
	}

}

void destruir(DiccionarioInt& d) {
	for (int i = 0; i < d->cota; i++) {
		destruirNodosHash(d->tabla[i]);
	}
	delete[] d->tabla;
	delete d;
	d = nullptr;
}


#endif
