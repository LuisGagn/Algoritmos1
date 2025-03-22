#include "PruebasPropias.h"

#ifndef PRUEBASPROPIAS_CPP
#define PRUEBASPROPIAS_CPP

void PruebasPropias() {
	int nroPrueba = 1;
	int correctos = 0, error = 0;
	int correctosTotal = 0, errorTotal = 0, ejCorrectosTotal = 0, ejErrorTotal = 0;

	// Prueba propia de ejemplo. Pueden hacer todas las pruebas que quieran agregar
	// Se recomienda copiar y pegar pruebas existentes y modificarlas
	FrameworkA1::ver(PruebaSuma(-18, -16, -34, nroPrueba), correctos, error);

	FrameworkA1::imprimirResultadoPrueba("PruebasSumaAdicionales", nroPrueba, correctos, error, correctosTotal, errorTotal, ejCorrectosTotal, ejErrorTotal);
}


#endif