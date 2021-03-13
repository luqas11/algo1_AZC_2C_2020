#include<stdio.h>
#include<stdbool.h>

typedef struct {
	int local;
	int central;
	int numero;
} TRegistro;

void main() {
	FILE *archivo;
	TRegistro registro;
	int local;
	bool terminado;
	
	archivo = fopen("EJ6_TelefonosOrdenados.dat", "rb");
	printf("Ingrese la caracteristica de la localidad: \n");
	scanf("%i", &local);

	fread(&registro, sizeof(registro), 1, archivo);
	while(!feof(archivo) && terminado == false) {
		
		if(registro.local == local){
			printf("\n%i-%i-%i", registro.local, registro.central, registro.numero);
		}else if(registro.local > local){
			terminado = true;
		}
		fread(&registro, sizeof(registro), 1, archivo);
	}
	
	fclose(archivo);
}
