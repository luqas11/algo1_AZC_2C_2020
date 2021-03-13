#include<stdio.h>
#include<string.h>

#define MAX 50
#define MAX_NOM 100

typedef char String[MAX];

void main() {
	FILE *archivoNombres;
	FILE *archivoOrdenado;

	String listaNombres[MAX_NOM];
	String nombre, nombre2;
	int i, j, k, ML = 0;

	archivoNombres = fopen("EJ5_Nombres.dat", "rb");
	archivoOrdenado = fopen("EJ5_NombresOrdenados.dat", "wb");

	fread(&nombre, sizeof(nombre), 1, archivoNombres);
	while(!feof(archivoNombres)) {
		strcpy(listaNombres[ML], nombre);
		ML++;
		fread(&nombre, sizeof(nombre), 1, archivoNombres);
	}

	for(i = 0; i < ML; i++) {
		for(j = 0; j < ML - i; j++) {

			if (strcmp(listaNombres[j + 1], listaNombres[j]) < 0) {

				strcpy(nombre2, listaNombres[j]);
				strcpy(listaNombres[j], listaNombres[j + 1]);
				strcpy(listaNombres[j + 1], nombre2);
			}
		}
	}

	for(i = 0; i < ML; i++) {
		fwrite(&listaNombres[i], sizeof(listaNombres[i]), 1, archivoOrdenado);
	}

	fclose(archivoNombres);
	fclose(archivoOrdenado);
}
