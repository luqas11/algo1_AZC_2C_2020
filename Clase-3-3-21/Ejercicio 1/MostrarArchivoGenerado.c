#include <stdio.h>

typedef struct  {
	int anio;
	int mes;
	int dia;
	int producto;
	int cantidad;
	float monto;
} TRegistro;

void mostrarArchivo(FILE *archivo) {

	TRegistro registro;

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		printf("\n%i \n%i \n%i \n%i \n%i \n%.2f\n", registro.anio, registro.mes, registro.dia, registro.producto, registro.cantidad, registro.monto);
		fread(&registro, sizeof(registro), 1, archivo);
	}
}

void main() {
	FILE *archivo;

	archivo = fopen("ventas.dat","rb");
	mostrarArchivo(archivo);
	fclose(archivo);
}
