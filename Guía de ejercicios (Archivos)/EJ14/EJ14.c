#include<stdio.h>
#include<string.h>
#define MAX 30

typedef char String [MAX];

typedef struct {
	int patente;
	String destino;
	float costo;
	float peso;
} TRegistro;

typedef struct {
	int patente;
	float pesoTotal;
} TRegistro2;

void main() {
	FILE *archivo;
	FILE *archivoSalida;
	TRegistro registro;
	TRegistro2 registro2;

	int patenteAnterior, viajesTotales, masViajesCantidad = 0, masViajesPatente, totalCordoba = 0;
	float pesoTotal;

	archivo = fopen("EJ14_Archivo.dat", "rb");
	archivoSalida = fopen("EJ14_ArchivoSalida.dat", "wb");

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		patenteAnterior = registro.patente;
		pesoTotal = 0;
		viajesTotales = 0;
		
		while(!feof(archivo) && registro.patente == patenteAnterior) {
			pesoTotal += registro.peso;
			viajesTotales++;
			if(strcmp(registro.destino, "Cordoba") == 0){
				totalCordoba++;	
			}
			fread(&registro, sizeof(registro), 1, archivo);
		}
		registro2.patente = patenteAnterior;
		registro2.pesoTotal = pesoTotal;
		fwrite(&registro2, sizeof(registro2), 1, archivoSalida);
		if(viajesTotales > masViajesCantidad){
			masViajesCantidad = viajesTotales;
			masViajesPatente = patenteAnterior;			
		}
	}
	printf("Camion %i, %i viajes \n", masViajesPatente, masViajesCantidad);
	printf("%i viajes a Cordoba", totalCordoba);
}
