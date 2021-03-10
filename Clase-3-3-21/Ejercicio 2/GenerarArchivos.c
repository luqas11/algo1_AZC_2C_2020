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

int i = 0;

void cargarStruct(TRSocio *registro, int dni, int socio, String nombre) {
	registro[i].dni = dni;
	registro[i].socio = socio;
	strcpy(registro[i].nombre, nombre);
	i++;
}

void cargarStructNuevo(TRSocioNuevo *registro, int dni, int socio, String nombre, int sucursal) {
	registro[i].dni = dni;
	registro[i].socio = socio;
	strcpy(registro[i].nombre, nombre);
	registro[i].sucursal = sucursal;
	i++;
}

void cargarDatos(FILE *archivo, int indice) {

	TRSocio registro[100];
	TRSocioNuevo registroNuevos[100];
	int j = 0;

	if(indice == 1) {
		cargarStruct(registro, 11111111, 4, "Uno");
		cargarStruct(registro, 22222222, 6, "Dos");
		cargarStruct(registro, 33333333, 2, "Tres");
		cargarStruct(registro, 44444444, 8, "Cuatro");
		cargarStruct(registro, 55555555, 23, "Cinco");
		cargarStruct(registro, 66666666, 9, "Seis");
		cargarStruct(registro, 77777777, 25, "Siete");
		cargarStruct(registro, 88888888, 1, "Ocho");
		cargarStruct(registro, 99999999, 15, "Nueve");
		for(j = 0; j < i; j++) {
			fwrite(&registro[j], sizeof(registro[j]), 1, archivo);
		}

	} else if (indice == 2) {
		cargarStructNuevo(registroNuevos, 12121212, 64, "Doce", 3);
		cargarStructNuevo(registroNuevos, 23232323, 90, "Veintitres", 2);
		cargarStructNuevo(registroNuevos, 44444444, 8, "Cuarenta y cuatro", 3);
		cargarStructNuevo(registroNuevos, 45454545, 43, "Cuarenta y cinco", 4);
		cargarStructNuevo(registroNuevos, 66666666, 9, "Sesenta y seis", 5);
		for(j = 0; j < i; j++) {
			fwrite(&registroNuevos[j], sizeof(registroNuevos[j]), 1, archivo);
		}
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
