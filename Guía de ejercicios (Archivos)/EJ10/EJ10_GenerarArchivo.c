#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int categoria;
	int sueldo;
} TRegistro;

void cargarDatos(FILE *archivo, String nombre, int categoria, int sueldo) {
	TRegistro registro;

	strcpy(registro.nombre, nombre);
	registro.categoria = categoria;
	registro.sueldo = sueldo;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;

	archivo = fopen("EJ10_Personal.dat", "wb");

	cargarDatos(archivo, "Uno", 10, 51300);
	cargarDatos(archivo, "Dos", 11, 56400);
	cargarDatos(archivo, "Tres", 11, 56600);
	cargarDatos(archivo, "Cuatro", 11, 56800);
	cargarDatos(archivo, "Cinco", 12, 54000);
	cargarDatos(archivo, "Seis", 12, 56300);
	cargarDatos(archivo, "Siete", 12, 56800);
	cargarDatos(archivo, "Ocho", 13, 56100);
	cargarDatos(archivo, "Nueve", 13, 57000);

	fclose(archivo);
	printf("Archivo generado.");
}
