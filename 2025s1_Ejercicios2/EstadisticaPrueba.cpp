#include "EstadisticaPrueba.h"

EstadisticaPrueba::EstadisticaPrueba()
{
	cantCorrectas = cantIncorrectas = cantNoImplementadas = cantComentadas = 0;
}

EstadisticaPrueba::~EstadisticaPrueba()
{
}

int EstadisticaPrueba::getCantidadCorrectas()const
{
	return cantCorrectas;
}

int EstadisticaPrueba::getCantidadIncorrectas()const
{
	return cantIncorrectas;
}

int EstadisticaPrueba::getCantidadNoImplementadas()const
{
	return cantNoImplementadas;
}

int EstadisticaPrueba::getCantidadComentadas()const
{
	return cantComentadas;
}


void EstadisticaPrueba::resetearResultados()
{
	cantCorrectas = cantIncorrectas = cantNoImplementadas = 0;
}
