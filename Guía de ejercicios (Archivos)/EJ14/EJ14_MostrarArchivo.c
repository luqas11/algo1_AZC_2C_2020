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

typedef struct {
	int patente;
	float peso;
} TRegistro2;

void main() {
	FILE *archivo;
	TRegistro registro;
	TRegistro2 registro2;
	int indice;

	printf("1 - Archivo \n2 - ArchivoSalida \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ14_Archivo.dat", "rb");

		fread(&registro, sizeof(registro), 1, archivo);
		while(!feof(archivo)) {
			printf("\n%i, %s, %.2f, %.2f", registro.patente, registro.destino, registro.costo, registro.peso);
			fread(&registro, sizeof(registro), 1, archivo);
		}

	} else if(indice == 2) {
		archivo = fopen("EJ14_ArchivoSalida.dat", "rb");

		fread(&registro2, sizeof(registro2), 1, archivo);
		while(!feof(archivo)) {
			printf("\nCamion %i, %.2fKg", registro2.patente, registro2.peso);
			fread(&registro2, sizeof(registro2), 1, archivo);
		}

	} else {
		printf("\nNo hay archivos para mostrar.");
		return;
	}

	fclose(archivo);
}
