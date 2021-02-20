#include <stdio.h>
#include <string.h>
#define MAX_NOM 100

typedef char String[MAX_NOM];

typedef struct {
	int DNI;
	String Nombre;
	String Email;
} TRegistro;

void cargarDatos(FILE *archivo) {

	TRegistro registro;

	printf("\nIngrese el DNI del alumno (o cero para finalizar):\n");
	scanf("%i", &registro.DNI);
	fflush(stdin);

	while(registro.DNI != 0)	{

		printf("Ingrese el nombre del alumno:\n");
		fgets (registro.Nombre, MAX_NOM, stdin);
		fflush(stdin);

		printf("Ingrese el email del alumno:\n");
		fgets (registro.Email, MAX_NOM, stdin);
		fflush(stdin);

		fwrite(&registro, sizeof(registro), 1, archivo);

		printf("\nIngrese el DNI del alumno (o cero para finalizar):\n");
		scanf("%i", &registro.DNI);
		fflush(stdin);
	}

}

void seleccionarArchivo(int indice) {

	FILE *archivo;

	if (indice == 1) {
		archivo = fopen("fiuba.dat","wb");

	} else 	if (indice == 2) {
		archivo = fopen("ecuba.dat","wb");

	} else 	if (indice == 3) {
		archivo = fopen("exuba.dat","wb");
	}

	cargarDatos(archivo);
	fclose(archivo);
}

void main() {
	int indice;

	printf("Generar archivo: \n1 - Fiuba \n2 - Ecuba \n3 - Exuba \nn - Salir \n\n");
	scanf("%i", &indice);
	fflush(stdin);

	while(indice == 1 || indice == 2 || indice == 3) {
		seleccionarArchivo(indice);

		printf("Generar archivo: \n1 - Fiuba \n2 - Ecuba \n3 - Exuba \nn - Salir \n\n");
		scanf("%i", &indice);
		fflush(stdin);
	}
}
