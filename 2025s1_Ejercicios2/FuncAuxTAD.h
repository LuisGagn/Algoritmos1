// Comentar la siguiente linea si es DLL
#define FRAMEWORKA1DLL_API  

// Descomentar las siguiente linea si es DLL
/*
#ifdef FRAMEWORKA1DLL_EXPORTS
#define FRAMEWORKA1DLL_API __declspec(dllexport) 
#else
#define FRAMEWORKA1DLL_API __declspec(dllimport) 
#endif
*/

#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>
#include <string.h>
#include <cmath>
#include <algorithm>
using namespace std;

#include "Definiciones.h"
#include "ColaArray.h"
#include "ListaOrdInt.h"

#include "ListaPosInt.h"
#include "PilaInt.h"
#include "ColaInt.h"
#include "MultisetInt.h"
#include "SetInt.h"
#include "DiccionarioInt.h"
#include "ColaPrioridadInt.h"
#include "TablaIntInt.h"
#include "TablaIntString.h"



namespace FrameworkA1
{
	/*
	PRE: 
	POS: devuelve una ListaOrdInt a partir de NodoListaS.
		 Los elementos quedan ordenados
	*/
	FRAMEWORKA1DLL_API ListaOrdInt ConvertirAListaOrd(NodoListaIntFramework *l);

	/*
	PRE: 
	POS: devuelve una ListaPosInt a partir de NodoListaS. 
		 Los elementos quedan en las mismas posiciones
	*/
	FRAMEWORKA1DLL_API ListaPosInt ConvertirAListaPos(NodoListaIntFramework *l);

	/*
	PRE: 
	POS: devuelve una PilaInt a partir de NodoListaS. 
		 El ultimo elemento de la lista queda en el tope de la pila.
	*/
	FRAMEWORKA1DLL_API PilaInt ConvertirAPila(NodoListaIntFramework *l);
	
	/*
	PRE: 
	POS: devuelve una ColaInt a partir de NodoListaS. 
		 El primer elemento de la lista queda en el pricipio de la cola.
	*/
	FRAMEWORKA1DLL_API ColaInt ConvertirACola(NodoListaIntFramework *l);

	/*
	PRE: 
	POS: devuelve un MultisetInt a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API MultisetInt ConvertirAMultiSet(NodoListaIntFramework *l);

	/*
	PRE: 
	POS: devuelve un SetInt a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API SetInt ConvertirASet(NodoListaIntFramework *l);

	/*
	PRE: 
	POS: devuelve un DiccionarioInt a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API DiccionarioInt ConvertirADiccionario(NodoListaIntFramework *l);

	/*
	PRE:
	POS: devuelve un TablaIntInt a partir de NodoListaS.
	*/
	FRAMEWORKA1DLL_API TablaIntInt ConvertirATabla(NodoListaIntFramework* d, NodoListaIntFramework* r);

	/*
	PRE:
	POS: devuelve un TablaIntString a partir de NodoListaS.
	*/
	FRAMEWORKA1DLL_API TablaIntString ConvertirATabla(NodoListaIntFramework* d, NodoListaStringFramework* r);

	/*
	PRE: 
	POS: devuelve un ColaPrioridadInt a partir de NodoListaS. 
	*/
	FRAMEWORKA1DLL_API ColaPrioridadInt ConvertirAColaPrioridad(NodoListaIntFramework *e, NodoListaIntFramework *p);

};
