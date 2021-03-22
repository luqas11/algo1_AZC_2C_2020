#include<stdio.h>

typedef struct {
	int mes;
	int dia;
	int cantidad;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	int mesAnterior, diaAnterior, totalMes, cantMasPersonas = 0, diaMasPersonas, mesMasPersonas, totalSemestre1 = 0, totalSemestre2 = 0;

	archivo = fopen("EJ15_Archivo.dat", "rb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		mesAnterior = registro.mes;
		totalMes = 0;

		while(!feof(archivo) && mesAnterior == registro.mes) {
			totalMes += registro.cantidad;
			if(registro.cantidad > cantMasPersonas) {
				diaMasPersonas = registro.dia;
				mesMasPersonas = registro.mes;
				cantMasPersonas = registro.cantidad;
			}
			fread(&registro, sizeof(registro), 1, archivo);
		}
		if(mesAnterior < 7){
			totalSemestre1 += totalMes;
		}else{
			totalSemestre2 += totalMes;
		}
		printf("MES: %i \n", mesAnterior);
		printf("  Total: %i \n", totalMes);
	}
	printf("\nFecha con mas pasajeros: mes %i, dia %i\n", mesMasPersonas, diaMasPersonas);
	if(totalSemestre1 > totalSemestre2){
		printf("En el primer semestre viajaron mas personas (%i)", totalSemestre1);		
	}else{
		printf("En el segundo semestre viajaron mas personas (%i)", totalSemestre2);
	}
	fclose(archivo);
}
