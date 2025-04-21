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


	int largo = strlen(str);

	char* rep = new char[largo + 1];
	rep[largo] = '\0';

 
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i]<='Z') {
			rep[i] = tolower(str[i]);
		}
		else if(str[i] >= 'a' && str[i] <= 'z'){
			rep[i] = toupper(str[i]);
		}
		else {
			rep[i] = str[i];
		}
		i++;
	}
	

	return rep;
}


// ISLAS
void islasAuxiliar(char** mapa, int col, int fil, int c, int f) {
	mapa[c][f] = 'O';

	// Casos -> -1 -1 / 0 -1 / +1 +1 // -1 0 / +1 0 // -1 +1 / 0 +1 / +1 +1   
	// 1 2 3
	// 4 T 6
	// 7 8 9

	for (int columna = -1; columna <= 1; columna++) {
		for (int fila = -1; fila <=1; fila++) {
			int newCol = c + columna;
			int newFil = f + fila;

			if (newFil==0&&newCol==0) {
				continue;
			}
			if ((newFil < fil && newCol < col) && (newFil >= 0 && newCol >= 0)) {
				if (mapa[newCol][newFil] == 'T') {
					islasAuxiliar(mapa, col, fil, newCol, newFil);
				}
			}
		}
	}
}

void islasNormal(char** mapa, int col, int fil) {
	for (int c = 0; c < col; c++) {
		for (int f = 0; f < fil; f++) {
			if (mapa[c][f] == 'O') {
				mapa[c][f] = 'T';
			}
		}
	}
}
int islas(char** mapa, int col, int fil){
	int cantIslas = 0;

	for (int c = 0; c < col; c++) {
		for (int f = 0; f < fil; f++) {
			if (mapa[c][f] == 'T') {
				islasAuxiliar(mapa, col, fil, c, f);
				cantIslas++;
			}
		}
	}
	islasNormal(mapa, col, fil);

	
	return cantIslas;
}

// ababac
bool contieneString(char *strO, char *substr) {
	int i = 0;
	int j = 0;

	while (strO[i] != '\0') {
		int k = i;
		j = 0;
		while (strO[k] != '\0' && substr[j] != '\0' && strO[k] == substr[j]) {
			k++;
			j++;
		}
		if (substr[j] == '\0') {
			return true;
		}
		i++;
	}

	return false;
}


unsigned int ocurrenciasSubstring(char **vecStr, int largoVecStr, char *substr)
{
	int cant = 0;
	
	for (int str = 0; str < largoVecStr; str++) {

		if (contieneString(vecStr[str], substr)) {
			cant++;
		}

	}
    return cant;
}


// ORDENAR VECTOR DE STRINGS

int largoStr(char* str) {
	int largo = 0;

	while (str[largo] != '\0') {
		largo++;
	}

	return largo;
}


char* copiarString(char* str) {
	int largo = largoStr(str);
	char* newStr = new char[largo + 1];
	newStr[largo] = '\0';

	for (int i = 0; i < largo; i++) {
		newStr[i] = str[i];
	}
	
	return newStr;
}




int compararStrings(char* strA, char* strB) {

	int i = 0;
	while (strA[i] != '\0' && strB[i] != '\0') {

		if (strA[i] == strB[i]) {
			i++;
		} else if(strA[i]<strB[i]){
			return -1;
		}
		else {
			return 1;
		}
	}
	

	if (strA[i] == '\0' && strB[i] == '\0') {
		return 0;
	}

	if(strA[i] == '\0'){
		return -1;
	}
		return 1;


}




char** ordenarVecStrings(char** vecStr, int largoVecStr)
{
	if (vecStr == NULL) {
		return vecStr;
	}
	char** vecStrNew = new char* [largoVecStr];
	for (int i = 0; i < largoVecStr; i++) {
		vecStrNew[i] = copiarString(vecStr[i]);
	}

	int num;


	for (int i = 0; i < largoVecStr; i++) {
		int min = i;

		for (int j = i + 1; j < largoVecStr; j++) {
			num = compararStrings(vecStrNew[j], vecStrNew[min]);
			if (num <0) {
				min = j;
			}

		}
			
		if (min != i) {
			char* temp = vecStrNew[i];
			vecStrNew[i] = vecStrNew[min];
			vecStrNew[min] = temp;
		}
		

	}
	return vecStrNew;
}

int cantSubStr(char* str, char sep) {
	int count = 0;
	bool subStr = false;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != sep) {
			if (!subStr) { 
				count++;
				subStr = true;
			}
		}
		else {
			subStr = false;
		}
	}

	return count;
}

char** splitStr(char* str, char separador, int& largoRet)
{
	int cantSubs = cantSubStr(str, separador);
	largoRet = cantSubs;

	if (str==NULL|| str[0]=='\0' || cantSubs==0) return nullptr;
	

	char** newVecStr = new char* [cantSubs];

	char* strCopia = copiarString(str);

	char delim[2] = { separador,'\0' };

	char* token = strtok(strCopia, delim);

	int sub = 0;


	while (token != nullptr) {
		if (largoStr(token) > 0) {
			newVecStr[sub] = copiarString(token);
			sub++;
		}
		token = strtok(nullptr, delim);
	}

	
	delete[] strCopia;
	return newVecStr;
}




void ordenarVecIntMergeSort(int* vector, int largo) 
{
	if (largo <= 1) return;

	int mitad = largo / 2;

	int* izq = new int[mitad];
	int* der = new int[largo - mitad];

	for (int i = 0; i < mitad; i++) {
		izq[i] = vector[i];
	}
	for (int i = mitad; i < largo; i++) {
		der[i - mitad] = vector[i];
	}

	ordenarVecIntMergeSort(izq, mitad);
	ordenarVecIntMergeSort(der, largo-mitad);

	int* aux = intercalarVector(izq, der, mitad, largo - mitad);

	for (int i = 0; i < largo;i++) {
		vector[i] = aux[i];
	}

	delete[] izq;
	delete[] der;
	delete[] aux;

}
