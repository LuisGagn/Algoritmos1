#pragma once

class EstadisticaPrueba  
{
public:
	EstadisticaPrueba();
	virtual ~EstadisticaPrueba();

	int getCantidadCorrectas()const;
	int getCantidadIncorrectas()const;
	int getCantidadNoImplementadas()const;
	int getCantidadComentadas()const;

	void resetearResultados();

private:
	int cantCorrectas, cantIncorrectas, cantNoImplementadas, cantComentadas;

};
