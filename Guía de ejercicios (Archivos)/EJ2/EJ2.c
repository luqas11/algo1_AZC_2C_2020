#include <stdio.h>
#include <stdbool.h>

bool esPrimo(int numero) {
	int i;
	
	for(i = 2; i < numero; i++){
		if(numero % i == 0){
			return false;
		}
	}
	return true;
}

void main() {
	FILE *archivoNumero;
	FILE *archivoPrimos;
	int numero;

	archivoNumero = fopen("EJ2_numeros.dat", "rb");
	archivoPrimos = fopen("EJ2_primos.dat", "wb");

	fread(&numero, sizeof(numero), 1, archivoNumero);
	while(!feof(archivoNumero)) {
		if(esPrimo(numero)) {
			fwrite(&numero, sizeof(numero), 1, archivoPrimos);
		}
		fread(&numero, sizeof(numero), 1, archivoNumero);
	}

	fclose(archivoNumero);
	fclose(archivoPrimos);
}
