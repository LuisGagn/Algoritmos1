#include "ManejadorImpresionPrueba.h"

ManejadorImpresionPrueba* ManejadorImpresionPrueba::instanciaManejador = NULL;

ManejadorImpresionPrueba::ManejadorImpresionPrueba(bool paraParseo)
{
}

ManejadorImpresionPrueba::~ManejadorImpresionPrueba()
{

}

ManejadorImpresionPrueba ManejadorImpresionPrueba::getInstancia()
{
	//if ( instanciaManejador == NULL )
	//	instanciaManejador = new ManejadorImpresionPrueba();

	return ManejadorImpresionPrueba();
}

void ManejadorImpresionPrueba::imprimirResultado(const char* comentario, bool paraParseo) const
{
	if (paraParseo)
	{
		cout << "" << "?";
		cout << "-" << "?";
		cout << "-" << comentario;
		cout << endl;
	}else{
		cout << endl;
		cout << "----------------------------- Testeo --------------------------------" << endl;

		imprimirComentario(comentario);

		//imprimirRetorno(retorno, retornoEsperado);

		cout << "---------------------------------------------------------------------" << endl << endl;
	}
}

void ManejadorImpresionPrueba::imprimirComentario(const char* comentario)const
{
	if ( strcmp(comentario, "") == 0 )
	{
		cout << "\n  Comentario: " << comentario << endl;
		cout << endl;
	}
}

void ManejadorImpresionPrueba::iniciarSeccion(const char* seccion)
{
	cout << "-!-Ini::" << seccion << endl;

	/*
	cout << "\n\n";
	cout << "*********************************************************************\n\n";
	cout << "********************** INICIO "<< seccion << "***********************\n";
	cout << "*********************************************************************\n\n";
	*/
}

void ManejadorImpresionPrueba::cerrarSeccion(const char* seccion)
{
	cout << "-!-Fin::" << seccion << endl;

	/*
	cout << "\n\n";
	cout << "*********************************************************************\n\n";
	cout << "********************** FIN " << seccion << "***********************\n";
	cout << "*********************************************************************\n\n";
	*/
}

void ManejadorImpresionPrueba::imprimirTotalResultados(const EstadisticaPrueba& estadistica, bool paraParseo)const
{
	if (!paraParseo)
	{
		cout << endl;
		cout << "  +------------------------------+" << endl;
		cout << "    RESULTADO DE LOS RETORNOS (NO CHEQUEA SI LAS SALIDAS SON CORRECTAS O NO!)" << endl;
		cout << "    PARA CHEQUEAR SI ES CORRECTO HAY REVISAR TODOS LOS LISTADOS Y VER SI IMPRIME LO QUE DEBERIA" << endl;
		cout << endl;
		//cout << "    Pruebas que retornan correcto:               " << estadistica.getCantidadCorrectas() << endl;
		cout << "    Pruebas que retornan incorrecto:             " << estadistica.getCantidadIncorrectas() << endl;
		cout << "    Pruebas que retornan NO_IMPLEMENTADA:        " << estadistica.getCantidadNoImplementadas() << endl;
		cout << "    Pruebas que retornan COMENTADA:              " << estadistica.getCantidadComentadas() << endl;
		cout << "  +------------------------------+" << endl;
		cout << endl;
	}
}
