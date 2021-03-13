#include<stdio.h>

typedef struct {
	int local;
	int central;
	int numero;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	int indice;

	printf("1 - Desordenados \n2 - Ordenados \nn - Salir \n\n");
	scanf("%i", &indice);

	if (indice == 1) {
		archivo = fopen("EJ6_TelefonosDesordenados.dat", "rb");
	} else if(indice == 2) {
		archivo = fopen("EJ6_TelefonosOrdenados.dat", "rb");
	} else {
		printf("\nNo hay archivos para mostrar.");
		return;
	}

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("\n%i \n%i \n%i \n", registro.local, registro.central, registro.numero);
		fread(&registro, sizeof(registro), 1, archivo);
	}

	fclose(archivo);
}
