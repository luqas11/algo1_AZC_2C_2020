/*
Se tiene el siguiente formato de registro para las ventas de una farmacia
typedef struct  {
   String año;
   String mes;
   int dia;
   int producto;
   int cantidad;
   float monto   }
TRegistro;

año  mes  dia  producto  Cantidad Monto
2020  1     1        1       1     50
2020  1     1        8       2     20
2020  1     1        3       1     30
2020  1     2        1       1     20
2020  1     1        1       1     20

Se listas solo los dias  que se vendieron mas de $500  del producto 8 y 9

Año 2020
Mes 1
Dia 1 500
Dia 2 600
DIa 8 700
Total Mes 1 1800
Total 2020 1800
*/

#include <stdio.h>

typedef struct  {
	int anio;
	int mes;
	int dia;
	int producto;
	int cantidad;
	float monto;
} TRegistro;

void main() {
	FILE *archivoVentas;
	int anioAnt;
	int mesAnt;
	int diaAnt;
	int totalAnio;
	int totalMes;
	int totalDiaVacuna;
	TRegistro regVentas;

	archivoVentas=fopen("ventas.dat", "rb");
	fread(&regVentas, sizeof(TRegistro), 1, archivoVentas);

	while (!feof(archivoVentas)) {
		anioAnt = regVentas.anio;
		totalAnio = 0;
		printf("Anio: %i \n", regVentas.anio);

		while (!feof(archivoVentas) && anioAnt == regVentas.anio) {
			mesAnt = regVentas.mes;
			totalMes = 0;
			printf("  Mes: %i \n", regVentas.mes);

			while (!feof(archivoVentas) && anioAnt == regVentas.anio && mesAnt == regVentas.mes)	{
				totalDiaVacuna = 0;
				diaAnt = regVentas.dia;

				while (!feof(archivoVentas) && anioAnt == regVentas.anio && mesAnt == regVentas.mes && diaAnt == regVentas.dia) {
					if (regVentas.producto == 8 || regVentas.producto == 9) {
						totalDiaVacuna = totalDiaVacuna + regVentas.monto * regVentas.cantidad;
					}
					fread(&regVentas, sizeof(TRegistro), 1, archivoVentas);
				}

				if (totalDiaVacuna > 500) {
					printf("    Dia %i: $%i \n", diaAnt, totalDiaVacuna);
					totalMes += totalDiaVacuna;
				}
			}
			printf("  Total del mes %i: $%i \n", mesAnt, totalMes);
			totalAnio = totalAnio + totalMes;
		}
		printf("Total del anio %i: $%i\n", anioAnt, totalAnio);
	}
	fclose(archivoVentas);
}

