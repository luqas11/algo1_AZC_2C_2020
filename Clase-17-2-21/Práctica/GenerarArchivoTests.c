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

void cargarDatos(FILE *archivo) {

	TRegistro registro;

	printf("Ingrese el DNI de la persona testeada (o cero para finalizar):\n");
	scanf("%i", &registro.DNI);
	fflush(stdin);

	while(registro.DNI != 0)	{

		printf("Ingrese la provincia de la persona testeada:\n");
		fgets(registro.Prov, MAX_NOM, stdin);
		fflush(stdin);

		printf("Ingrese la ciudad de la persona testeada:\n");
		fgets(registro.Ciu, MAX_NOM, stdin);
		fflush(stdin);

		printf("Ingrese el resultado del test:\n");
		scanf("%c", &registro.test);
		fflush(stdin);

		fwrite(&registro, sizeof(registro), 1, archivo);

		printf("\nIngrese el DNI de la persona testeada (o cero para finalizar):\n");
		scanf("%i", &registro.DNI);
		fflush(stdin);
	}

}

void main() {

	FILE *archivo;

	printf("Presione enter para crear un nuevo archivo...\n");
	getchar();
	archivo = fopen("listadoTest.dat","wb");
	cargarDatos(archivo);
	fclose(archivo);

}
