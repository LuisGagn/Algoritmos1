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
	int subsecuencias = 0;
	bool wasOne = false;
	bool wasTwo = false;
	int current = 0;
	for (int i = 0; i < largo; i++) {
		int num = vector[i];
		switch (num)
		{
		case 1: 
			current = num;
			wasOne = true;
			wasTwo = false;
			break;
		case 2:
			if (current <= num && wasOne) {
				wasTwo = true;
			}
			else {
				wasOne = false;
			}
			current = num;
			break;
		case 3: 
			if (current == 2 && wasOne && wasTwo) {
				subsecuencias++;
			}
			current = 3;
			wasOne = false;
			wasTwo = false;
			break;
		default:
			break;
		}
		

	}


	return subsecuencias;
}

int maximoNumero(unsigned int n) {
	int max = INT_MIN;
	while (n > 0) {
		int number;
		cin >> number;
		if (number > max) {
			max = number;
		}
		n--;
	}

	return max;
}

void ordenarVecInt(int *vec, int largoVec) {
	
	for (int i = 0; i < largoVec-1; i++) {
		int numI = vec[i];
		int min = i;

		for (int j = i + 1; j < largoVec; j++) {
			int numJ = vec[j];
			if (numJ <= vec[min]) {
				min = j;
			}
		}
		vec[i] = vec[min];
		vec[min] = numI;

	}
}

int* intercalarVector(int* v1, int* v2, int l1, int l2){
	
	if (l1 == 0 && l2 == 0) return nullptr;

	int i = 0;
	int j = 0;
	int k = 0;
	
	int* v3= new int[l1+l2];
	

	while (i < l1 && j<l2 ) {
			if (v1[i] < v2[j]) {
				v3[k] = v1[i];
				i++;
			}
			else if (v1[i] > v2[j]) {
				v3[k] = v2[j];
				j++;
			}
			else {
				v3[k] = v1[i];
				k++;
				v3[k] = v2[j];
				i++;
				j++;
			}
			k++;
		}

	while (i < l1) {
		v3[k] = v1[i];
		k++;
		i++;
	}

	while (j < l2) {
		v3[k] = v2[j];
		j++;
		k++;
	}



	return v3;
	}


	


bool subconjuntoVector(int* v1, int* v2, int l1, int l2)
{
	bool sub = false;
	int count = 0;
	for (int i = 0; i < l1; i++) {
		bool found = false;
		for (int j = 0; j < l2 && !found; j++) {
			if (v1[i] == v2[j]) {
				count++;
				found = true;
			}
		}
	}

	if (count == l1) {
		sub = true;
	}

	return sub;
}

char* invertirCase(char* str)
{
	if (str == nullptr) {
		return NULL;
	}
 /*
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i]<='Z') {
			str[i] = tolower(str[i]);
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			str[i] = toupper(str[i]);
		}
		i++;
	}

	return str;
	*/
	return str;
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
