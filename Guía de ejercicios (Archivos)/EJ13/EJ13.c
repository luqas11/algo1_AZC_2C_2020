#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int dni;
} TRegistro;

void main() {
	FILE *archivo1;
	FILE *archivo2;
	FILE *archivoNuevo;
	TRegistro registro1, registro2;

	archivo1 = fopen("EJ13_Curso1.dat", "rb");
	archivo2 = fopen("EJ13_Curso2.dat", "rb");
	archivoNuevo = fopen("EJ13_CursoNuevo.dat", "wb");

	fread(&registro1, sizeof(registro1), 1, archivo1);
	fread(&registro2, sizeof(registro2), 1, archivo2);
	while(!feof(archivo1)) {

		if(!feof(archivo2) && strcmp(registro1.nombre, registro2.nombre) > 0) {
			fwrite(&registro2, sizeof(registro2), 1, archivoNuevo);
			fread(&registro2, sizeof(registro2), 1, archivo2);
		} else {
			fwrite(&registro1, sizeof(registro1), 1, archivoNuevo);
			fread(&registro1, sizeof(registro1), 1, archivo1);
		}
	}
	while(!feof(archivo2)) {
		fwrite(&registro2, sizeof(registro2), 1, archivoNuevo);
		fread(&registro2, sizeof(registro2), 1, archivo2);
	}
	
	fclose(archivo1);
	fclose(archivo2);
	fclose(archivoNuevo);
}
