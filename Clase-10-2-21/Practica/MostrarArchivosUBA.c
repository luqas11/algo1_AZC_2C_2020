#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct {
	int DNI;
	String Nombre;
	String Email;
} TRegistro;

void mostrarDatos(FILE *archivo) {

	TRegistro registro;

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("DNI: %i \n", registro.DNI);
		printf("Nombre: %s", registro.Nombre);
		printf("Email: %s \n", registro.Email);
		fread(&registro, sizeof(registro), 1, archivo);
	}
}

void seleccionarArchivo(int indice) {

	FILE *archivo;

	if (indice == 1) {
		archivo = fopen("fiuba.dat","rb");
	} else 	if (indice == 2) {
		archivo = fopen("ecuba.dat","rb");
	} else 	if (indice == 3) {
		archivo = fopen("exuba.dat","rb");
	} else 	if (indice == 4) {
		archivo = fopen("merge.dat","rb");
	}

	if(archivo == NULL) {
		printf("No se pudo abrir el archivo \n\n");
	} else {
		mostrarDatos(archivo);
		fclose(archivo);
	}
}

void main() {
	int indice;

	printf("Mostrar archivo: \n1 - Fiuba \n2 - Ecuba \n3 - Exuba \n4 - Merge \nn - Salir \n\n");
	scanf("%i", &indice);
	fflush(stdin);

	while(indice == 1 || indice == 2 || indice == 3 || indice == 4) {
		seleccionarArchivo(indice);

		printf("Mostrar archivo: \n1 - Fiuba \n2 - Ecuba \n3 - Exuba \n4 - Merge \nn - Salir \n\n");
		scanf("%i", &indice);
		fflush(stdin);
	}
}
