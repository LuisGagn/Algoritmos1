#include "EjerciciosArboles.h"


int altura(NodoAB* raiz) {
	if (raiz == nullptr) return 0;

	int left = altura(raiz->izq);
	int right = altura(raiz->der);

	return max(left, right) + 1;
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (p == nullptr && q == nullptr) return true;
	if (p != nullptr && q == nullptr || p == nullptr && q != nullptr) return false;
	if (p->dato == q->dato) {
		bool izq = sonIguales(p->izq, q->izq);
		bool der = sonIguales(p->der, q->der);
		return izq && der;
	}
	else {
		return false;
	}

	return true;
}


bool auxiliarCaminoSuma(NodoAB* raiz, int sum) {
	if (raiz == NULL) {
		return false;
	}

	// Si es hoja, verificar si la suma coincide
	if (raiz->izq == nullptr && raiz->der == nullptr) {
		return sum == raiz->dato;
	}

	// Restar el valor del nodo actual y verificar recursivamente en hijos
	int sumaRestante = sum - raiz->dato;

	return auxiliarCaminoSuma(raiz->izq, sumaRestante) ||
		auxiliarCaminoSuma(raiz->der, sumaRestante);
}

bool existeCaminoConSuma(NodoAB* raiz, int sum) {


	if (raiz == NULL) {
		return sum == 0;
	}

	else {
		return auxiliarCaminoSuma(raiz, sum);
	}
}


int alturaCamino(NodoAB* raiz, bool& balanceado) {

	if (raiz == nullptr) return 0;

	int left = alturaCamino(raiz->izq, balanceado);
	int right = alturaCamino(raiz->der, balanceado);

	if (abs(left - right) > 1) balanceado = false;

	return 1 + max(left, right);
}

bool esArbolBalanceado(NodoAB* raiz) {
	bool balanceado = true;
	alturaCamino(raiz, balanceado);


	return balanceado;
}



void copioAListaAux(NodoAB* a, NodoLista*& l, int k) {
	if (a == NULL || k < 1) return;

	if (k == 1) {
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = a->dato;
		nuevo->sig = l;
		l = nuevo;
	}
	else {
		copioAListaAux(a->der, l, k - 1);
		copioAListaAux(a->izq, l, k - 1);

	}
}


NodoLista* enNivel(NodoAB* a, int k) {
	NodoLista* l = NULL;
	copioAListaAux(a, l, k);
	return l;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	if (a == nullptr || desde > hasta || hasta == 0) return 0;

	// Si estamos en el rango, contamos el nodo actual
	int contarEste = (desde <= 1 && hasta >= 1) ? 1 : 0;

	// Llamadas recursivas bajando un nivel
	int izq = cantNodosEntreNiveles(a->izq, desde - 1, hasta - 1);
	int der = cantNodosEntreNiveles(a->der, desde - 1, hasta - 1);

	return contarEste + izq + der;	return 0;
}

NodoLista* camino(NodoAB* arbol, int x) {

	if (arbol == nullptr) return NULL;
	NodoLista* lista = new NodoLista;

	if (arbol->dato == x) {
		lista->dato = arbol->dato;
		lista->sig = nullptr;
		return lista;
	}

	lista->dato = arbol->dato;
	lista->sig = nullptr;

	if (arbol->dato < x) {
		lista->sig = camino(arbol->der, x);
		return lista;
	}
	else {
		lista->sig = camino(arbol->izq, x);
		return lista;
	}




	return lista;
}

NodoAB* invertirHastak(NodoAB* a, int k) {
	if (a == NULL || k == 0) return NULL;


	NodoAB* arbol = new NodoAB;
	arbol->dato = a->dato;
	if (k > 0) {

		arbol->der = invertirHastak(a->izq, k - 1);
		arbol->izq = invertirHastak(a->der, k - 1);


	}

	return arbol;
}


void borrarNodoEspecifico(NodoAB*& A, int dato) {
	if (!A) return;
	if (dato < A->dato) {
		borrarNodoEspecifico(A->izq, dato);
	}
	else if (dato > A->dato) {
		borrarNodoEspecifico(A->der, dato);
	}
	else {
		// Lo borra con la funcion ya programada para ello
		borrarNodoRaiz(A);
	}
}

NodoAB* minimo(NodoAB* A) {
	while (A && A->izq) A = A->izq;
	return A;
}


void borrarNodoRaiz(NodoAB*& A) {
	if (A == nullptr) return;

	// Caso 1 Solo una hoja
	if (!A->izq && !A->der) {
		delete A;
		A = nullptr;
		return;
	}

	// Caso 2 Solo un hijo
	if (!A->izq) {
		NodoAB* borrar = A;
		A = A->der;
		delete borrar;
		return;
	}
	else if (!A->der) {
		NodoAB* borrar = A;
		A = A->izq;
		delete borrar;
		return;

		// Caso 3 -> Dos hijos  
	}
	else {

		NodoAB* minNodo = minimo(A->der);
		A->dato = minNodo->dato;
		borrarNodoEspecifico(A->der, minNodo->dato);
		return;
	}


}




bool auxSumaABB(NodoAB* a, NodoAB* nodo, int n) {


	if (nodo == NULL) return false;

	int restante = n - nodo->dato;

	// Buscar como si fuera una lista.
	NodoAB* aux = a;
	while (aux != NULL) {
		if (aux != nodo && aux->dato == restante) {
			return true;
		}
		if (restante < aux->dato) {
			aux = aux->izq;
		}
		else {
			aux = aux->der;
		}
	}

	// Si no llegamos a devolver true, pasamos a usar el nodo der o izquierdo
	return auxSumaABB(a, nodo->izq, n) || auxSumaABB(a, nodo->der, n);
}


bool sumaABB(NodoAB* a, int n) {
	return auxSumaABB(a, a, n);
}

int sucesorAux(NodoAB* a, int n, int min) {
	if (a == NULL) return min;

	int valor = a->dato;



	// Casos
	// 1-> a=Null
	// 2-> a<n
	// 3-> a>n

	if (a->dato <= n) {
		if (valor > n && valor < min) {
			min = valor;
		}
		valor = sucesorAux(a->der, n, min);
	}
	else {
		if (valor > n && valor < min) {
			min = valor;
		}
		valor = sucesorAux(a->izq, n, min);
	}

	return valor;
}


int sucesor(NodoAB* a, int n)
{
	int valor = sucesorAux(a, n, INT32_MAX);

	if (valor == INT32_MAX) return -1;

	return valor;
}

void contarNodosPorNivel(NodoAB* raiz, int*& niveles, int desde, int hasta) {
	if (raiz == nullptr || desde > hasta) return;
	niveles[desde - 1]++;

	// Lo mandamos con el nivel acontar, creamos una funcion nueva por la lista pasada como ref..
	contarNodosPorNivel(raiz->izq, niveles, desde + 1, hasta);
	contarNodosPorNivel(raiz->der, niveles, desde + 1, hasta);
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {

	if (raiz == NULL) return 0;

	int* niveles = new int[nivelHasta]();

	contarNodosPorNivel(raiz, niveles, 1, nivelHasta);


	int maxNodos = 0;
	int nivelMaxNodos = 1;

	for (int i = 0; i < nivelHasta; i++) {
		if (niveles[i] > maxNodos) {
			maxNodos = niveles[i];
			nivelMaxNodos = i + 1;
		}
	}

	delete[] niveles;
	return nivelMaxNodos;


}


void borrarPares(NodoAB*& a) {

	if (a == nullptr) return;

	if (a->dato % 2 == 0) {
		borrarNodoRaiz(a);
		// Se borra el nodo y luego se verifica si era par., si no hay nodos que no borraria.
		borrarPares(a);
	}

	// Si no hago esto falla por que no existe A despues. 
	if (a) {
		borrarPares(a->izq);
		borrarPares(a->der);
	}




}

int alturaAG(NodoAG* raiz) {

	// En un AG cada nodo tiene 2 valores posibles -> Primer Hijo | Siguiente Hermano
	// No todo nodo tiene hijos o hermanos. 
	// Los hermanos, no aumentan la altura pero si sus hijos
	// Entonces en un arbol como el siguiente, 3 y 4 no daran altura.
	/*
		1
	   /
	  2 - 3 - 4
	 /
	5
	*/
	// Sin embargo, si avanzaran, pero claro, si fuera un arbol como el siguiente, la altura seria 4
	// Por lo que deberiamos contar cuantos lleva en cada sub arbol y tomar el max y saltear todo hermano sin hijos.

	/*
		1
	   /
	  2 - 3 - 4
	 /	   \
	5       6
			 \
			  7
	*/





	if (raiz == nullptr) return 0;
	int alturaHijos = 0;

	// Agarro el hijo y bajo lo mas que pueda, una vez llego al fondo recursiona sumando por altura, cuando termina
	// so toene un hermanito lo busca y calcula su altura, si es mas grande que la anterior, la sobre escribe

	// Paso a paso para enternerlo yo de su recursion
	// P1-> Voy a PH (2)
	// P2-> Voy a PH (5) (No tiene hijos, retorna 1)
	// P3-> Voy a 2 1+1 = 2
	// P4-> Voy a SH (3)
	// P5-> Voy a PH (6)
	// P6-> Voy a PH (7) (No tiene hijos, retorna 1)
	// P7-> Voy a 6 y luego a 3 -> 1 + 1 + 1 = 3 
	// P8-> Voy a SH (4) -> )No tiene hijos retorna 1)
	// P9-> Se ocmparan las alturas, max = 3, returns 1+3 = 4
	//

	NodoAG* hijo = raiz->ph;
	while (hijo) {
		alturaHijos = max(alturaHijos, alturaAG(hijo));
		hijo = hijo->sh;
	}

	return 1 + alturaHijos;

}

void sumaAuxNiveles(NodoAG* raiz, int nivel, int& valor) {


	if (raiz == NULL) return;


	if (nivel % 2 == 0) {
		valor += raiz->dato;
	}
	else {
		valor -= raiz->dato;
	}
	// Si tiene un hijo, pasamos al siguiente nivel
	if (raiz->ph) {
		sumaAuxNiveles(raiz->ph, nivel + 1, valor);
	}
	// Si es un hermano, sigue nomas y los suma/resta
	while (raiz->sh) {
		raiz = raiz->sh;
		if (nivel % 2 == 0) {
			valor += raiz->dato;
		}
		else {
			valor -= raiz->dato;
		}

		if (raiz->ph) {
			sumaAuxNiveles(raiz->ph, nivel + 1, valor);
		}
	}


}


int sumaPorNiveles(NodoAG* raiz) {
	if (raiz == NULL) return 0;

	int valor = 0;
	sumaAuxNiveles(raiz, 1, valor);

	return valor;

}




bool esPrefijo(NodoAG* a, NodoLista* l)
{
	if (l == NULL) return true;
	if (a == NULL) return false;

	// Si termina la lista, devuelve true, ponemos la lista antes ya que si encontramos le caso vacio vacio, devuelve false si no.

	bool pref = a->dato == l->dato;


	// Si no es el valor, se fija en sus hermanos
	if (!pref) {
		return esPrefijo(a->sh, l);
	}
	else {
		// Si es alguno, pasa al siguiente en ambos
		return esPrefijo(a->ph, l->sig);
	}

}


NodoLista* caminoAG(NodoAG* arbolGeneral, int dato) {

	if (arbolGeneral == NULL) return NULL;

	// Si encuentra el nodo, lo devuelve
	if (arbolGeneral->dato == dato) {
		NodoLista* nodo = new NodoLista;
		nodo->dato = arbolGeneral->dato;
		nodo->sig = nullptr;
		return nodo;
	}


	NodoLista* lista = caminoAG(arbolGeneral->ph, dato);
	// Si encontro el nodo, es decir, existe lista, devuelve todos los nodos hasta lista.
	if (lista) {
		NodoLista* nodo = new NodoLista;
		nodo->dato = arbolGeneral->dato;
		nodo->sig = lista;
		return nodo;
	}

	return caminoAG(arbolGeneral->sh, dato);
}

void contarNodosNivelAG(NodoAG* a, int*& niveles, int desde, int hasta) {

	if (a == nullptr || desde > hasta) return;
	niveles[desde - 1]++;

	contarNodosNivelAG(a->ph, niveles, desde + 1, hasta);
	contarNodosNivelAG(a->sh, niveles, desde, hasta);







}


int nivelConMasNodosAG(NodoAG* arbolGeneral) {
	if (arbolGeneral == NULL) return 0;
	int cantNiveles = alturaAG(arbolGeneral); //O(n)
	int* niveles = new int[cantNiveles]();


	contarNodosNivelAG(arbolGeneral, niveles, 1, cantNiveles);



	// Busca el nivel con mas nodos y menor indice.
	int maxNodos = 0;
	int nivelMaxNodos = 1;

	for (int i = 0; i < cantNiveles; i++) {
		if (niveles[i] > maxNodos) {
			maxNodos = niveles[i];
			nivelMaxNodos = i + 1;
		}
	}

	delete[] niveles;
	return nivelMaxNodos;
}