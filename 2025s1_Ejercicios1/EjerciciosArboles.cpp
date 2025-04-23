#include "EjerciciosArboles.h"


int altura(NodoAB* raiz){
	if (raiz == nullptr) return 0;

	int left = altura(raiz->izq);
	int right = altura(raiz->der);

	return max(left, right)+1;
}

bool sonIguales(NodoAB* p, NodoAB* q) {
	if (p == nullptr && q == nullptr) return true;
	if (p != nullptr && q == nullptr || p == nullptr && q != nullptr) return false;
	if (p->dato == q->dato) {
		bool izq = sonIguales(p->izq, q->izq);
		bool der = sonIguales(p->der, q->der);
		return izq&&der;
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

bool esArbolBalanceado(NodoAB *raiz) {
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* enNivel(NodoAB *a, int k) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

NodoAB* invertirHastak(NodoAB* a, int k){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void borrarNodoRaiz(NodoAB * & A) {
	// IMPLEMENTAR SOLUCION
}

bool sumaABB(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

int sucesor(NodoAB* a, int n)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int nivelMasNodos(NodoAB* raiz, int nivelHasta) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

void borrarPares(NodoAB* & a){
	// IMPLEMENTAR SOLUCION
}

int alturaAG(NodoAG* raiz)
{
	// IMPLEMENTAR SOLUCION
	return 0;
}

int sumaPorNiveles(NodoAG* raiz){
	// IMPLEMENTAR SOLUCION
	return 0;
}

bool esPrefijo(NodoAG *a, NodoLista *l)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

NodoLista* caminoAG(NodoAG *arbolGeneral, int dato) {
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int nivelConMasNodosAG(NodoAG * arbolGeneral) {
	// IMPLEMENTAR SOLUCION
	return 0;
}
