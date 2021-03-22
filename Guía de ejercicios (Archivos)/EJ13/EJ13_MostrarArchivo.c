#include<stdio.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int dni;
} TRegistro;

void main() {
	FILE *archivo;
	int indice;
	TRegistro registro;

	printf("1 - Curso1 \n2 - Curso2 \n3 - Nuevo \nn - Salir \n\n");
	scanf("%i", &indice);

	if(indice == 1) {
		archivo = fopen("EJ13_Curso1.dat", "rb");

	} else if (indice == 2) {
		archivo = fopen("EJ13_Curso2.dat", "rb");

	} else if (indice == 3) {
		archivo = fopen("EJ13_CursoNuevo.dat", "rb");

	} else {
		printf("\nNo hay archivos para mostrar");
		return;
	}

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("\n%s, %i", registro.nombre, registro.dni);
		fread(&registro, sizeof(registro), 1, archivo);
	}

	fclose(archivo);
}
