#pragma once

// NOTA: Este archivo no debe ser modificado
// NOTA: Si necesitan sus propios struct los definen en el cpp del TAD correspondiente.

#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>

struct NodoListaIntFramework {
	int dato;
	NodoListaIntFramework *sig;
	NodoListaIntFramework() : dato(0), sig(NULL) {}
	NodoListaIntFramework(int d) : dato(d), sig(NULL) {}
};

struct NodoListaStringFramework {
	char* dato;
	NodoListaStringFramework* sig;
	NodoListaStringFramework() : dato(NULL), sig(NULL) {}
};

struct NodoABInt {
	int dato;
	NodoABInt *izq;
	NodoABInt *der;
	NodoABInt() : dato(0), izq(NULL), der(NULL) {}
	NodoABInt(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAGIntFramework {
	int dato;
	NodoAGIntFramework *ph;
	NodoAGIntFramework *sh;
	NodoAGIntFramework() : dato(0), ph(NULL), sh(NULL) {}
	NodoAGIntFramework(int d) : dato(d), ph(NULL), sh(NULL) {}
};

struct NodoListaIntDobleDatoFramework {
	int dato1;
	int dato2;
	NodoListaIntDobleDatoFramework *sig;
	NodoListaIntDobleDatoFramework() : dato1(0), dato2(0), sig(NULL) {}
	NodoListaIntDobleDatoFramework(int d1, int d2) : dato1(d1), dato2(d2), sig(NULL) {}
};

struct NodoABIntDobleDatoFramework {
	int dato1;
	int dato2;
	NodoABIntDobleDatoFramework *izq;
	NodoABIntDobleDatoFramework *der;
	NodoABIntDobleDatoFramework() : dato1(0), dato2(0), izq(NULL), der(NULL) {}
	NodoABIntDobleDatoFramework(int d1, int d2) : dato1(d1), dato2(d2), izq(NULL), der(NULL) {}
};