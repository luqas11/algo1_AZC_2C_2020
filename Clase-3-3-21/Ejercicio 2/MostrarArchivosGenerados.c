#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct  {
	int dni;
	int socio;
	String nombre;
} TRSocio;
typedef struct  {
	int dni;
	int socio;
	String nombre;
	int sucursal;
} TRSocioNuevo;

void mostrarArchivo(FILE *archivo, int indice) {

	TRSocio registro;
	TRSocioNuevo registroNuevo;

	if (indice == 1 || indice == 3) {

		fread(&registro, sizeof(registro), 1, archivo);
		while(!feof(archivo)) {
			printf("\n%i \n%i \n%s \n", registro.dni, registro.socio, registro.nombre);
			fread(&registro, sizeof(registro), 1, archivo);
		}

	} else if (indice == 2) {

		fread(&registroNuevo, sizeof(registroNuevo), 1, archivo);
		while(!feof(archivo)) {
			printf("\n%i \n%i \n%s \n%i \n", registroNuevo.dni, registroNuevo.socio, registroNuevo.nombre, registroNuevo.sucursal);
			fread(&registroNuevo, sizeof(registroNuevo), 1, archivo);
		}

	}
}

void seleccionarArchivo(int indice) {

	FILE *archivo;

	if (indice == 1) {
		archivo = fopen("socios.dat","rb");
	} else 	if (indice == 2) {
		archivo = fopen("nuevos.dat","rb");
	} else 	if (indice == 3) {
		archivo = fopen("sociosAct.dat","rb");
	} else {
		printf("No hay archivos para mostrar.");
		return;
	}

	mostrarArchivo(archivo, indice);
	fclose(archivo);
}

void main() {
	int indice;

	printf("Mostrar archivo: \n1 - Socios \n2 - Nuevos \n3 - Socios (actualizado) \nn - Salir \n\n");
	scanf("%i", &indice);
	fflush(stdin);
	seleccionarArchivo(indice);
}
