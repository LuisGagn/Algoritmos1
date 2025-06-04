#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct NodoLInt {
	NodoLInt* sig;
	int dato;
	unsigned int cant;
};

struct _representacionMultisetInt {
	NodoLInt* primero;
	unsigned int cantidad;
};

MultisetInt crearMultisetInt() {
	MultisetInt nueva = new _representacionMultisetInt;
	nueva->primero=nullptr;
	nueva->cantidad = 0;
	return nueva;
}

void agregar(MultisetInt& s, int e, unsigned int ocurrencias){

	if (!esVacio(s)) {
		NodoLInt* actual = s->primero;
		NodoLInt* prev = nullptr;

		while (actual) {
			if (actual->dato == e) {
				actual->cant+=ocurrencias;
				break;
			}
			else if (actual->dato < e) { 
					prev = actual;
					actual = actual->sig;
			}
			else {
				NodoLInt* nuevo = new NodoLInt;
				nuevo->dato = e;
				nuevo->cant = ocurrencias;
				nuevo->sig = actual;
				if (prev) prev->sig = nuevo;
				else s->primero = nuevo;
				break;
			}
			
		}
	
		if (!actual) {
			NodoLInt* nuevo = new NodoLInt;
			nuevo->dato = e;
			nuevo->cant = ocurrencias;
			nuevo->sig = nullptr;
			prev->sig = nuevo;
		}

	}
	else {
		NodoLInt* nuevo = new NodoLInt;
		nuevo->dato = e;
		nuevo->cant = ocurrencias;
		nuevo->sig = s->primero;
		s->primero = nuevo;
	}

	s->cantidad += ocurrencias;
}

void borrar(MultisetInt& s, int e) {
	if (!esVacio(s)) {
		NodoLInt* prev = nullptr;
		NodoLInt* actual = s->primero;
		bool borrado = false;
		while (actual && !borrado) {
			if (actual->dato == e) {
				if (actual->cant > 1) {
					actual->cant--;
					borrado = true;
				}
				else {
					NodoLInt* borrar = actual;
					if(prev){
					prev->sig = actual->sig;
					delete borrar;
					}
					else {
						s->primero = actual->sig;
						delete borrar;
					}
					borrado = true;
				}
			}
			else {
				prev = actual;
				actual = actual->sig;
			}
		}

		if (borrado) s->cantidad--;

	}
	
}

bool pertenece(MultisetInt s, int e) {
	if (!esVacio(s)){
	NodoLInt* aux = s->primero;
	while (aux) {
		if (aux->dato == e) return true;
		aux = aux->sig;
	}
	}
	return false;
	
}

// En ves de hacer que agregue, aprovecho qu estan ordenados por default y hago el agregado manual, haciendo que sea mas optima la union
// de O(n*m) a O(n+m)
MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt nuevo = crearMultisetInt();

	NodoLInt* aux1 = s1->primero;
	NodoLInt* aux2 = s2->primero;
	NodoLInt* last = nuevo->primero;

	while (aux1 && aux2) {

		if (aux1->dato < aux2->dato) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = aux1->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux1->cant;
			aux1 = aux1->sig;
		}
		else if (aux1->dato > aux2->dato) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux2->dato;
			nodo->cant = aux2->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux2->cant;
			aux2 = aux2->sig;
		}
		else { // Igual numero
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = max(aux1->cant, aux2->cant);
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += max(aux1->cant, aux2->cant);
			aux1 = aux1->sig;
			aux2 = aux2->sig;
		}
	}

	if (aux1) {
		while (aux1) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = aux1->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux1->cant;
			aux1 = aux1->sig;
		}
	}
	else {
		while (aux2) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux2->dato;
			nodo->cant = aux2->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux2->cant;
			aux2 = aux2->sig;
		}
	}
	

	return nuevo;
}

MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt nuevo = crearMultisetInt();

	NodoLInt* aux1 = s1->primero;
	NodoLInt* aux2 = s2->primero;
	NodoLInt* last = nuevo->primero;

	while (aux1 && aux2) {

		if (aux1->dato < aux2->dato) {
			aux1 = aux1->sig;
		}
		else if (aux1->dato > aux2->dato) {
			aux2 = aux2->sig;
		}
		else { // Igual numero
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = min(aux1->cant, aux2->cant);
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += min(aux1->cant, aux2->cant);
			aux1 = aux1->sig;
			aux2 = aux2->sig;
			
		}
	}

	return nuevo;
}

MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
	MultisetInt nuevo = crearMultisetInt();

	NodoLInt* aux1 = s1->primero;
	NodoLInt* aux2 = s2->primero;
	NodoLInt* last = nuevo->primero;

	while (aux1 && aux2) {

		if (aux1->dato < aux2->dato) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = aux1->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux1->cant;
			aux1 = aux1->sig;
		}
		else if (aux1->dato > aux2->dato) {
			aux2 = aux2->sig;
		}
		else { // Toma los que estan.
			if (aux1->cant > aux2->cant) {
				NodoLInt* nodo = new NodoLInt;
				nodo->dato = aux1->dato;
				nodo->cant = aux1->cant-aux2->cant;
				nodo->sig = nullptr;
				if (!last) nuevo->primero = nodo;
				else last->sig = nodo;
				last = nodo;
				nuevo->cantidad += aux1->cant-aux2->cant;
			}


			aux1 = aux1->sig;
			aux2 = aux2->sig;
		}
	}

	if (aux1) {
		while (aux1) {
			NodoLInt* nodo = new NodoLInt;
			nodo->dato = aux1->dato;
			nodo->cant = aux1->cant;
			nodo->sig = nullptr;
			if (!last) nuevo->primero = nodo;
			else last->sig = nodo;
			last = nodo;
			nuevo->cantidad += aux1->cant;
			aux1 = aux1->sig;
		}
	}
	


	return nuevo;
}

bool contenidoEn(MultisetInt s1, MultisetInt s2) {
	if (esVacio(s2)) return esVacio(s1);
	if (esVacio(s1)) return true;
	
	NodoLInt* aux1 = s1->primero;
	NodoLInt* aux2 = s2->primero;
	bool existen = true;
	while (aux1 && aux2 && existen) {

		if (aux1->dato < aux2->dato) {
			existen = false;
		}
		else if (aux1->dato > aux2->dato) {
			aux2 = aux2->sig;
		}
		else { // Igual numero
			if(aux1->cant > aux2->cant){
				existen = false;
		}
			aux1 = aux1->sig;
			aux2 = aux2->sig;
		}
	}

	if (aux1) existen = false;

	return existen;
}

int elemento(MultisetInt s) {
	return s->primero->dato;
}

bool esVacio(MultisetInt s) {
	return s->cantidad==0;
}

unsigned int cantidadElementos(MultisetInt s) {
	return s->cantidad;
}

void destruir(MultisetInt& s) {
	NodoLInt* aux = s->primero;
	while (aux) {
		NodoLInt* borrar = aux;
		aux = aux->sig;
		delete borrar;
	}
	delete s;
	s = nullptr;
}

// Es mas optimo hacer esto ya que se que es ordenada de min a max, que usar agregar
// Pasa de O(n*n) a O(n)
MultisetInt clon(MultisetInt s) {
	MultisetInt nuevo = crearMultisetInt();
	NodoLInt* aux1 = s->primero;
	NodoLInt* last = nuevo->primero;
	while (aux1) {
		NodoLInt* nodo = new NodoLInt;
		nodo->dato = aux1->dato;
		nodo->cant = aux1->cant;
		nodo->sig = nullptr;
		if (!last) nuevo->primero = nodo;
		else last->sig = nodo;
		last = nodo;
		aux1 = aux1->sig;
	}
	nuevo->cantidad = s->cantidad;
	return nuevo;
}

#endif
