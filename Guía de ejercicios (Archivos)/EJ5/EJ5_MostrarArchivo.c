#include<stdio.h>

#define MAX 50

typedef char String[MAX];

void main() {
	FILE *archivo;
	String nombre;
	int indice;

	printf("1 - Nombres \n2 - NombresOrdenados \nn - Salir\n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ5_Nombres.dat", "rb");
	} else if(indice == 2) {
		archivo = fopen("EJ5_NombresOrdenados.dat", "rb");
	} else {
		printf("No hay archivos para mostrar.");
	}

	fread(&nombre, sizeof(nombre), 1, archivo);
	while(!feof(archivo)) {
		printf("\n%s", nombre);
		fread(&nombre, sizeof(nombre), 1, archivo);
	}

	fclose(archivo);
}
