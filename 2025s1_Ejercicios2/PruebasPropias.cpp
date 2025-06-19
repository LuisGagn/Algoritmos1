#include "PruebasPropias.h"

PruebasPropias::PruebasPropias(ConductorPrueba* conductor)
:Prueba(conductor)
{
}

PruebasPropias::~PruebasPropias()
{
}

// Lista de pruebas propias para cada TAD
void pruebasPropiasColaInt();
void pruebasPropiasListaordInt();
void pruebasPropiasListaPosInt();
void pruebasPropiasPilaInt();
void pruebasPropiasDiccionarioInt();
void pruebasPropiasTablaIntString();
void pruebasPropiasMultisetInt();
void pruebasPropiasColaDePrioridadInt();
void pruebasPropiasEjercicios();

const char* PruebasPropias::getNombre() const
{
	return "PruebasPropias";
}

void PruebasPropias::correrPruebaConcreta()
{
	pruebasPropiasColaInt();
	pruebasPropiasListaordInt();
	pruebasPropiasListaPosInt();
	pruebasPropiasPilaInt();
	pruebasPropiasDiccionarioInt();
	pruebasPropiasTablaIntString();
	pruebasPropiasMultisetInt();
	pruebasPropiasColaDePrioridadInt();
	pruebasPropiasEjercicios();
}

void pruebasPropiasColaInt() {
	// Clon ya se prueba que funciona
	cout << "TESTS COLA INT" << endl;
	cout << "//////////////////" << endl;
	cout << "crearCola, encolar, desencolar, principio, cantelementos y esVacia" << endl;
	ColaInt c = crearColaInt();
	cout << "cantidad de elementos al crear la cola: " << cantidadElementos(c) << endl;
	cout << "Esta vacia: " << esVacia(c) << endl;
	encolar(c, 4);
	cout << "Esta vacia: " << esVacia(c) << endl;
	cout << "Principio de la cola cuando agrego el primer elemento: " << principio(c) << endl;
	encolar(c, 5);
	encolar(c, 2);
	encolar(c, 3);
	encolar(c, -1);
	cout << "Largo de cola: " << cantidadElementos(c) << endl;
	cout << "el primer elemento antes de desencolar es: " << principio(c) << endl;
	desencolar(c);
	cout << "el primer elemento luego de desencolar es: " << principio(c) << endl;
	cout << "la cantidad de elementos luego de desencolar es: " << cantidadElementos(c) << endl;
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
	destruir(c);
}


void pruebasPropiasListaordInt()
{
	cout << "TESTS LISTA ORD INT" << endl;
	cout << "//////////////////" << endl;
	ListaOrdInt l = crearListaOrdInt();
	cout << "Largo de lista Ord: " << cantidadElementos(l) << ":0" << endl;
	cout << "Largo de lista Ord: " << esVacia(l) << ":1" << endl;
	agregar(l, 5);
	agregar(l, 7);
	agregar(l, -1);
	agregar(l, -2);
	agregar(l, 15);
	agregar(l, 4);
	agregar(l, 5);

	cout << "Largo de lista Ord: " << cantidadElementos(l)<<":7" << endl;
	int principio = minimo(l);
	int final = maximo(l);
	cout << "Elemento del principio de lista Ord: " << principio <<":-2" << endl;
	cout << "Elemento del final de lista Ord: " << final <<":15" << endl;

	borrarMinimo(l);
	cout << "Elimino el " << principio << " de la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	cout << "Nuevo principio" << minimo(l)<< ":-1" << endl;

	borrarMaximo(l);
	cout << "Elimino el " << final << " de la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	cout << "Nuevo final" << maximo(l) << ":7" << endl;
	string vacia = esVacia(l) ? " si " : " no ";
	cout << "La lista " << vacia << " es vacia" << endl;
	string existeElemento = existe(l, 32) ? " si " : " no ";
	cout << "La lista " << existeElemento << " contiene el elemento 32" << endl;
	existeElemento = existe(l, 7) ? " si " : " no ";
	cout << "La lista " << existeElemento << " contiene el elemento 7" << endl;


	ListaOrdInt clonL = clon(l);
	cout << "minimo del clon: " << minimo(clonL) << ":" << minimo(l) << endl;
	cout << "maximo del clon: " << maximo(clonL) << ":" << maximo(l) << endl;
	destruir(l);
	destruir(clonL);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

void pruebasPropiasListaPosInt()
{
	cout << "TESTS LISTA POS INT " << endl;
	cout << "//////////////////" << endl;
	ListaPosInt l = crearListaPosInt();
	cout << "Es Vacia" << esVacia(l) << ":1"<<endl;
	cout << "Cant lelementos lsita vacia: " << cantidadElementos(l)<<":0" << endl;
	agregar(l, 5, 0);
	agregar(l, 7, 1);
	agregar(l, -1, 2);
	agregar(l, 5, 21);
	agregar(l, -2, 3);
	agregar(l, 4, 11);
	agregar(l, 15, 10);
	cout << "Es Vacia" << esVacia(l) << ":0" << endl;
	cout << "Largo de lista Pos: " << cantidadElementos(l) << endl;

	ListaPosInt l2 = clon(l);

	borrar(l2, 50); //borro mas alla de la posicion - no deberia tener efecto
	cout << "Largo de lista Pos: " << cantidadElementos(l2) <<":"<<cantidadElementos(l)<< endl;
	while (!esVacia(l2))
	{
		int e = elemento(l2, 0);
		borrar(l2, 0);
		if (!esVacia(l2)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	borrar(l2, 0); //Borro una vez que la lista ya esta vacia, no deberia tener efecto

	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(l2) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(l) << endl;

	borrar(l, 0);
	borrar(l, 1);
	borrar(l, 4);
	borrar(l, 1);
	borrar(l, 50); //Borro mucho mas alla de la ultima posicion

	cout << "Largo de lista Pos luego de borrar 4 elementos: " << cantidadElementos(l) << endl;

	while (!esVacia(l))
	{
		elemento(l, 0);
		borrar(l, 0);
	}

	cout << "Largo de lista Pos luego de vaciarla: " << cantidadElementos(l) << endl;
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
	destruir(l);
	destruir(l2);

}

void pruebasPropiasPilaInt()
{
	cout << "TESTS PILA INT " << endl;
	cout << "//////////////////" << endl;
	PilaInt p = crearPilaInt();

	cout << "cantidad de elementos al crear la pila: " << cantidadElementos(p)<<":0" << endl;
	cout << "Esta vacia: " << esVacia(p)<<":1" << endl;


	push(p, 4);

	cout << "tope de la pila cuando agrego el primer elemento: " << top(p) << endl;


	push(p, 5);
	push(p, 2);
	push(p, 3);
	push(p, -1);

	cout << "Esta vacia: " << esVacia(p) << endl;


	cout << "Largo de pila: " << cantidadElementos(p) << endl;


	cout << "el primer elemento antes del pop es: " << top(p) << endl;

	pop(p);

	cout << "el primer elemento luego del pop es: " << top(p) << endl;
	cout << "la cantidad de elementos luego del pop es: " << cantidadElementos(p) << endl;

	destruir(p);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}


void pruebasPropiasDiccionarioInt() {
	cout << "TESTS DICCIOANRIO INT " << endl;
	cout << "//////////////////" << endl;
	DiccionarioInt d = crearDiccionarioInt(5);
	cout << "Es Vacio " << esVacio(d) << ":1" << endl;
	cout << "Cantidad elem dic vacio " << cantidadElementos(d) << ":0" << endl;
	agregar(d, 5);
	agregar(d, 7);
	agregar(d, -1);
	agregar(d, -5);
	agregar(d, 15);
	agregar(d, 4);


	cout << "Pertenece 5 " << pertenece(d, 5) << ":1" << endl;
	cout << "Pertenece 50 " << pertenece(d, 50) << ":0" << endl;
	cout << "Largo de diccionario: " << cantidadElementos(d) <<":6" << endl;
	agregar(d, 5);
	cout << "Luego de agregar repetidos hay: " << cantidadElementos(d) << ":6" << endl;
	destruir(d);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

void pruebasPropiasTablaIntString() {
	cout << "TESTS TABLA INT STRING" << endl;
	cout << "//////////////////" << endl;
	TablaIntString tabla = crearTablaIntString(5);
	cout << "Es Vacia: " << esVacia(tabla) << ":1" << endl;
	agregar(tabla, 1, "hello");
	agregar(tabla, 2, "car");
	agregar(tabla, 3, "dog");
	agregar(tabla, 4, "cat");
	agregar(tabla, 5, "girl");
	cout << "5 Ahora: " << recuperar(tabla, 5)<<":girl" << endl;
	agregar(tabla, 5, "boy");
	cout << "Cambio el 5: " << recuperar(tabla, 5) << ":boy" << endl;
	agregar(tabla, -5, "boy2");
	cout << "Cambio el 5: " << recuperar(tabla, 5) << ":boy" << endl;
	cout << "Recuperar -5: " << recuperar(tabla, -5) << ":boy2" << endl;
	cout << "Es Vacia tras agregar: " << esVacia(tabla) << ":0" << endl;
	cout << "Largo de la tabla: " << cantidadElementos(tabla) <<":6" << endl;
	cout << "Definido elemento 5: " << estaDefinida(tabla, 5) << ":1" << endl;
	cout << "Definido elemento 50: " << estaDefinida(tabla, 50) << ":0" << endl;
	destruir(tabla);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}


void pruebasPropiasMultisetInt()
{
	cout << "TESTS MULTISET INT " << endl;
	cout << "//////////////////" << endl;
	MultisetInt s = crearMultisetInt();
	cout << "Largo de lista creada: " << cantidadElementos(s)<<":0" << endl;
	cout << "Es Vacia: " << esVacio(s)<<":1" << endl;
	agregar(s, 5, 2);
	agregar(s, 7, 2);
	agregar(s, -1, 1);
	agregar(s, -2, 1);
	agregar(s, 15, 1);
	agregar(s, 4, 1);
	cout << "Es Vacia tras agregar: " << cantidadElementos(s) << ":0" << endl;
	cout << "Largo de lista Pos: " << cantidadElementos(s) << endl;


	
	NodoListaIntFramework* lord = NULL;
	MultisetInt s2 = crearMultisetInt();
	cout << "Contenido vacio en lleno" << contenidoEn(s2, s) << ":1" << endl;
	cout << "Contenido vacio en vacio" << contenidoEn(s2, s2) << ":1" << endl;
	cout << "Contenido lleno en vacio" << contenidoEn(s, s2) << ":0" << endl;
	agregar(s2, 5, 2);
	agregar(s2, 1, 1);
	agregar(s2, 2, 3);
	agregar(s2, 13, 1);
	agregar(s2, 15, 1);
	agregar(s2, 4, 2);
	agregar(s2, 7, 1);


	
	destruir(s);
	destruir(s2);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}


void pruebasPropiasColaDePrioridadInt()
{
	cout << "TESTS COLA PRIORIDAD INT " << endl;
	cout << "//////////////////" << endl;
	ColaPrioridadInt cola = crearColaPrioridadInt(10);
	cout << "Largo de cola creada: " << cantidadElementos(cola) << ":0" << endl;
	cout << "Es Vacia: " << esVacia(cola) << ":1" << endl;
	cout << "Es llena: " << esLlena(cola) << ":0" << endl;
	encolar(cola, 3, 3);
	encolar(cola, 5, 5);
	encolar(cola, 8, 8);
	encolar(cola, 1, 1);
	encolar(cola, 6, 6);
	encolar(cola, 2, 3);
	encolar(cola, 9, 9);
	encolar(cola, -5, 3);
	encolar(cola, 20, 9);

	cout << "La cola de prioridad esta llena? " << (esLlena(cola) ? "SI" : "NO") << endl;

	encolar(cola, 1, -1);

	cout << "La cola de prioridad esta llena? " << (esLlena(cola) ? "SI" : "NO") << endl;

	cout << "Cantidad de elementos de la cola: " << cantidadElementos(cola) << endl;

	ColaPrioridadInt colaClon = clon(cola);
	int e;
	int p;
	cout << "Clon de elementos colaPrioridadInt: ";
	while (!esVacia(colaClon))
	{
		e = principio(colaClon);
		p = principioPrioridad(colaClon);
		desencolar(colaClon);
		if (!esVacia(colaClon)) {
			cout << e << ":" << p << ",";
		}
		else {
			cout << e << ":" << p << endl;
		}
	}

	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(colaClon) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(cola) << endl;

	ColaPrioridadInt colaClonPriori = clon(cola);
	cout << "Clon de prioridades colaPrioridadInt: ";
	while (!esVacia(colaClonPriori))
	{
		e = principio(colaClonPriori);
		p = principioPrioridad(colaClonPriori);
		desencolar(colaClonPriori);
		if (!esVacia(colaClonPriori)) {
			cout << e << ":" << p << ",";
		}
		else {
			cout << e << ":" << p << endl;
		}

	}

	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(colaClonPriori) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(cola) << endl;

	desencolar(cola);
	desencolar(cola);
	desencolar(cola);

	cout << "Cantidad de elementos luego de borrar 3 elementos: " << cantidadElementos(cola) << endl;

	destruir(cola);
	destruir(colaClon);
	destruir(colaClonPriori);
	cout << "END TESTS" << endl;
	cout << "//////////////////" << endl;
	cout << "" << endl;
	cout << "" << endl;
}

void pruebasPropiasEjercicios() {
	// Pruebas Enlistar
	cout << " " << endl;
	cout << " " << endl;
	cout << "PRUEBAS ENLISTAR" << endl;
	pruebaEnlistar("{}");
	pruebaEnlistar("{-1,#,2,#,5}");


	// Pruebas UnionListaOrd
	cout << " " << endl;
	cout << " " << endl;
	cout << "PRUEBAS UNION LISTA ORD" << endl;
	pruebaUnionListaOrd("(2,4,6,8)", "()");
	pruebaUnionListaOrd("()", "()");


	// Pruebas EstaContenida
	cout << " " << endl;
	cout << " " << endl;
	cout << "PRUEBAS ESTA CONTENIDA" << endl;
	pruebaEstaContenida("()", "()");
	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "()");
	pruebaEstaContenida("()", "(7,3,7,2,4,4,4,7,1,4,8)");
	pruebaEstaContenida("(1,2)", "(7,3,7,2,4,4,4,7,1,4,8)");
	pruebaEstaContenida("(1,2,2)", "(7,3,7,2,4,4,4,7,1,4,8)");
}




