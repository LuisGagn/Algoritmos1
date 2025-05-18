#pragma once

#include <iostream>
using namespace std;
#include <string.h>
#include "EstadisticaPrueba.h"

class ManejadorImpresionPrueba  
{
public:
	ManejadorImpresionPrueba(bool paraParseo = true);
	virtual ~ManejadorImpresionPrueba();

	void imprimirResultado(const char* comentario, bool paraParseo)const;
	void imprimirTotalResultados(const EstadisticaPrueba& estadistica, bool paraParseo)const;

	void iniciarSeccion(const char* seccion);
	void cerrarSeccion(const char* seccion);

	static ManejadorImpresionPrueba getInstancia();
protected:
	void imprimirComentario(const char* comentario)const;

private:
	static ManejadorImpresionPrueba* instanciaManejador;
};