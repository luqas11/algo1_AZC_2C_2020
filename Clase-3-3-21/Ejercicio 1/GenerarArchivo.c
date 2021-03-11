#include <stdio.h>

typedef struct  {
	int anio;
	int mes;
	int dia;
	int producto;
	int cantidad;
	float monto;
} TRegistro;

void cargarStruct(FILE *archivo, int anio, int mes, int dia, int producto, int cantidad, float monto) {
	TRegistro registro;
	
	registro.anio = anio;
	registro.mes = mes;
	registro.dia = dia;
	registro.producto = producto;
	registro.cantidad = cantidad;
	registro.monto = monto;
	fwrite(&registro, sizeof(registro), 1, archivo);
}

void cargarDatos(FILE *archivo) {

	cargarStruct(archivo, 2020, 1, 1, 1, 1, 150);
	cargarStruct(archivo, 2020, 1, 1, 8, 1, 280);
	cargarStruct(archivo, 2020, 1, 1, 3, 1, 130);
	cargarStruct(archivo, 2020, 1, 1, 3, 1, 130);
	cargarStruct(archivo, 2020, 1, 2, 2, 1, 120);
	cargarStruct(archivo, 2020, 1, 2, 9, 1, 290);
	cargarStruct(archivo, 2020, 1, 2, 1, 1, 150);
	cargarStruct(archivo, 2020, 1, 2, 8, 1, 220);
	cargarStruct(archivo, 2020, 1, 3, 1, 1, 220);
	cargarStruct(archivo, 2020, 1, 3, 2, 1, 220);
	cargarStruct(archivo, 2020, 1, 3, 1, 1, 220);
	cargarStruct(archivo, 2020, 1, 3, 1, 1, 220);
	cargarStruct(archivo, 2020, 1, 4, 9, 2, 220);
	cargarStruct(archivo, 2020, 1, 4, 8, 20, 30);
	cargarStruct(archivo, 2020, 1, 4, 9, 2, 150);
	cargarStruct(archivo, 2020, 1, 4, 1, 1, 220);
	cargarStruct(archivo, 2020, 2, 1, 1, 1, 150);
	cargarStruct(archivo, 2020, 2, 1, 8, 1, 280);
	cargarStruct(archivo, 2020, 2, 1, 3, 1, 130);
	cargarStruct(archivo, 2020, 2, 1, 3, 1, 130);
	cargarStruct(archivo, 2020, 2, 2, 2, 1, 120);
	cargarStruct(archivo, 2020, 2, 2, 9, 1, 290);
	cargarStruct(archivo, 2020, 3, 2, 1, 1, 150);
	cargarStruct(archivo, 2021, 2, 2, 8, 4, 220);
	cargarStruct(archivo, 2021, 2, 3, 1, 1, 220);
	cargarStruct(archivo, 2021, 2, 3, 2, 1, 220);
	cargarStruct(archivo, 2021, 2, 3, 1, 1, 220);
	cargarStruct(archivo, 2021, 2, 3, 1, 1, 220);
	cargarStruct(archivo, 2021, 2, 4, 9, 3, 220);
	cargarStruct(archivo, 2021, 2, 4, 8, 50, 30);
	cargarStruct(archivo, 2021, 2, 4, 9, 2, 150);
	cargarStruct(archivo, 2022, 2, 4, 1, 1, 220);
}

void main() {

	FILE *archivo;
	printf("Presione enter para generar el archivo...");
	getchar();
	archivo = fopen("ventas.dat","wb");
	cargarDatos(archivo);
	fclose(archivo);
	printf("Archivo generado.");
}
