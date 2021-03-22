#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int dni;
} TRegistro;

void cargarDatos(FILE *archivo, String nombre, int dni) {
	TRegistro registro;
	strcpy(registro.nombre, nombre);
	registro.dni = dni;
	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;
	int indice;

	printf("1 - Curso1 \n2 - Curso2 \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ13_Curso1.dat", "wb");

		cargarDatos(archivo, "A Uno", 11111111);
		cargarDatos(archivo, "Be Dos", 22222222);
		cargarDatos(archivo, "Ce Tres", 55555555);
		cargarDatos(archivo, "Ge Cuatro", 66666666);
		cargarDatos(archivo, "Hache Cinco", 88888888);
		cargarDatos(archivo, "Ka Seis", 99999999);
	} else if (indice == 2) {
		archivo = fopen("EJ13_Curso2.dat", "wb");

		cargarDatos(archivo, "De Siete", 33333333);
		cargarDatos(archivo, "Efe Ocho", 44444444);
		cargarDatos(archivo, "I Nueve", 77777777);
		cargarDatos(archivo, "Jota Diez", 10101010);
	} else {
		printf("\nNo se generaron archivos");
		return;
	}

	printf("\nArchivo generado.");
	fclose(archivo);
}
