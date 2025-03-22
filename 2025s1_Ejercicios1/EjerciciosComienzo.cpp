#include "EjerciciosComienzo.h"

int suma(int a, int b) {
    return a+b;
}

void tablaDel(unsigned int tablaDel, unsigned int desde, unsigned int hasta) {
 	
	for (desde; desde <= hasta; desde++)
	{
		int res = desde * tablaDel;
		cout << desde << "*" << tablaDel << "=" << res;
		if (desde != hasta) {
			cout << ";";
		}
	};


}

void simplificar(int n, int d) {
	
	bool neg = false;
	if (n != 0) {

		

		if (n < 0) {
			neg = true;
			n = n * -1;
		}
		if (d < 0) {
			neg = !neg;
			d = d * -1;
		}



		int k;
		n < d ? k = n : k = d;
		int max=0;



		for (int i = 1; i <= k; i++) {
			if (n % i == 0 && d%i==0) {
				max = i;
			}
		}

		 n = n / max;
		 d = d / max;
	}
	
		if(neg){
		cout <<"-" << n << "/" << d;
		}
		else {
			cout << n << "/" << d;
		}




}

int ocurrencias123Repetidos(int* vector, int largo) {
	// IMPLEMENTAR SOLUCION
	return 0;
}

int maximoNumero(unsigned int n) {
	// IMPLEMENTAR SOLUCION
    return 0;
}

void ordenarVecInt(int *vec, int largoVec) {
	// IMPLEMENTAR SOLUCION
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	// IMPLEMENTAR SOLUCION
	return NULL;
}

bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	// IMPLEMENTAR SOLUCION
	return false;
}

char* invertirCase(char* str)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

int islas(char** mapa, int col, int fil){
	// IMPLEMENTAR SOLUCION
    return 0;
}

unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	// IMPLEMENTAR SOLUCION
    return 0;
}

char **ordenarVecStrings(char **vecStr, int largoVecStr)
{
	// IMPLEMENTAR SOLUCION
    return NULL;
}

char** splitStr(char* str, char separador, int &largoRet)
{
	// IMPLEMENTAR SOLUCION
	return NULL;
}

void ordenarVecIntMergeSort(int* vector, int largo) 
{
	// IMPLEMENTAR SOLUCION
}
