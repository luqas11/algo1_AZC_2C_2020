#include<stdio.h>
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
	TRegistro registro;

	archivo = fopen("EJ11_Archivo.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%s \n%i \n%i \n%.2f \n\n", registro.nombre, registro.anio, registro.division, registro.promedio);
		fread(&registro, sizeof(registro), 1, archivo);
	}
	
	fclose(archivo);
	
}
