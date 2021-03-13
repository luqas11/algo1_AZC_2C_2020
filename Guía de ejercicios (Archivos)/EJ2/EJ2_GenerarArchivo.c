#include<stdio.h>

void cargarDatos(FILE *archivo, int numero) {
	fwrite(&numero, sizeof(numero), 1, archivo);
}

void main() {

	FILE *archivo;
	
	printf("Presione enter para generar el archivo...");
	getchar();
		
	archivo = fopen("EJ2_numeros.dat", "wb");
	cargarDatos(archivo, 5);
	cargarDatos(archivo, 8);
	cargarDatos(archivo, 125);
	cargarDatos(archivo, 45);
	cargarDatos(archivo, 23);
	cargarDatos(archivo, 33);
	cargarDatos(archivo, 236);
	cargarDatos(archivo, 31);
	
	fclose(archivo);
	printf("Archivo generado.");
}
