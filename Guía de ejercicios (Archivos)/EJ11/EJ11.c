#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String[MAX];

typedef struct {
	String nombre;
	int anio;
	int division;
	float promedio;
} TRegistro;

void main() {
	FILE *archivo;
	FILE *archivoSalida;

	TRegistro registro;
	int anioAnterior, divisionAnterior, alumnosDivision;
	float mejorPromedio = 0;
	String nombreMejorPromedio;

	archivo = fopen("EJ11_Archivo.dat", "rb");
	archivoSalida = fopen("EJ11_ArchivoSalida.txt", "w");

	fprintf(archivoSalida, "Cantidad de alumnos:\n");
	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("Anio %i \n", registro.anio);
		anioAnterior = registro.anio;

		while(!feof(archivo) && registro.anio == anioAnterior) {
			alumnosDivision = 0;
			printf("  Division %i \n", registro.division);
			divisionAnterior = registro.division;

			while(!feof(archivo) && registro.anio == anioAnterior && registro.division == divisionAnterior) {
				printf("    %s, %.2f \n", registro.nombre, registro.promedio);
				if(registro.promedio > mejorPromedio) {
					mejorPromedio = registro.promedio;
					strcpy(nombreMejorPromedio, registro.nombre);
				}
				alumnosDivision++;
				fread(&registro, sizeof(registro), 1, archivo);
			}
			fprintf(archivoSalida, "Anio %i, division %i: %i \n", anioAnterior, divisionAnterior, alumnosDivision);
		}
	}
	printf("Mejor promedio: %s, %.2f", nombreMejorPromedio, mejorPromedio);

	fclose(archivo);
	fclose(archivoSalida);
}
