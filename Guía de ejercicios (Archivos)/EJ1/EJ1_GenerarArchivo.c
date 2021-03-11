#include <stdio.h>

void cargarDatos(FILE *archivo, int numero) {
	fwrite(&numero, sizeof(numero), 1, archivo);
}

void main() {
	FILE *archivo;

	printf("Presione enter para generar el archivo...");
	getchar();
	archivo = fopen("EJ1_numeros.dat", "wb");
	cargarDatos(archivo, 5);
	cargarDatos(archivo, 4);
	cargarDatos(archivo, 0);
	cargarDatos(archivo, 3);
	cargarDatos(archivo, 1);
	cargarDatos(archivo, 6);
	fclose(archivo);
	printf("Archivo generado.");
}
