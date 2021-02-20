#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct  {
	String Prov;
	String Ciu ;
	int DNI;
	char test;
} TRegistro;

void mostrarTesteos(FILE *archivo) {

	TRegistro registro;

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%s%s%i \n%c \n\n", registro.Prov, registro.Ciu, registro.DNI, registro.test);
		fread(&registro, sizeof(registro), 1, archivo);
	}
}

void main() {
	FILE *archivo;

	archivo = fopen("listadoTest.dat","rb");
	mostrarTesteos(archivo);
	fclose(archivo);
}
