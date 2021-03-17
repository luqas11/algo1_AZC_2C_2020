#include<stdio.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int categoria;
	int sueldo;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;

	archivo = fopen("EJ10_Personal.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%s \n%i \n%i \n\n", registro.nombre, registro.categoria, registro.sueldo);
		fread(&registro, sizeof(registro), 1, archivo);
	}
	
	fclose(archivo);
}
