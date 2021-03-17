#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int anio;
	int division;
	float promedio;
} TRegistro;

void cargarDatos(FILE *archivo, String nombre, int anio, int division, float promedio) {
	TRegistro registro;

	strcpy(registro.nombre, nombre);
	registro.anio = anio;
	registro.division = division;
	registro.promedio = promedio;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;

	archivo = fopen("EJ11_Archivo.dat", "wb");

	cargarDatos(archivo, "Uno", 1, 1, 7.3);
	cargarDatos(archivo, "Dos", 1, 2, 5.55);
	cargarDatos(archivo, "Tres", 2, 4, 9.5);
	cargarDatos(archivo, "Cuatro", 3, 1, 5.2);
	cargarDatos(archivo, "Cinco", 3, 1, 6.25);
	cargarDatos(archivo, "Seis", 3, 1, 8.2);
	cargarDatos(archivo, "Siete", 3, 2, 5.2);
	cargarDatos(archivo, "Ocho", 3, 4, 8.45);
	cargarDatos(archivo, "Nueve", 5, 6, 4.1);
	cargarDatos(archivo, "Diez", 5, 6, 8.75);

	fclose(archivo);
	printf("Archivo generado.");
}
