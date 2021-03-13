#include<stdio.h>

void main() {
	FILE *archivo;
	int numero, indice;

	printf("1 - Numeros1 \n2 - Numeros2 \n3 - NumerosMerge \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ4_Numeros1.dat", "rb");
	} else if(indice == 2) {
		archivo = fopen("EJ4_Numeros2.dat", "rb");
	} else if (indice == 3) {
		archivo = fopen("EJ4_NumerosMerge.dat", "rb");
	} else {
		printf("No se generaron archivos.");
		return;
	}

	fread(&numero, sizeof(numero), 1, archivo);
	while(!feof(archivo)) {
		printf("\n%i", numero);
		fread(&numero, sizeof(numero), 1, archivo);
	}
	
	fclose(archivo);
}
