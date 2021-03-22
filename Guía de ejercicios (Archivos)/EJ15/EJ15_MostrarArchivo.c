#include<stdio.h>

typedef struct {
	int mes;
	int dia;
	int cantidad;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	
	archivo = fopen("EJ15_Archivo.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%i %i %i \n", registro.mes, registro.dia, registro.cantidad);
		fread(&registro, sizeof(registro), 1, archivo);
	}
	
	fclose(archivo);
}
