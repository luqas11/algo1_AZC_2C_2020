#include <stdio.h>

void main() {
	FILE *archivo;
	int numero, indice;

	printf("1 - Numeros \n2 - Factoriales \nn - Salir\n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ1_numeros.dat", "rb");
	} else if(indice == 2) {
		archivo = fopen("EJ1_factoriales.dat", "rb");
	} else {
		printf("No hay archivos para mostrar.");
		return;
	}

	fread(&numero, sizeof(numero), 1, archivo);

	while(!feof(archivo)) {
		printf("\n%i", numero);
		fread(&numero, sizeof(numero), 1, archivo);
	}

	fclose(archivo);
}
