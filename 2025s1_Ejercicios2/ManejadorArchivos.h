#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <assert.h>
#include <iomanip>
using namespace std;

class ManejadorArchivos {
public:
	ManejadorArchivos(char* rutaL, char* rutaC, char* rutaS);
	~ManejadorArchivos() {}

	//Compara los dos archivos y escribe el resultado en rutaEscritura
	void Comparar(bool mostrarSalidas, bool soloMostrarErrores);

	void GenerarMensaje(const char* mensaje);

private:
	ManejadorArchivos() {
		pCorrectas = pIncorrectas = pNI = pComentadas = fCorrectas = fIncorrectas = 0;
		puntajeObtenido = puntajeTotal = 0;
	};

	string rutaL, rutaC, rutaS;

	int pCorrectas;
	int pIncorrectas;
	int pNI;
	int pComentadas;
	int fCorrectas;
	int fIncorrectas;
	double puntajeObtenido;
	double puntajeTotal;

	bool Prefijo(string linea, string pref) const;
	pair<string, string> ObtenerPalabraReservada(string linea) const;
	void ImprimirInicio(ofstream &salida, string) const;
	void ImprimirFin(ofstream &salida, string) const;
	void ImprimirComparacion(ofstream &salida, int nroPrueba, string obtenido, string esperado, string retO, string retE, string com, double puntaje, bool mostrarSalidas, bool soloMostrarErrores);
	void ImprimirEsperadoVsRecibido(ofstream &salida, string &esp, string &obt) const;
	void ImprimirEstadisticas(ofstream &salida) const;
	bool MismaImpresion(string esp, string obt) const;
	bool esIniSeccion(string & linea) const;
	bool esFinSeccion(string & linea) const;
	bool esFinDePrueba(string & linea) const;
	int obtenerNumeroDePrueba(string & linea) const;
	bool AvanzarHastaProximaPrueba(ifstream &archivo, int &nroPrueba, string &textoRes, string &contenidoFin, bool imprimirIniFin, ofstream &salida) const;
};