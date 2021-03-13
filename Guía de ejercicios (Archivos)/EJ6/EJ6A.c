#include<stdio.h>

typedef struct {
	int local;
	int central;
	int numero;
} TRegistro;

void main() {
	FILE *archivo;
	int local;
	TRegistro registro;

	archivo = fopen("EJ6_TelefonosDesordenados.dat", "rb");

	printf("Ingrese la caracteristica de la localidad: \n");
	scanf("%i", &local);

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo)) {
		if(registro.local == local){
			printf("\n%i-%i-%i", registro.local, registro.central, registro.numero);
		}
		fread(&registro, sizeof(registro), 1, archivo);
	}
	
	fclose(archivo);
}
