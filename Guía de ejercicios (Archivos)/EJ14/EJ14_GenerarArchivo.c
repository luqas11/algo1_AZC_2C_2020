#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String [MAX];

typedef struct {
	int patente;
	String destino;
	float costo;
	float peso;
} TRegistro;

void cargarDatos(FILE *archivo, int patente, String destino, float costo, float peso) {
	TRegistro registro;

	registro.patente = patente;
	strcpy(registro.destino, destino);
	registro.costo = costo;
	registro.peso = peso;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {
	FILE *archivo;

	archivo = fopen("EJ14_Archivo.dat", "wb");

	cargarDatos(archivo, 111, "Jujuy"   , 123.55, 243.70);
	cargarDatos(archivo, 111, "Salta"   , 423.50, 156.95);
	cargarDatos(archivo, 111, "Mendoza" , 723.70, 123.75);
	cargarDatos(archivo, 122, "Salta"   , 173.00, 134.00);
	cargarDatos(archivo, 122, "La Rioja", 121.50, 625.55);
	cargarDatos(archivo, 122, "Cordoba" , 623.00, 425.75);
	cargarDatos(archivo, 122, "Chaco"   , 123.55, 933.70);
	cargarDatos(archivo, 133, "Jujuy"   , 423.50, 136.95);
	cargarDatos(archivo, 144, "Misiones", 723.70, 193.75);
	cargarDatos(archivo, 144, "Cordoba" , 163.00, 134.00);
	cargarDatos(archivo, 155, "La Pampa", 921.50, 225.55);
	cargarDatos(archivo, 166, "Cordoba" , 423.00, 425.75);
	cargarDatos(archivo, 166, "Cordoba" , 223.55, 233.70);
	cargarDatos(archivo, 166, "Chubut"  , 427.50, 186.95);
	cargarDatos(archivo, 166, "Misiones", 923.70, 223.75);
	cargarDatos(archivo, 166, "Cordoba" , 133.00, 134.00);
	cargarDatos(archivo, 177, "Mendoza" , 821.50, 825.55);
	cargarDatos(archivo, 188, "Cordoba" , 693.00, 425.75);

	printf("Archivo generado.");
	fclose(archivo);
}
