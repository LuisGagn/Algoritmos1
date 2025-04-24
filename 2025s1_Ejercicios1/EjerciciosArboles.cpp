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


int alturaCamino(NodoAB* raiz, bool&balanceado) {

	if (raiz == nullptr) return 0;

	int left = alturaCamino(raiz->izq, balanceado);
	int right = alturaCamino(raiz->der, balanceado);

	if (abs(left - right) > 1) balanceado = false;

	return 1 + max(left, right);
}

bool esArbolBalanceado(NodoAB *raiz) {
	bool balanceado = true;
	alturaCamino(raiz, balanceado);
	

	return balanceado;
}


NodoLista* enNivel(NodoAB *a, int k) {

	if (a == nullptr) return NULL;
	

	if (k == 1) {
			NodoLista* listaNivel = new NodoLista;
			listaNivel->dato = a->dato;
			listaNivel->sig = nullptr;
			return listaNivel;

	}

	NodoLista* left = enNivel(a->izq, k - 1);
	NodoLista* der = enNivel(a->der, k - 1);

	if (!left) return der;

	NodoLista* temp = left;

	while (temp->sig) temp = temp->sig;

	temp->sig = der;

	
	return left;
}

int cantNodosEntreNiveles(NodoAB* a, int desde, int hasta) {
	if (a == nullptr || desde > hasta) return 0;

	// Si estamos en el rango, contamos el nodo actual
	int contarEste = (desde <= 1 && hasta >= 1) ? 1 : 0;

	// Llamadas recursivas bajando un nivel
	int izq = cantNodosEntreNiveles(a->izq, desde - 1, hasta - 1);
	int der = cantNodosEntreNiveles(a->der, desde - 1, hasta - 1);

	return contarEste + izq + der;	return 0;
}

NodoLista* camino(NodoAB *arbol, int x) {

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

NodoAB* invertirHastak(NodoAB* a, int k){
	if (a == NULL || k ==0) return NULL;


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
  if(!A->izq && !A->der){
    delete A;
    A=nullptr;
    return;
  }

  // Caso 2 Solo un hijo
  if(!A->izq){
    NodoAB* borrar = A;
    A=A->der;
    delete borrar;
    return;
  } else if(!A->der){
    NodoAB* borrar = A;
    A=A->izq;
    delete borrar;
    return;
  
  // Caso 3 -> Dos hijos  
  } else {
    
    NodoAB* minNodo = minimo(A->der);
    A->dato = minNodo->dato;
	borrarNodoEspecifico(A->der,minNodo->dato);
    return;
  }
  
  
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
