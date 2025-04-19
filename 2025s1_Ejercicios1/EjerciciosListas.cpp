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


NodoLista* saltarDuplicados(NodoLista* l) {
	// Esta auxiliar nos ayuda a no tener que utilizar numeros duplicados, salteando hasta el proximo numero.
	while (l && l->sig && l->dato == l->sig->dato) {
		l = l->sig;
	}

	return l ? l->sig : nullptr;
}



NodoLista* exor(NodoLista* l1, NodoLista* l2)
{

	
	// RECURSIVO 
	// Acaban ambas liastas
	if (!l1 && !l2) return nullptr;

	// Ignora los duplicados consecuentes directamente
	while (l1 && l1->sig && l1->dato == l1->sig->dato) l1 = l1->sig;
	while (l2 && l2->sig && l2->dato == l2->sig->dato) l2 = l2->sig;

	// Se acaba l1
	if (!l1) {
		int val = l2->dato;
		NodoLista* siguiente = saltarDuplicados(l2);
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = val;
		nuevo->sig = exor(nullptr, siguiente);
		return nuevo;
	}

	// Acaba l2
	if (!l2) {
		int val = l1->dato;
		NodoLista* siguiente = saltarDuplicados(l1);
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = val;
		nuevo->sig = exor(siguiente, nullptr);
		return nuevo;
	}
	// Datos iguales
	if (l1->dato == l2->dato) {
		NodoLista* siguientel1 = saltarDuplicados(l1);
		NodoLista* siguientel2 = saltarDuplicados(l2);
		return exor(siguientel1, siguientel2);

	}

	// Dato menor l1 
	if (l1->dato < l2->dato) {
		int val = l1->dato;
		NodoLista* siguiente = saltarDuplicados(l1);
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = val;
		nuevo->sig = exor(siguiente, l2);
		return nuevo;
	}

	// Dato menor l2
	if (l1->dato > l2->dato) {
		int val = l2->dato;
		NodoLista* siguiente = saltarDuplicados(l2);
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = val;
		nuevo->sig = exor(l1, siguiente);
		return nuevo;
	}
	
	// ITERATIVO POR HACER


}

void eliminarDuplicadosListaOrdenadaDos(NodoLista*& l) 
{

	// Caso comienza duplicados
	while (l&&l->sig && l->dato == l->sig->dato) {
		int val = l->dato;
		while (l && l->dato == val) {
			NodoLista* borrar = l;
			l = l->sig;
			delete borrar;
		}
	}

	if (!l) return;

	// Prev guarda el primero
	NodoLista* prev = l;
	// ACtual gruada el siguiente 
	NodoLista* actual = l->sig;


	while (actual) {

		bool duplicado = false;

		// Si es un duplicado, borra y apunta actual al siguiente puntero.
		while (actual->sig && actual->dato == actual->sig->dato) {
			duplicado = true;
			NodoLista* borrar = actual->sig;
			actual->sig = borrar->sig;
			delete borrar;
		}

		// Si hubo algun duplicado, actual tambien es duplicado.
		// cambiamos el puntero de prev al primer elemento diferente.
		// borramos actual y actualizamos prev.
		// Prev no lo evaluamos ya qu e al inicio eliminamos todos los que comeinzan como duplicados.
		if (duplicado) {
			prev->sig = actual->sig;
			NodoLista* borrar = actual;
			actual = actual->sig;
			delete borrar;
		}
		else {
			prev = actual;
			actual = actual->sig;
		}
	}
}


bool palindromo(NodoLista* l)
{
	bool estado = true;
	NodoLista* aux = new NodoLista;
	NodoLista* og = l;
	while (l) {
		agregarPrincipio(aux, l->dato);
		l = l->sig;
	}

	while (og && estado) {
		if (aux->dato != og->dato) estado = false;
		aux = aux->sig;
		og = og->sig;
	}


	while (aux) {
		NodoLista* borrar = aux;
		aux = aux->sig;
		delete borrar;
	}
	delete aux;

	return estado;
}

void eliminarSecuencia(NodoLista* &l, NodoLista* secuencia) 
{
	if (!l || !secuencia) return;

	// Guardamos el comienzo de la lista
	NodoLista* ant = nullptr;
	NodoLista* inicio = l;


	while (inicio) {
	
		// Iteramos sobre la lista, comenzando por inicio y secuencia
		NodoLista* it1 = inicio;
		NodoLista* it2 = secuencia;

		while (it1 && it2 && it1->dato == it2->dato) {
			it1 = it1->sig;
			it2 = it2->sig;
		}

		// Si it2 llega al final, encontramos la primer secuencia
		if (!it2) {
			// Eliminamos todos los nodos desde que comienza hasta que llega al primer dato que no es parde de la secuencia
			NodoLista* borrar = inicio;
			while (borrar != it1) {
				NodoLista* siguiente = borrar->sig;
				delete borrar;
				borrar = siguiente;
			}

			// si el primer valor de la secuencia era el primero de la lista
			// al borar todo reasignamos l al primer valor que no perrtenece a la seucneia
			if (!ant) {
				l = it1;  
			}
			// Si no era el primer valor, asignamos el puntero del primer valor antes de la secuencia al primer valor despuse de la secuencia
			else {
				ant->sig = it1;
			}

			return; // Solo la primera secuencia
		}

		// Si no encuentra la secuencia, avanza al siguiente comienzo
		// Evita que secuencias como abc en aaabbabc se puerdan,
		ant = inicio;
		inicio = ant->sig;
	}
}

void moverNodo(NodoLista* &lista, unsigned int inicial, unsigned int final)
{
	if (inicial == final || !lista || inicial<1 || final<1) return;

	// Buscar nodo a mover
	NodoLista* prev = nullptr;
	NodoLista* actual = lista;
	int pos = 1;

	while (actual && pos < inicial) {
		if(pos == (inicial-1)){
			prev = actual;
		}
		actual = actual->sig;
		pos++;
	}

	if (!actual && pos!= inicial) return; // Inicial fuera de rango



	if (final == 1) {
			prev->sig = actual->sig;

			actual->sig = lista;
			lista = actual;


		return;
	}
	pos = 1;
	NodoLista* aux = lista;
	NodoLista* test = lista;


	while (aux&& pos <= final) {

		if (pos == final) { // aux 1 test 1 - aux 2 test 1 - aux 3 test 2  

			// Saca el nodo
			if (!prev) {
				lista = actual->sig;
			}
			else {
				prev->sig = actual->sig;
			}
			if (final<inicial) {
			actual->sig = test ->sig;
			test->sig = actual;
			}
			else {
				actual->sig = aux->sig;
				aux->sig = actual;
			}

			return;




		}
		test = aux;
		aux= aux->sig;

		pos++;
	}






}
