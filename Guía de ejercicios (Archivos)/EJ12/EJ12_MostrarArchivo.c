#include<stdio.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	int legajo;
	String nombre;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	int indice;

	printf("1 - Analisis \n2 - Algebra \nn - Salir \n\n");
	scanf("%i", &indice);
	
	if(indice == 1) {
		archivo = fopen("EJ12_Analisis.dat", "rb");

		fread(&registro, sizeof(registro), 1, archivo);
		while(!feof(archivo)) {
			printf("\n%s %i", registro.nombre, registro.legajo);
			fread(&registro, sizeof(registro), 1, archivo);
		}

	} else if(indice == 2) {
		archivo = fopen("EJ12_Algebra.dat", "rb");

		fread(&registro, sizeof(registro), 1, archivo);
		while(!feof(archivo)) {
			printf("\n%s %i", registro.nombre, registro.legajo);
			fread(&registro, sizeof(registro), 1, archivo);
		}

	} else {
		printf("\nNo se encontraron archivos.");
		return;
	}

	fclose(archivo);
}
