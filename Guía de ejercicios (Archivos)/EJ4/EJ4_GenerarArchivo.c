#include<stdio.h>

void cargarDatos(FILE *archivo, int numero) {
	fwrite(&numero, sizeof(numero), 1, archivo);
}

void main() {
	FILE *archivo;
	int indice;

	printf("1 - Numeros1 \n2 - Numeros2 \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ4_Numeros1.dat", "wb");
		cargarDatos(archivo, 1234);
		cargarDatos(archivo, 2245);
		cargarDatos(archivo, 2645);
		cargarDatos(archivo, 3795);
		cargarDatos(archivo, 5235);
	} else if(indice == 2) {
		archivo = fopen("EJ4_Numeros2.dat", "wb");
		cargarDatos(archivo, 2235);
		cargarDatos(archivo, 4655);
		cargarDatos(archivo, 7565);
		cargarDatos(archivo, 7755);
		cargarDatos(archivo, 9419);
	} else {
		printf("\nNo se generaron archivos.");
		return;
	}

	fclose(archivo);
	printf("\nArchivo generado.");
}
