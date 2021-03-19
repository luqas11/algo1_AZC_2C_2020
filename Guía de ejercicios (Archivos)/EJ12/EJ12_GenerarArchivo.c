#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	int legajo;
	String nombre;
} TRegistro;

void cargarDatos(FILE *archivo, int legajo, String nombre) {
	TRegistro registro;

	strcpy(registro.nombre, nombre);
	registro.legajo = legajo;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;
	int indice;

	printf("1 - Analisis \n2 - Algebra \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ12_Analisis.dat", "wb");

		cargarDatos(archivo, 1001, "Uno");
		cargarDatos(archivo, 1002, "Dos");
		cargarDatos(archivo, 1010, "Diez");

	} else if (indice == 2) {
		archivo = fopen("EJ12_Algebra.dat", "wb");

		cargarDatos(archivo, 1001, "Uno");
		cargarDatos(archivo, 1002, "Dos");
		cargarDatos(archivo, 1010, "Diez");
		cargarDatos(archivo, 1011, "Once");
		cargarDatos(archivo, 1014, "Catorce");

	} else {
		printf("\nNo se generaron archivos.");
		return;
	}

	fclose(archivo);

	printf("\nArchivo generado.");
}
