/* ENUNCIADO:

#define cantcolumnas 10
#define cantfilas 25

typedef int Tveccolumnas[cantcolumnas];
typedef Tveccolumnas Tvecfilas[cantfilas];

Dadas las anteriores declaraciones de constantes y tipos y teniendo en cuenta que la estructura almacena numeros enteros entre 1 y 100 y que esta cargada en su totalidad.

 Se pide:
Desarrollar una funcion en lenguaje C que reciba la estructura ya cargada y muestre la cantidad de apariciones de cada numero.

Nota: Se pueden usar las estructuras auxiliares que considere necesarias. En caso de utilizarlas deben declararse.

Codificar el programa principal con las variables necesarias y solamente la invocacion al modulo desarrollado.

*/
#include<stdio.h>
#define cantcolumnas 10
#define cantfilas 25
#define cantnumeros 100

typedef int Tveccolumnas[cantcolumnas];
typedef Tveccolumnas Tvecfilas[cantfilas];

void mostrarApariciones(Tvecfilas matriz) {

	int i,j;
	int sumatorias[cantnumeros+1];

	for(i=0; i<=cantnumeros; i++) {
		sumatorias[i] = 0;
	}

	for(i=0; i<cantfilas; i++) {
		for(j=0; j<cantcolumnas; j++) {
			sumatorias[matriz[i][j]]++;
		}
	}

	for(i=1; i<=cantnumeros; i++) {
		printf("El numero %i aparece %i veces \n", i, sumatorias[i]);
	}
}

void main() {
	Tvecfilas matriz;

	mostrarApariciones(matriz);
}
