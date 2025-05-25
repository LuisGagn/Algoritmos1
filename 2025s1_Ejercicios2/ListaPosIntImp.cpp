#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct _representacionListaPosInt {
	int* elementos;
	int cantidad;
	int largo;
};

ListaPosInt crearListaPosInt()
{
	ListaPosInt lista = new _representacionListaPosInt;
	lista->cantidad = 0;
	lista->largo = 10; // Capacidad inicial
	lista->elementos = new int[10];
	return lista;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	// Checkea si la cantidad de plazas disponibles sirve para agregar el elemento. 
	bool insertado = false;
	if (l->largo < l->cantidad + 1) {
		int* nuevo = new int[l->largo*1.5]; 
		// Tras investigar, tenia 5 opciones, por lo siguiente decante por 1.5.
		// -1 Sumar +1, esto causa que si añado 10 elementos, debe recorrer el mismo array 10 veces, siendo siempre el caso promedio O(n)
		// -2 Sumar +10, Si bien es una mejora notable, igual puede mejorarse
		// -3 Multiplicar *2 Esto incrementa vastamente la memoria, el tema que en casos muy amplios por ejemplo 160 si añado un solo elemento, ahora tengo 159 elementos sin usar peor con memoria guardada. 
		// -4 Multiplicar *1.5 Esto al igual que el *2, funciona de igual manera pero en casos como por ejemplo: 131, al añadir un solo elemento nos quedan 64 elementos sin usar, si bien es mejor manejo
		// de la memoria, en cantidades bajas de datos incrementa en poca cantidad, pero en cantidades altas, incrmeenta en mayor cantidad que la suma basica, siendo mejor en el tiempo de ejecucion promedio
		// -5 Elevar ^2 Esto causa un tiempo de ejecucion mas corto en mayor cantidad de datos y casos pero incrementa tan rapido que mucha memoria queda inutil, pasando de 256 a 64k, siendo bastamente infeiciente.

		
		int j = 0;
		for (int i = 0; i < l->cantidad; i++) {
			if (i == pos) {
				nuevo[j] = e;
				j++;
				insertado = true;
			}
			nuevo[j] = l->elementos[i];
			j++;
		}

		if (!insertado) {
			nuevo[l->cantidad] = e;
		}
		l->cantidad += 1;
		l->largo += 1;
		int* borrar = l->elementos;
		l->elementos = nuevo;
		delete[] borrar;
	}
	else {
		
		if (l->cantidad > pos) {
			// puntero guarda siguiente
			// Puntero actual
			// Set and move
			int anterior = l->elementos[pos];
			for (int i = pos; i <= l->cantidad; i++) {
				if (insertado) {
					int aux= anterior;
					anterior = l->elementos[i];
					l->elementos[i] = aux;
				}
				else {
					l->elementos[i] = e;
					insertado = true;
				}
	
			}

		}
		else {
			l->elementos[l->cantidad] = e;
		}
		l->cantidad++;
	}

}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (l->cantidad > pos) {
		for (int i = pos; i < l->cantidad-1; i++) {
			l->elementos[i] = l->elementos[i + 1];
		}
		l->cantidad--;
		if (l->cantidad < l->largo) {
			l->elementos[l->cantidad] = 0;
		}
		}
}

int elemento(ListaPosInt l, unsigned int pos)
{
	//IMPLEMENTAR SOLUCION
	return l->elementos[pos];
}

bool esVacia(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return l->cantidad==0;
}

unsigned int cantidadElementos(ListaPosInt l)
{
	//IMPLEMENTAR SOLUCION
	return l->cantidad;
}

ListaPosInt clon(ListaPosInt l)
{
	ListaPosInt nueva = crearListaPosInt();
	
	for (int i = 0; i < l->cantidad; i++) {
		int dato = l->elementos[i];
		agregar(nueva, dato, i);
	}
	return nueva;
}

void destruir(ListaPosInt& l)
{
	delete[] l->elementos;
	delete l;
}


#endif