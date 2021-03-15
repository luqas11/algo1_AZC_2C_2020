#include<stdio.h>

#define MAX 35

typedef char String[MAX];
typedef struct {
	int dia;
	int mes;
	int anio;
} TFecha;
typedef struct {
	String nombre;
	char sexo;
	TFecha nacimiento;
	TFecha ingreso;
	int sueldo;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;

	archivo = fopen("EJ9_Empleados.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("%s \n%c \n%i \n%i \n%i \n%i \n%i \n%i \n%i \n\n", registro.nombre, registro.sexo, registro.nacimiento.dia, registro.nacimiento.mes, registro.nacimiento.anio, registro.ingreso.dia, registro.ingreso.mes, registro.ingreso.anio, registro.sueldo);
		fread(&registro, sizeof(registro), 1, archivo);
	}
	fclose(archivo);
}
