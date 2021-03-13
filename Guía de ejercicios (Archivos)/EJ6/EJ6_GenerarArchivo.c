#include<stdio.h>

typedef struct {
	int local;
	int central;
	int numero;
} TRegistro;

void cargarDatos(FILE *archivo, int local, int central, int numero) {
	TRegistro registro;

	registro.local = local;
	registro.central = central;
	registro.numero = numero;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;
	int indice;

	printf("1 - Desordenado \n2 - Ordenado \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ6_TelefonosDesordenados.dat", "wb");

		cargarDatos(archivo, 101, 221, 111111);
		cargarDatos(archivo, 108, 228, 888888);
		cargarDatos(archivo, 104, 244, 444444);
		cargarDatos(archivo, 109, 229, 999999);
		cargarDatos(archivo, 102, 222, 222222);
		cargarDatos(archivo, 104, 245, 545454);
		cargarDatos(archivo, 106, 226, 666666);
		cargarDatos(archivo, 104, 243, 343434);

	} else if(indice == 2) {
		archivo = fopen("EJ6_TelefonosOrdenados.dat", "wb");

		cargarDatos(archivo, 101, 221, 111111);
		cargarDatos(archivo, 102, 222, 222222);
		cargarDatos(archivo, 103, 223, 333333);
		cargarDatos(archivo, 104, 214, 141414);
		cargarDatos(archivo, 104, 224, 242424);
		cargarDatos(archivo, 104, 234, 343434);
		cargarDatos(archivo, 107, 227, 777777);
		cargarDatos(archivo, 108, 228, 888888);

	} else {
		printf("\nNo se generaron archivos.");
		return;
	}

	printf("\nArchivo generado.");
	fclose(archivo);
}
