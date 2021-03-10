#include <stdio.h>

typedef struct  {
	int anio;
	int mes;
	int dia;
	int producto;
	int cantidad;
	float monto;
} TRegistro;

void cargarStruct(TRegistro *registro, int *i, int anio, int mes, int dia, int producto, int cantidad, float monto) {
	registro[*i].anio = anio;
	registro[*i].mes = mes;
	registro[*i].dia = dia;
	registro[*i].producto = producto;
	registro[*i].cantidad = cantidad;
	registro[*i].monto = monto;
	(*i)++;
}

void cargarDatos(FILE *archivo) {

	TRegistro registro[100];
	int j, i = 0;
	cargarStruct(registro, &i, 2020, 1, 1, 1, 1, 150);
	cargarStruct(registro, &i, 2020, 1, 1, 8, 1, 280);
	cargarStruct(registro, &i, 2020, 1, 1, 3, 1, 130);
	cargarStruct(registro, &i, 2020, 1, 1, 3, 1, 130);
	cargarStruct(registro, &i, 2020, 1, 2, 2, 1, 120);
	cargarStruct(registro, &i, 2020, 1, 2, 9, 1, 290);
	cargarStruct(registro, &i, 2020, 1, 2, 1, 1, 150);
	cargarStruct(registro, &i, 2020, 1, 2, 8, 1, 220);
	cargarStruct(registro, &i, 2020, 1, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2020, 1, 3, 2, 1, 220);
	cargarStruct(registro, &i, 2020, 1, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2020, 1, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2020, 1, 4, 9, 2, 220);
	cargarStruct(registro, &i, 2020, 1, 4, 8, 20, 30);
	cargarStruct(registro, &i, 2020, 1, 4, 9, 2, 150);
	cargarStruct(registro, &i, 2020, 1, 4, 1, 1, 220);
	cargarStruct(registro, &i, 2020, 2, 1, 1, 1, 150);
	cargarStruct(registro, &i, 2020, 2, 1, 8, 1, 280);
	cargarStruct(registro, &i, 2020, 2, 1, 3, 1, 130);
	cargarStruct(registro, &i, 2020, 2, 1, 3, 1, 130);
	cargarStruct(registro, &i, 2020, 2, 2, 2, 1, 120);
	cargarStruct(registro, &i, 2020, 2, 2, 9, 1, 290);
	cargarStruct(registro, &i, 2020, 3, 2, 1, 1, 150);
	cargarStruct(registro, &i, 2021, 2, 2, 8, 4, 220);
	cargarStruct(registro, &i, 2021, 2, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2021, 2, 3, 2, 1, 220);
	cargarStruct(registro, &i, 2021, 2, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2021, 2, 3, 1, 1, 220);
	cargarStruct(registro, &i, 2021, 2, 4, 9, 3, 220);
	cargarStruct(registro, &i, 2021, 2, 4, 8, 50, 30);
	cargarStruct(registro, &i, 2021, 2, 4, 9, 2, 150);
	cargarStruct(registro, &i, 2022, 2, 4, 1, 1, 220);

	for(j = 0; j < i; j++) {
		fwrite(&registro[j], sizeof(registro[j]), 1, archivo);
	}
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
