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

	TFecha fechaActual;
	fechaActual.dia = 15;
	fechaActual.mes = 3;
	fechaActual.anio = 2021;

	archivo = fopen("EJ9_Empleados.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		if(registro.nacimiento.mes == fechaActual.mes){
			printf("%s, $%i\n", registro.nombre, (registro.sueldo/1000) * (fechaActual.anio - registro.ingreso.anio));
		}
		fread(&registro, sizeof(registro), 1, archivo);
	}
	fclose(archivo);
}
