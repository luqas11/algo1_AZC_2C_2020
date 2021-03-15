#include<stdio.h>
#include<string.h>

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

void cargarDatos(FILE *archivo, String nombre, char sexo, int diaNacimiento, int mesNacimiento, int anioNacimiento, int diaIngreso, int mesIngreso, int anioIngreso, int sueldo) {

	TFecha fechaNacimiento;
	TFecha fechaIngreso;
	TRegistro registro;

	strcpy(registro.nombre, nombre);
	registro.sexo = sexo;
	fechaNacimiento.dia = diaNacimiento;
	fechaNacimiento.mes = mesNacimiento;
	fechaNacimiento.anio = anioNacimiento;
	fechaIngreso.dia = diaIngreso;
	fechaIngreso.mes = mesIngreso;
	fechaIngreso.anio = anioIngreso;
	registro.nacimiento = fechaNacimiento;
	registro.ingreso = fechaIngreso;
	registro.sueldo = sueldo;

	fwrite(&registro, sizeof(registro), 1, archivo);
}

void main() {

	FILE *archivo;

	archivo = fopen("EJ9_Empleados.dat", "wb");

	cargarDatos(archivo, "Uno", 'f', 1, 1, 2001, 2, 2, 2011, 51000);
	cargarDatos(archivo, "Dos", 'm', 2, 2, 2001, 4, 4, 2018, 52000);
	cargarDatos(archivo, "Tres", 'f', 13, 3, 2001, 6, 6, 2013, 53000);
	cargarDatos(archivo, "Cuatro", 'm', 3, 3, 2001, 6, 6, 2016, 53000);
	cargarDatos(archivo, "Cinco", 'f', 24, 4, 2001, 6, 6, 2014, 56000);
	cargarDatos(archivo, "Seis", 'm', 4, 4, 2001, 6, 6, 2015, 57000);

	fclose(archivo);
	printf("Archivo generado.");
}
