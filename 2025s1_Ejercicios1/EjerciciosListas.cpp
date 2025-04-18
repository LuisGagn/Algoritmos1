#include "EjerciciosListas.h"



void agregarPrincipio(NodoLista* &lista, int dato) {

	NodoLista* nodo = new NodoLista;
	nodo->dato = dato;
	nodo->sig = lista;
	lista = nodo;
}

int largoLista(NodoLista* &lista) {
	int largo = 0;
	NodoLista* temp = lista;
	while (temp) {
		largo++;
		temp = temp->sig;
	}
	return largo;
	delete[] temp;
}

NodoLista* invertirParcial(NodoLista* l) 
{
	// Caso base: Lista nula o de 1 item
	if (!l || !l->sig) return nullptr;
	NodoLista* listaInvertida = nullptr;
	
	while (l->sig) {
		agregarPrincipio(listaInvertida, l->dato);
		l = l->sig;
	}
		return listaInvertida;
		delete[] listaInvertida;
	}

void eliminarNesimoDesdeElFinal(NodoLista*& lista, int &n) 
{
	
//RECURSIVO: 
	static int count = 0;
	static int countDelta = 0;
	// Count verigica la cantidad de veces que volvio de recursion, ayudandonos a eliminar el correcto.
	// CountDelta lleva la cuenta de cuantas llamadas recursivas quedan en el stack,
	// esto nos ayuda a validar cuando termina la funcion y setear en 0 el count inicial.
	// El uso estatico de las variables es para permitir su permanencia en todo el programa sin re inicializarse entre llamadas. 


	// Caso Base
	if (lista == NULL || n < 1) return;


	countDelta++;
	eliminarNesimoDesdeElFinal(lista->sig, n);
	countDelta--;
	count++;

	// Caso n = largo lista
	if (count == n && countDelta == 0 ) {
		NodoLista* borrar = lista;
		lista = lista->sig;
		delete borrar;
	}

	// Caso n != largo lista 
	if (count == n + 1 ) {
		NodoLista* anterior = lista;
		NodoLista* borrar = anterior->sig;
		anterior->sig = borrar->sig;
		delete borrar;
	}
	
	// Reinicializa variables.
	if (countDelta ==0) {
		count = 0;
		return;
	}

	



/* 
//ITERATIVO: 
	// Caso lista vacia o < 1
	if (lista == nullptr || n < 1) return;

	// Creamos dos nodos
	NodoLista* first = lista;
	NodoLista* sec = lista;

	// Llevamos el primer nodo hasta el final de la lista por ahora seria O(n)
	// Valida asi mismo si n> lista
	for (int i = 0; i < n; ++i) {
		if (first == nullptr) return; 
		first = first->sig;
	}

	// Si el elemento a borrar es el primero de todos (llega hasta n)
	if (first == nullptr) {
		NodoLista* borrar = lista;
		lista = lista->sig; 
		delete borrar;
		return;
	}

	// Ahora movemos hasta llegar al final de la lista, dandonos O(l) que es lo que buscabamos
	// Esto nos deja exactamente uno detras del que queremos eliminar. 
	while (first->sig != nullptr) {
		first = first->sig;
		sec = sec->sig;
	}
	NodoLista* borrar = sec->sig;
	sec->sig = borrar->sig;
	delete borrar;

	*/
}


void insertarOrdenado(NodoLista*& l, int valor) {

	// Creamos el nodo para no compartir memoria
	NodoLista* nuevo = new NodoLista;
	nuevo->dato = valor;
	nuevo->sig = nullptr;

	// La lista esta vacia o el valor es mas chico que el primero.
	if (!l || valor < l->dato) {
		nuevo->sig = l;
		l = nuevo;
	}
	else {
		// Buscamos la posicion en que es valido insertar el nuevo elemento.
		NodoLista* actual = l;
		while (actual->sig && actual->sig->dato < valor) {
			actual = actual->sig;
		}
		// Indicamos el nuevo nodo en dicha posiscion.
		nuevo->sig = actual->sig;
		actual->sig = nuevo;
	}
}

NodoLista* listaOrdenadaInsertionSort(NodoLista* l) 
{
	NodoLista* listaOrdenada = nullptr;
	NodoLista* actual = l;

	while (actual) {
		NodoLista* siguiente = actual->sig;
		insertarOrdenado(listaOrdenada, actual->dato);
		actual = siguiente;
	}
	return listaOrdenada;
}


void listaOrdenadaSelectionSort(NodoLista*& l)
{
	NodoLista* i = l;
	while (i) {
		// Busca el nodo mas chico
		NodoLista* min = i;
		NodoLista* j = i->sig;
		while (j) {
			if (j->dato < min->dato) {
				min = j;
			}

			j = j->sig;
		}
		// Si el nodo mas chico tiene es distinto del primero, los cambia.
		if (min != i) {
			int temp = i->dato;
			i->dato = min->dato;
			min->dato = temp;
		}
		i = i->sig;
	}

}

NodoLista* intercalarIter(NodoLista* l1, NodoLista* l2)
{
	NodoLista* resultado = nullptr;
	NodoLista* ultimo = nullptr;
	while (l1 && l2) {
		int valor;
		if (l1->dato < l2->dato) {
			valor = l1->dato;
			l1 = l1->sig;
		}
		else {
			valor = l2->dato;
			l2 = l2->sig;
		}

		NodoLista* nuevo = new NodoLista;
		nuevo->dato = valor;
		nuevo->sig = nullptr;

		// Para que esto funcione y no tener que recorrer la lista, 
		// guardamos la direccion del ultimo puntero, y modificamos a donde apunta.
		if (!resultado) {
			resultado = nuevo;
			ultimo = nuevo;
		}
		else {
			ultimo->sig = nuevo;
			ultimo = nuevo;
		}
	}

	// Agregar los nodos restantes de l1 o l2
	NodoLista* resto = l1 ? l1 : l2;

	while (resto) {
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = resto->dato;
		nuevo->sig = nullptr;


		if (!resultado) {
			resultado = nuevo;
			ultimo = nuevo;
		}
		else {
			ultimo->sig = nuevo;
			ultimo = nuevo;
		}
		resto = resto->sig;
	}

	return resultado;
}

NodoLista* intercalarRec(NodoLista* l1, NodoLista* l2)
{
	if (!l1 && !l2) return nullptr;

	NodoLista* nuevo = nullptr;

	if (!l1) {
		nuevo = new NodoLista;
		nuevo->dato = l2->dato;
		nuevo->sig = intercalarRec(nullptr, l2->sig);
	}
	else if (!l2) {
		nuevo = new NodoLista;
		nuevo->dato = l1->dato;
		nuevo->sig = intercalarRec(l1->sig, nullptr);
	}
	else if (l1->dato < l2->dato) {
		nuevo = new NodoLista;
		nuevo->dato = l1->dato;
		nuevo->sig = intercalarRec(l1->sig, l2);
	}
	else {
		nuevo = new NodoLista;
		nuevo->dato = l2->dato;
		nuevo->sig = intercalarRec(l1, l2 ->sig);
	}

	return nuevo;
}

NodoLista* insComFin(NodoLista* l, int x)
{
	// Agregamos el ultimo elemento
	NodoLista* nueva = nullptr;
	agregarPrincipio(nueva, x);
	
	// Agregar los elementos en orden inverso
	while (l) {
		agregarPrincipio(nueva, l->dato);
		l = l->sig;
	}

	// Agregamos el primer elemento
	agregarPrincipio(nueva, x);



	return nueva;
}

NodoLista* exor(NodoLista* l1, NodoLista* l2)
{
	if (!l1 && !l2) return nullptr;

	NodoLista* nuevo = nullptr;

	if (!l1 && l2->dato != nuevo->dato) {
		nuevo = new NodoLista;
		nuevo->dato = l2->dato;
		nuevo->sig = exor(nullptr, l2->sig);
		return nuevo;
	}
	else if (!l2 && l1->dato != nuevo->dato) {
		nuevo = new NodoLista;
		nuevo->dato = l1->dato;
		nuevo->sig = exor(l1->sig, nullptr);
		return nuevo;
	}
	else if (l1->dato < l2->dato && l1->dato != nuevo->dato) {
		nuevo = new NodoLista;
		nuevo->dato = l1->dato;
		nuevo->sig = exor(l1->sig, l2);
		return nuevo;
	}
	else if (l1->dato > l2->dato && l2->dato != nuevo->dato) {
		nuevo = new NodoLista;
		nuevo->dato = l2->dato;
		nuevo->sig = exor(l1, l2->sig);
		return nuevo;
	}
	else if (l1->dato == l2->dato || l1->dato == nuevo->dato) {
		return exor(l1->sig, l2->sig);
	}

	return nuevo;
}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{
	// IMPLEMENTAR SOLUCION
}

bool palindromo(NodoLista* l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	// IMPLEMENTAR SOLUCION
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	// IMPLEMENTAR SOLUCION
}
