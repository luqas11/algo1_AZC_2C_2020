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

void cargarStruct(FILE *archivo, int dni, int socio, String nombre) {
	TRSocio registro;

	registro.dni = dni;
	registro.socio = socio;
	strcpy(registro.nombre, nombre);
	fwrite(&registro, sizeof(registro), 1, archivo);
}

void cargarStructNuevo(FILE *archivo, int dni, int socio, String nombre, int sucursal) {
	TRSocioNuevo registro;

	registro.dni = dni;
	registro.socio = socio;
	strcpy(registro.nombre, nombre);
	registro.sucursal = sucursal;
	fwrite(&registro, sizeof(registro), 1, archivo);
}

void cargarDatos(FILE *archivo, int indice) {

	if(indice == 1) {
		cargarStruct(archivo, 11111111, 4, "Uno");
		cargarStruct(archivo, 22222222, 6, "Dos");
		cargarStruct(archivo, 33333333, 2, "Tres");
		cargarStruct(archivo, 44444444, 8, "Cuatro");
		cargarStruct(archivo, 55555555, 23, "Cinco");
		cargarStruct(archivo, 66666666, 9, "Seis");
		cargarStruct(archivo, 77777777, 25, "Siete");
		cargarStruct(archivo, 88888888, 1, "Ocho");
		cargarStruct(archivo, 99999999, 15, "Nueve");
		
	} else if (indice == 2) {
		cargarStructNuevo(archivo, 12121212, 64, "Doce", 3);
		cargarStructNuevo(archivo, 23232323, 90, "Veintitres", 2);
		cargarStructNuevo(archivo, 44444444, 8, "Cuarenta y cuatro", 3);
		cargarStructNuevo(archivo, 45454545, 43, "Cuarenta y cinco", 4);
		cargarStructNuevo(archivo, 66666666, 9, "Sesenta y seis", 5);
	}
}

void seleccionarArchivo(int indice) {

	FILE *archivo;

	if (indice == 1) {
		archivo = fopen("socios.dat","wb");
	} else 	if (indice == 2) {
		archivo = fopen("nuevos.dat","wb");
	} else {
		printf("No se generaron archivos.");
		return;
	}

	cargarDatos(archivo, indice);
	fclose(archivo);

	printf("Archivo generado.");

}

void main() {
	int indice;

	printf("Generar archivo: \n1 - Socios \n2 - Nuevos \nn - Salir \n\n");
	scanf("%i", &indice);
	fflush(stdin);
	seleccionarArchivo(indice);
}
