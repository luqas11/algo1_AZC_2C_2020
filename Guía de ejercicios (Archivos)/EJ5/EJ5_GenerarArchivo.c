#include<stdio.h>
#include<string.h>

#define MAX 50

typedef char String[MAX];

void cargarDatos(FILE *archivo, String nombre) {
	String nombreCpy;

	strcpy(nombreCpy, nombre);
	fwrite(&nombreCpy, sizeof(nombreCpy), 1, archivo);
}

void main() {
	FILE *archivo;

	archivo = fopen("EJ5_Nombres.dat", "wb");

	cargarDatos(archivo, "Uno");
	cargarDatos(archivo, "Dos");
	cargarDatos(archivo, "Tres");
	cargarDatos(archivo, "Cuatro");
	cargarDatos(archivo, "Cinco");
	cargarDatos(archivo, "Seis");
	cargarDatos(archivo, "Siete");
	cargarDatos(archivo, "Ocho");
	cargarDatos(archivo, "Nueve");
	cargarDatos(archivo, "Diez");


	printf("Archivo generado.");
	fclose(archivo);
}
