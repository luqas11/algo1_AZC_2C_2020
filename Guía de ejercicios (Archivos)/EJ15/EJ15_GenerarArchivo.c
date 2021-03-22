#include<stdio.h>

typedef struct {
	int mes;
	int dia;
	int cantidad;
} TRegistro;

void cargarDatos(FILE *archivo, int mes, int dia, int cantidad) {
	TRegistro registro;

	registro.mes = mes;
	registro.dia = dia;
	registro.cantidad = cantidad;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;

	archivo = fopen("EJ15_Archivo.dat", "wb");

	cargarDatos(archivo, 1, 1 ,34);
	cargarDatos(archivo, 1, 2 ,63);
	cargarDatos(archivo, 1, 3 ,34);
	cargarDatos(archivo, 1, 4 ,43);
	cargarDatos(archivo, 1, 5 ,32);
	cargarDatos(archivo, 2, 1 ,33);
	cargarDatos(archivo, 2, 2 ,73);
	cargarDatos(archivo, 2, 3 ,35);
	cargarDatos(archivo, 2, 4 ,13);
	cargarDatos(archivo, 3, 1 ,33);
	cargarDatos(archivo, 3, 5 ,83);
	cargarDatos(archivo, 4, 2 ,33);
	cargarDatos(archivo, 5, 2 ,53);
	cargarDatos(archivo, 5, 3 ,39);
	cargarDatos(archivo, 5, 4 ,23);
	cargarDatos(archivo, 6, 1 ,33);
	cargarDatos(archivo, 7, 5 ,83);
	cargarDatos(archivo, 8, 2 ,33);
	cargarDatos(archivo, 9, 2 ,53);
	cargarDatos(archivo, 9, 3 ,39);
	cargarDatos(archivo, 9, 4 ,23);

	printf("Archivo generado.");
	fclose(archivo);
}
